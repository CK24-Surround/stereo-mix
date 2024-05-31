﻿// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SMGrpcClientSubsystem.h"
#include "SAuth/AuthService.h"
#include "SMAuthSubsystem.generated.h"

/**
 * StereoMix Authentication Subsystem
 */
UCLASS(Abstract, BlueprintType)
class STEREOMIX_API USMAuthSubsystem : public USMGrpcClientSubsystem
{
	GENERATED_BODY()

public:
	USMAuthSubsystem();

	UAuthService* GetAuthService() const { return Cast<UAuthService>(GrpcService); }

	UFUNCTION(BlueprintPure)
	virtual bool IsAuthenticated() const;

	UFUNCTION(BlueprintCallable)
	virtual void RestAuthentication();
};