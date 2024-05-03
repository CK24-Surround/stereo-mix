// Copyright Surround, Inc. All Rights Reserved.


#include "SMGameplayAbility.h"

#include "AbilitySystem/SMAbilitySystemComponent.h"
#include "Characters/SMPlayerCharacter.h"

USMGameplayAbility::USMGameplayAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateNo;
	NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
	NetSecurityPolicy = EGameplayAbilityNetSecurityPolicy::ClientOrServer;
}

USMAbilitySystemComponent* USMGameplayAbility::GetSMAbilitySystemComponentFromActorInfo() const
{
	if (ensure(CurrentActorInfo))
	{
		return Cast<USMAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get());
	}

	return nullptr;
}

ASMPlayerCharacter* USMGameplayAbility::GetSMPlayerCharacterFromActorInfo() const
{
	if (ensure(CurrentActorInfo))
	{
		return Cast<ASMPlayerCharacter>(CurrentActorInfo->AvatarActor.Get());
	}

	return nullptr;
}

void USMGameplayAbility::ClientRPCPlayMontage_Implementation(UAnimMontage* InMontage, float InPlayRate, FName StartSection)
{
	if (ensure(ReplicationPolicy == EGameplayAbilityReplicationPolicy::ReplicateYes))
	{
		USMAbilitySystemComponent* SourceASC = GetSMAbilitySystemComponentFromActorInfo();
		if (ensure(SourceASC))
		{
			const float Duration = SourceASC->PlayMontage(this, CurrentActivationInfo, InMontage, InPlayRate, StartSection);
			ensure(Duration > 0.0f);
		}
	}
}
