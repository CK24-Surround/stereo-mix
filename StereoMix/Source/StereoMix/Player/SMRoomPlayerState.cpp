﻿// Copyright Surround, Inc. All Rights Reserved.


#include "SMRoomPlayerState.h"

#include "Games/SMRoomState.h"
#include "Utilities/SMLog.h"

ASMRoomPlayerState::ASMRoomPlayerState()
{
}

void ASMRoomPlayerState::PreInitializeComponents()
{
	Super::PreInitializeComponents();

#if WITH_SERVER_CODE
	if (HasAuthority())
	{
		const ASMRoomState* RoomState = GetWorld()->GetGameStateChecked<ASMRoomState>();
		Team = RoomState->GetPlayerCountInTeam(ESMTeam::EDM) < RoomState->MaxPlayersInTeam ? ESMTeam::EDM : ESMTeam::FutureBass;
		NET_LOG(this, Log, TEXT("[RoomPlayerState] Player %s initialize team to %s"), *GetName(), *UEnum::GetValueAsString(Team))
	}
#endif
}

void ASMRoomPlayerState::BeginPlay()
{
	Super::BeginPlay();
	const ASMRoomState* RoomState = GetWorld()->GetGameStateChecked<ASMRoomState>();
	RoomState->BroadcastPlayerAdded(this);
}

void ASMRoomPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	const ASMRoomState* RoomState = GetWorld()->GetGameStateChecked<ASMRoomState>();
	RoomState->BroadcastPlayerRemoved(this);
}

bool ASMRoomPlayerState::CanChangeTeam(const ESMTeam NewTeam) const
{
	const ASMRoomState* RoomState = CastChecked<ASMRoomState>(GetWorld()->GetGameState());
	return RoomState->GetPlayerCountInTeam(NewTeam) < RoomState->MaxPlayersInTeam;
}

void ASMRoomPlayerState::OnTeamChanged(const ESMTeam PreviousTeam, const ESMTeam NewTeam)
{
	Super::OnTeamChanged(PreviousTeam, NewTeam);
	if (PreviousTeam != ESMTeam::None && NewTeam != PreviousTeam)
	{
		const ASMRoomState* RoomState = GetWorld()->GetGameStateChecked<ASMRoomState>();
		RoomState->BroadcastTeamChanged(this, NewTeam);
	}
}