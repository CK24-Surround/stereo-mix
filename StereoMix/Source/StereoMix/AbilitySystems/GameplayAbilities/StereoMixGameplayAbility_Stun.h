// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "StereoMixGameplayAbility_Stun.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API UStereoMixGameplayAbility_Stun : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	UFUNCTION()
	void OnStandUp();
	
	UFUNCTION()
	void OnComplete();

	UFUNCTION()
	void OnInterrupted();

	UFUNCTION()
	void OnCancelled();
	
protected:
	UPROPERTY(EditAnywhere, Category = "Montage")
	TObjectPtr<UAnimMontage> StunMontage;

	UPROPERTY(EditAnywhere, Category = "Montage")
	TObjectPtr<UAnimMontage> StandUpMontage;
};