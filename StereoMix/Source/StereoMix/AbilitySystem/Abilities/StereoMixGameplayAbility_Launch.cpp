// Fill out your copyright notice in the Description page of Project Settings.


#include "StereoMixGameplayAbility_Launch.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/StereoMixAbilitySystemComponent.h"
#include "AbilityTasks/StereoMixAbilityTask_SpawnAndLaunchProjectile.h"
#include "Characters/StereoMixPlayerCharacter.h"
#include "Utilities/StereoMixeLog.h"

UStereoMixGameplayAbility_Launch::UStereoMixGameplayAbility_Launch()
{
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateYes;
}

void UStereoMixGameplayAbility_Launch::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AStereoMixPlayerCharacter* SourceCharacter = GetStereoMixPlayerCharacterFromActorInfo();
	if (ensure(SourceCharacter))
	{
		// 마우스 커서 정보는 클라이언트에만 존재합니다.
		// 따라서 클라이언트의 커서정보를 기반으로 서버에 투사체 생성 요청을 하기 위해 해당 로직은 클라이언트에서만 실행되어야합니다.
		if (!ActorInfo->IsNetAuthority())
		{
			const FVector StartLocation = SourceCharacter->GetActorLocation();
			const FVector TargetLocation = SourceCharacter->GetCursorTargetingPoint();
			ServerRPCRequestProjectile(StartLocation, TargetLocation);
		}

		CommitAbility(Handle, ActorInfo, ActivationInfo);

		UStereoMixAbilitySystemComponent* SourceASC = GetStereoMixAbilitySystemComponentFromActorInfo();
		if (ensure(SourceASC))
		{
			SourceASC->PlayMontage(this, ActivationInfo, Montage, 1.0f);
		}
	}

	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UStereoMixGameplayAbility_Launch::ServerRPCRequestProjectile_Implementation(const FVector_NetQuantize10& StartLocation, const FVector_NetQuantize10& CursorLocation)
{
	const FVector Direction = (CursorLocation - StartLocation).GetSafeNormal();
	const FRotator StartRotation = FRotationMatrix::MakeFromX(Direction).Rotator();
	UStereoMixAbilityTask_SpawnAndLaunchProjectile* ProjectileTask = UStereoMixAbilityTask_SpawnAndLaunchProjectile::CreateTask(this, ProjectileClass, StartLocation, StartRotation);
	if (ProjectileTask)
	{
		ProjectileTask->ReadyForActivation();
	}

	// 대부분의 경우 캐릭터의 위치와 조준한 위치가 평면상에 존재하지만 알 수 없는 오류로 인해 틀어질 수 있습니다. 이 경우를 확인하기 위한 로그입니다.
	if (StartLocation.Z != CursorLocation.Z)
	{
		NET_LOG(GetAvatarActorFromActorInfo(), Warning,
				TEXT("캐릭터의 위치와 커서의 위치가 평면상에 놓이지 않았습니다. 투사체가 캐릭터와 평행하게 발사되지 않습니다. 투사체 시작점: %s 목표 위치: %s"),
				*StartLocation.ToString(), *CursorLocation.ToString());
	}
}
