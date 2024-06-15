﻿// Copyright Surround, Inc. All Rights Reserved.


#include "SMCharacterSelectPlayerController.h"

#include "EngineUtils.h"
#include "Games/CharacterSelect/SMCharacterSelectMode.h"
#include "Games/CharacterSelect/SMCharacterSelectPlayerState.h"
#include "Subsystem/SMBackgroundMusicSubsystem.h"
#include "Utilities/SMLog.h"

ASMCharacterSelectPlayerController::ASMCharacterSelectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Type::Default;
}

void ASMCharacterSelectPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld()->GetGameViewport())
	{
		LoadingScreenWidget = CreateWidget<USMLoadingScreenWidget>(this, LoadingScreenWidgetClass);
		LoadingScreenWidget->SetLoadingText(FText::FromString(TEXT("다른 플레이어들을 기다리는 중 입니다...")));
		LoadingScreenWidget->AddToViewport(10);
	}
}

void ASMCharacterSelectPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetGameInstance()->GetSubsystem<USMBackgroundMusicSubsystem>()->StopAndReleaseBackgroundMusic();
}

void ASMCharacterSelectPlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (GetWorld()->GetGameState())
	{
		InitPlayer();
	}
	else
	{
		NET_LOG(this, Verbose, TEXT("GameState is not set yet. Register GameStateSetEvent."))
		GetWorld()->GameStateSetEvent.AddLambda([this](AGameStateBase*)
		{
			InitPlayer();
		});
	}
}

void ASMCharacterSelectPlayerController::RequestImmediateStartGame_Implementation()
{
#if WITH_SERVER_CODE
	if (GetWorld() && GetWorld()->GetAuthGameMode())
	{
		ASMCharacterSelectMode* CharacterSelectMode = CastChecked<ASMCharacterSelectMode>(GetWorld()->GetAuthGameMode());
		CharacterSelectMode->ImmediateStart();
	}
#endif
}

void ASMCharacterSelectPlayerController::InitPlayer()
{
	CharacterSelectState = GetWorld()->GetGameStateChecked<ASMCharacterSelectState>();
	CharacterSelectState->OnCurrentStateChanged.AddDynamic(this, &ASMCharacterSelectPlayerController::OnCurrentCharacterSelectStateChanged);

	CharacterSelectPlayerState = Cast<ASMCharacterSelectPlayerState>(PlayerState);
	CharacterSelectPlayerState->OnCharacterChangeResponse.AddDynamic(this, &ASMCharacterSelectPlayerController::OnCharacterChangeResponse);

	ESMTeam Team = CharacterSelectPlayerState->GetTeam();
	for (TActorIterator<AActor> It(GetWorld(), ASMPreviewCharacter::StaticClass()); It; ++It)
	{
		if (ASMPreviewCharacter* TargetCharacter = Cast<ASMPreviewCharacter>(*It); TargetCharacter && TargetCharacter->GetTeam() == Team)
		{
			NET_LOG(this, Verbose, TEXT("PreviewCharacter: %s - %s"), *UEnum::GetValueAsString(TargetCharacter->GetTeam()), *UEnum::GetValueAsString(TargetCharacter->GetCharacterType()))
			PreviewCharacters.Add(TargetCharacter->GetCharacterType(), TargetCharacter);
		}
	}

	CharacterSelectPlayerState->SetCurrentState(ECharacterSelectPlayerStateType::Unready);
}

void ASMCharacterSelectPlayerController::OnCurrentCharacterSelectStateChanged(ECharacterSelectionStateType NewCharacterSelectionState)
{
	NET_LOG(this, Verbose, TEXT("Current character selection state: %s"), *UEnum::GetValueAsString(NewCharacterSelectionState));
	if (NewCharacterSelectionState == ECharacterSelectionStateType::Select)
	{
		LoadingScreenWidget->HideLoadingScreen();
		CharacterSelectWidget = CreateWidget<USMCharacterSelectWidget>(this, CharacterSelectWidgetClass);
		CharacterSelectWidget->InitWidget(GetCharacterSelectState(), GetCharacterSelectPlayerState());
		CharacterSelectWidget->AddToViewport();
		
		GetGameInstance()->GetSubsystem<USMBackgroundMusicSubsystem>()->PlayTeamBackgroundMusic(CharacterSelectPlayerState->GetTeam());
		NET_LOG(this, Verbose, TEXT("PlayTeamBackgroundMusic: %s"), *UEnum::GetValueAsString(CharacterSelectPlayerState->GetTeam()))
	}
}

void ASMCharacterSelectPlayerController::OnCharacterChangeResponse(bool bSuccess, ESMCharacterType NewCharacterType)
{
	if (bSuccess)
	{
		if (const TObjectPtr<ASMPreviewCharacter>* PreviewCharacter = PreviewCharacters.Find(NewCharacterType))
		{
			PreviewCharacter->Get()->PlaySelectAnimation();
		}
	}
}
