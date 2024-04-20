// Fill out your copyright notice in the Description page of Project Settings.


#include "SMGameMode.h"

#include "SMGameState.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

ASMGameMode::ASMGameMode()
{
	bUseSeamlessTravel = true;
}

FString ASMGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	const FString ErrorMessage = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);

	FString InNickname = UGameplayStatics::ParseOption(Options, TEXT("Nickname")).Left(20);
	if (InNickname.IsEmpty())
	{
		InNickname = FString::Printf(TEXT("%s%i"), *DefaultPlayerName.ToString(), NewPlayerController->PlayerState->GetPlayerId());
	}

	ChangeName(NewPlayerController, InNickname, false);

	return ErrorMessage;
}

void ASMGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	BindToGameState();
}

void ASMGameMode::EndMatch()
{
	ASMGameState* SMGameState = GetGameState<ASMGameState>();
	if (ensure(SMGameState))
	{
		SMGameState->EndRound();
	}

	Super::EndMatch();
}

void ASMGameMode::BindToGameState()
{
	ASMGameState* SMGameState = GetGameState<ASMGameState>();
	if (ensure(SMGameState))
	{
		SMGameState->OnEndRoundTimer.BindUObject(this, &ASMGameMode::OnEndRoundTimer);
		SMGameState->OnEndVictoryDefeatTimer.BindUObject(this, &ASMGameMode::OnEndVictoryDefeatTimer);
	}
}

void ASMGameMode::OnEndRoundTimer()
{
	EndMatch();
}

void ASMGameMode::OnEndVictoryDefeatTimer()
{
	FString CurrentLevelPath = TEXT("/Game/StereoMix/Levels/Main/L_Main");
	GetWorld()->ServerTravel(CurrentLevelPath);
}
