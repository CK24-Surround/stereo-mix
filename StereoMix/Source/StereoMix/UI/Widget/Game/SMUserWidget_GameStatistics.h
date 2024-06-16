﻿// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "SMUserWidget.h"
#include "SMUserWidget_GameStatistics.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API USMUserWidget_GameStatistics : public USMUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	void UpdatePingText(int32 NewPing) const;
	
private:
	UPROPERTY(Transient, BlueprintReadOnly, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UCommonTextBlock> PingTextBlock;
};
