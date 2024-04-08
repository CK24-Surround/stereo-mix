// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StereoMixDesignData.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API UStereoMixDesignData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter|Movement", DisplayName = "이동속도")
	float MoveSpeed = 700.0f;

public:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter|Projectile", DisplayName = "투사체 공격력")
	float ProjectileAttack = 16.67f;
	
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter|Projectile", DisplayName = "초당 투사체 공격 속도")
	float ProjectileRate = 4.0f;

	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter|Projectile", DisplayName = "투사체 속도")
	float ProjectileSpeed = 2250.0f;

	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter|Projectile", DisplayName = "투사체 사정거리")
	float ProjectileMaxDistance = 2250.0f;
};