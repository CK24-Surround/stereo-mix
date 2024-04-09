// Fill out your copyright notice in the Description page of Project Settings.


#include "StereoMixGameplayAbility_Caught.h"

#include "AbilitySystemComponent.h"
#include "Utilities/StereoMixTag.h"

UStereoMixGameplayAbility_Caught::UStereoMixGameplayAbility_Caught()
{
	AbilityTags = FGameplayTagContainer(StereoMixTag::Ability::Caught);
	ActivationOwnedTags = FGameplayTagContainer(StereoMixTag::Character::State::Caught);
	
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	ReplicationPolicy = EGameplayAbilityReplicationPolicy::ReplicateYes;
}

void UStereoMixGameplayAbility_Caught::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!ensure(ActorInfo))
	{
		return;
	}

	UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get();
	if (!ASC)
	{
		return;
	}

	ASC->PlayMontage(this, ActivationInfo, CaughtMontage, 1.0f);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}