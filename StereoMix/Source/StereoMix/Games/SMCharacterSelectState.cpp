﻿// Copyright Surround, Inc. All Rights Reserved.


#include "SMCharacterSelectState.h"

#include "CountdownTimerComponent.h"
#include "Net/UnrealNetwork.h"
#include "Player/SMPlayerState.h"

void ASMCharacterSelectState::OnRep_CharacterSelectionState() const
{
	CharacterSelectionStateChangedEvent.Broadcast(CharacterSelectionState);
}

ASMCharacterSelectState::ASMCharacterSelectState()
{
	CountdownTime = 30;
	
	CharacterSelectionState = ECharacterSelectionState::Select;
	CountdownTimer = CreateDefaultSubobject<UCountdownTimerComponent>(TEXT("RoomCountdownTimer"));
}

void ASMCharacterSelectState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);
	if(HasAuthority())
	{
		ASMPlayerState* SMPlayerState = Cast<ASMPlayerState>(PlayerState);
		if(SMPlayerState && SMPlayerState->GetTeam() == ESMTeam::None)
		{
			SMPlayerState->SetTeam(ESMTeam::FutureBass);
		}
	}
}

void ASMCharacterSelectState::RemovePlayerState(APlayerState* PlayerState)
{
	Super::RemovePlayerState(PlayerState);
}

void ASMCharacterSelectState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ThisClass, CharacterSelectionState);
}

void ASMCharacterSelectState::SetCharacterSelectionState(ECharacterSelectionState NewCharacterSelectionState)
{
#if  WITH_SERVER_CODE
	CharacterSelectionState = NewCharacterSelectionState;
	CharacterSelectionStateChangedEvent.Broadcast(NewCharacterSelectionState);
#endif
}

void ASMCharacterSelectState::NotifyPlayerJoined(ASMPlayerState* JoinedPlayer)
{
	if (OnPlayerJoined.IsBound())
	{
		OnPlayerJoined.Broadcast(JoinedPlayer);
	}
}

void ASMCharacterSelectState::NotifyPlayerLeft(ASMPlayerState* LeftPlayer)
{
	if (OnPlayerLeft.IsBound())
	{
		OnPlayerLeft.Broadcast(LeftPlayer);
	}
}

void ASMCharacterSelectState::NotifyPlayerTeamChanged(ASMPlayerState* Player, ESMTeam PreviousTeam, ESMTeam NewTeam)
{
}

void ASMCharacterSelectState::NotifyPlayerCharacterChanged(ASMPlayerState* Player, ESMCharacterType NewCharacter)
{
	if (OnPlayerCharacterChanged.IsBound())
	{
		OnPlayerCharacterChanged.Broadcast(Player, NewCharacter);
	}
}