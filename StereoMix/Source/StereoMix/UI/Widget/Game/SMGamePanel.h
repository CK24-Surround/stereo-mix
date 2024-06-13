﻿// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "CommonActivatableWidget.h"
#include "SMGamePanel.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API USMGamePanel : public UCommonActivatableWidget, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	/** 위젯 컴포넌트에 위젯이 생성될때 호출되며 ASC가 할당됩니다. */
	virtual void SetASC(UAbilitySystemComponent* InASC);
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	TWeakObjectPtr<UAbilitySystemComponent> ASC;
};