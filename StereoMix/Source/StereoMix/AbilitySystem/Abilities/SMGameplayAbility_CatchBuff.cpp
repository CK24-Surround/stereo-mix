// Copyright Surround, Inc. All Rights Reserved.


#include "SMGameplayAbility_CatchBuff.h"

#include "Abilities/Tasks/AbilityTask_WaitDelay.h"
#include "AbilitySystem/SMAbilitySystemComponent.h"
#include "AbilitySystem/SMTags.h"
#include "AbilitySystem/AttributeSets/SMCharacterAttributeSet.h"
#include "Characters/SMPlayerCharacter.h"
#include "Components/SMCatchInteractionComponent_Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Utilities/SMLog.h"

USMGameplayAbility_CatchBuff::USMGameplayAbility_CatchBuff()
{
	AbilityTags.AddTag(SMTags::Ability::CatchBuff);
}

void USMGameplayAbility_CatchBuff::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ASMPlayerCharacter* SourceCharacter = GetSMPlayerCharacterFromActorInfo();
	if (!ensureAlways(SourceCharacter))
	{
		EndAbilityByCancel();
		return;
	}

	USMAbilitySystemComponent* SourceASC = GetSMAbilitySystemComponentFromActorInfo();
	if (!ensureAlways(SourceASC))
	{
		EndAbilityByCancel();
		return;
	}

	USMCatchInteractionComponent_Character* SourceCIC = Cast<USMCatchInteractionComponent_Character>(SourceCharacter->GetCatchInteractionComponent());
	if (!ensureAlways(SourceCIC))
	{
		EndAbilityByCancel();
		return;
	}

	UCharacterMovementComponent* SourceMovement = SourceCharacter->GetCharacterMovement();
	if (!ensureAlways(SourceMovement))
	{
		EndAbilityByCancel();
		return;
	}

	const USMCharacterAttributeSet* SourceAttributeSet = SourceASC->GetSet<USMCharacterAttributeSet>();
	if (!ensureAlways(SourceAttributeSet))
	{
		EndAbilityByCancel();
		return;
	}

	// 더해줘야할 이동속도를 구합니다.
	const float MoveSpeedToAdd = (SourceAttributeSet->GetBaseMoveSpeed() * MoveSpeedMultiply) - SourceAttributeSet->GetBaseMoveSpeed();

	// 클라이언트의 경우 예측 실행합니다.
	if (ActorInfo->IsLocallyControlled())
	{
		SourceMovement->MaxWalkSpeed += MoveSpeedToAdd;

		// 버프의 해제도 예측으로 종료되어야하기 때문에 로컬만 바인드합니다. 
		SourceCIC->OnCatchRelease.AddUObject(this, &ThisClass::K2_EndAbility);
	}

	// 서버의 경우 실제로 반영합니다.
	if (ActorInfo->IsNetAuthority())
	{
		SourceCharacter->SetMaxWalkSpeed(SourceMovement->MaxWalkSpeed + MoveSpeedToAdd);
	}
}

void USMGameplayAbility_CatchBuff::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	USMAbilitySystemComponent* SourceASC = GetSMAbilitySystemComponentFromActorInfo();
	if (!ensureAlways(SourceASC))
	{
		EndAbilityByCancel();
		return;
	}

	ASMPlayerCharacter* SourceCharacter = GetSMPlayerCharacterFromActorInfo();
	if (!ensureAlways(SourceCharacter))
	{
		EndAbilityByCancel();
		return;
	}

	UCharacterMovementComponent* SourceMovement = SourceCharacter->GetCharacterMovement();
	if (!ensureAlways(SourceMovement))
	{
		EndAbilityByCancel();
		return;
	}

	const USMCharacterAttributeSet* SourceAttributeSet = SourceASC->GetSet<USMCharacterAttributeSet>();
	if (!ensureAlways(SourceAttributeSet))
	{
		EndAbilityByCancel();
		return;
	}

	// 감소시켜줘야할 이동속도를 구합니다.
	const float MoveSpeedToAdd = (SourceAttributeSet->GetBaseMoveSpeed() * MoveSpeedMultiply) - SourceAttributeSet->GetBaseMoveSpeed();

	// 클라이언트의 경우 예측 실행합니다.
	if (CurrentActorInfo->IsLocallyControlled())
	{
		SourceMovement->MaxWalkSpeed -= MoveSpeedToAdd;
	}

	// 서버의 경우 실제로 반영합니다. 그리고 면역 태그도 제거해줍니다.
	if (CurrentActorInfo->IsNetAuthority())
	{
		SourceCharacter->SetMaxWalkSpeed(SourceMovement->MaxWalkSpeed - MoveSpeedToAdd);
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}