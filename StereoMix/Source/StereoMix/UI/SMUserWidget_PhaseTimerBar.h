// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SMUserWidget.h"
#include "SMUserWidget_PhaseTimerBar.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class STEREOMIX_API USMUserWidget_PhaseTimerBar : public USMUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

public:
	void SetRatio(float InRatio);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> PhaseTimerBar;

	UPROPERTY()
	TWeakObjectPtr<UMaterialInstanceDynamic> PhaseTimerBarMaterialInstanceDynamic;
};
