// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Static.h"

#include "SMGameplayCueNotifyBase.generated.h"

/**
 *
 */
UCLASS(Abstract)
class STEREOMIX_API USMGameplayCueNotifyBase : public UGameplayCueNotify_Static
{
	GENERATED_BODY()

protected:
	/** 큐 파라미터에서 위치와 회전값을 가져옵니다.*/
	UFUNCTION(BlueprintCallable, Category = "Design|Utilities")
	void GetLocationAndRotation(const FGameplayCueParameters& Parameters, FVector& OutLocation, FRotator& OutRotation) const;
};
