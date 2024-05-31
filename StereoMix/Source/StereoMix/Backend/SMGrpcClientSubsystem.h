﻿// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SMGrpcSubsystem.h"
#include "TurboLinkGrpcService.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SMGrpcClientSubsystem.generated.h"

/**
 * StereoMix gRPC Client Subsystem
 */
UCLASS(Abstract)
class STEREOMIX_API USMGrpcClientSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	USMGrpcClientSubsystem();

	explicit USMGrpcClientSubsystem(const FString& InServiceName);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	const FString& GetServiceName() const { return ServiceName; }

	virtual UGrpcService* GetGrpcService() const;

	virtual void Connect() const;

	virtual bool IsBusy() const { return false; }

protected:
	UPROPERTY()
	TObjectPtr<USMGrpcSubsystem> GrpcSubsystem;

	UPROPERTY()
	TObjectPtr<UTurboLinkGrpcManager> GrpcManager;

	UPROPERTY()
	TObjectPtr<UGrpcService> GrpcService;

	UPROPERTY(VisibleDefaultsOnly)
	FString ServiceName;
	
	UFUNCTION()
	virtual void OnServiceStateChanged(EGrpcServiceState ServiceState);
};
