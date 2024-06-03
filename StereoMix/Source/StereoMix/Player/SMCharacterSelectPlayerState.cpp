﻿// Copyright Surround, Inc. All Rights Reserved.


#include "SMCharacterSelectPlayerState.h"

#include "SMCharacterSelectPlayerController.h"
#include "Games/SMCharacterSelectState.h"

ASMCharacterSelectPlayerState::ASMCharacterSelectPlayerState()
{
}

void ASMCharacterSelectPlayerState::BeginPlay()
{
	Super::BeginPlay();
	CharacterSelectState = GetWorld()->GetGameState<ASMCharacterSelectState>();
}

bool ASMCharacterSelectPlayerState::CanChangeTeam(ESMTeam NewTeam) const
{
	return false;
}

bool ASMCharacterSelectPlayerState::CanChangeCharacterType(ESMCharacterType NewCharacterType) const
{
	return Super::CanChangeCharacterType(NewCharacterType);
}

void ASMCharacterSelectPlayerState::ChangeCharacterType_Implementation(ESMCharacterType NewCharacterType)
{
	SetCharacterType(NewCharacterType);
}

