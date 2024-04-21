// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "SMChangeAttributeItem.generated.h"

class USphereComponent;
class UGameplayEffect;

UCLASS(Abstract)
class STEREOMIX_API ASMChangeAttributeItem : public AActor
{
	GENERATED_BODY()

public:
	ASMChangeAttributeItem();

protected:
	virtual void PostInitializeComponents() override;

protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastRPCSetHidden(bool bNewHidden);

	void HealRespawnTimerCallback();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Root")
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = "SpawnerMesh")
	TObjectPtr<UStaticMeshComponent> SpawnerMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "ItemMesh")
	TObjectPtr<UStaticMeshComponent> ItemMeshComponent;

protected:
	UPROPERTY(EditAnywhere, Category = "GAS|GE")
	TSubclassOf<UGameplayEffect> GE;

	UPROPERTY(EditAnywhere, Category = "Design")
	float RespawnTime = 10.0f;
};