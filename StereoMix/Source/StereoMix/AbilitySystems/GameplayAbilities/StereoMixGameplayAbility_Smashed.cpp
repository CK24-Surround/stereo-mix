// Fill out your copyright notice in the Description page of Project Settings.


#include "StereoMixGameplayAbility_Smashed.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "Characters/StereoMixPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utilities/StereoMixeLog.h"
#include "Utilities/StereoMixTag.h"

UStereoMixGameplayAbility_Smashed::UStereoMixGameplayAbility_Smashed()
{
	FAbilityTriggerData TriggerTag;
	TriggerTag.TriggerTag = StereoMixTag::Event::Character::Smashed;
	TriggerTag.TriggerSource = EGameplayAbilityTriggerSource::GameplayEvent;
	AbilityTriggers.Add(TriggerTag);

	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateYes;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::ServerInitiated;
}

void UStereoMixGameplayAbility_Smashed::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!ensure(ActorInfo))
	{
		return;
	}

	AStereoMixPlayerCharacter* AvatarCharacter = Cast<AStereoMixPlayerCharacter>(ActorInfo->AvatarActor.Get());
	if (!AvatarCharacter)
	{
		return;
	}

	AStereoMixPlayerCharacter* CatchCasterCharacter = Cast<AStereoMixPlayerCharacter>(TriggerEventData->Instigator);
	if (!CatchCasterCharacter)
	{
		return;
	}

	UAbilitySystemComponent* CatchCasterASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(CatchCasterCharacter);
	if (!CatchCasterASC)
	{
		return;
	}

	NET_LOG(ActorInfo->AvatarActor.Get(), Log, TEXT("풀기(디태치) 시전"));
	AvatarCharacter->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	AvatarCharacter->GetCharacterMovement()->bIgnoreClientMovementErrorChecksAndCorrection = false;
	
	if (RemoveCaughtStateGE)
	{
		BP_ApplyGameplayEffectToOwner(RemoveCaughtStateGE);
	}

	if (RemoveCatchStateGE)
	{
		const FGameplayEffectContextHandle GEContextHandle = CatchCasterASC->MakeEffectContext();
		if (GEContextHandle.IsValid())
		{
			CatchCasterASC->BP_ApplyGameplayEffectToSelf(RemoveCatchStateGE, 1.0f, GEContextHandle);
		}
	}

	UAbilityTask_PlayMontageAndWait* AbilityTaskPlayMontageAndWait = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, TEXT("SmashedMontage"), SmashedMontage);
	if (AbilityTaskPlayMontageAndWait)
	{
		AbilityTaskPlayMontageAndWait->OnCompleted.AddDynamic(this, &UStereoMixGameplayAbility_Smashed::OnCompleted);
		AbilityTaskPlayMontageAndWait->ReadyForActivation();
	}
}

void UStereoMixGameplayAbility_Smashed::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UStereoMixGameplayAbility_Smashed::OnCompleted()
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
