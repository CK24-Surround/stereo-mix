// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMGameplayAbility.h"
#include "SMGameplayAbility_Smashed.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API USMGameplayAbility_Smashed : public USMGameplayAbility
{
	GENERATED_BODY()

public:
	USMGameplayAbility_Smashed();

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Montage")
	TObjectPtr<UAnimMontage> SmashedMontage;
};
