// Fill out your copyright notice in the Description page of Project Settings.


#include "SMGameState.h"

#include "EngineUtils.h"
#include "Tiles/SMTile.h"
#include "Utilities/SMLog.h"

ASMGameState::ASMGameState()
{
	TeamScores.Add(ESMTeam::FutureBass, 0);
	TeamScores.Add(ESMTeam::EDM, 0);
}

void ASMGameState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (HasAuthority())
	{
		for (ASMTile* Tile : TActorRange<ASMTile>(GetWorld()))
		{
			if (!Tile)
			{
				continue;
			}

			++TotalTileCount;
			Tile->OnChangeTile.AddUObject(this, &ASMGameState::OnChangeTile);
		}

		NET_LOG(this, Warning, TEXT("현재 타일 개수: %d"), TotalTileCount);
	}
}

void ASMGameState::OnChangeTile(ESMTeam PreviousTeam, ESMTeam NewTeam)
{
	// 이런 경우는 없어야하지만 만약을 위한 방어 코드입니다.
	if (PreviousTeam == NewTeam)
	{
		return;
	}

	// TODO: 나중에 중립 타일화 시키는 기능을 구현해야합니다.
	if (NewTeam == ESMTeam::None)
	{
		return;
	}

	if (PreviousTeam == ESMTeam::None)
	{
		AddTeamScore(NewTeam);
	}
	else
	{
		SwapScore(PreviousTeam, NewTeam);
	}

	PrintScore();
}

void ASMGameState::AddTeamScore(ESMTeam InTeam)
{
	++TeamScores[InTeam];
}

void ASMGameState::SwapScore(ESMTeam PreviousTeam, ESMTeam NewTeam)
{
	--TeamScores[PreviousTeam];
	++TeamScores[NewTeam];
}

void ASMGameState::PrintScore()
{
	NET_LOG(this, Warning, TEXT("FutureBase팀 스코어: %d EDM팀 스코어: %d"), TeamScores[ESMTeam::FutureBass], TeamScores[ESMTeam::EDM]);
}
