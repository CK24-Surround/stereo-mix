// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StereoMixGameplayAbility.h"
#include "StereoMixGameplayAbility_Caught.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API UStereoMixGameplayAbility_Caught : public UStereoMixGameplayAbility
{
	GENERATED_BODY()

public:
	UStereoMixGameplayAbility_Caught();

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Montage")
	TObjectPtr<UAnimMontage> CaughtMontage;
};
