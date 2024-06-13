﻿// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SMFrontendPlayerController.h"
#include "Games/Room/SMRoomPlayerState.h"
#include "Player/SMPlayerState.h"
#include "UI/Widget/Loading/SMLoadingScreenWidget.h"
#include "UI/Widget/Room/SMRoomWidget.h"
#include "SMRoomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STEREOMIX_API ASMRoomPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	ASMRoomPlayerController();

	virtual void BeginPlay() override;
	
	virtual void OnRep_PlayerState() override;

	ASMRoomPlayerState* GetRoomPlayerState() const { return RoomPlayerState.Get(); }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<USMLoadingScreenWidget> LoadingScreenWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<USMRoomWidget> RoomWidgetClass;

	UPROPERTY(Transient)
	TObjectPtr<USMLoadingScreenWidget> LoadingScreenWidget;

	UPROPERTY(Transient)
	TObjectPtr<USMRoomWidget> RoomWidget;

	UPROPERTY(Transient)
	TWeakObjectPtr<ASMRoomState> RoomState;
	
	UPROPERTY(Transient)
	TWeakObjectPtr<ASMRoomPlayerState> RoomPlayerState;
};