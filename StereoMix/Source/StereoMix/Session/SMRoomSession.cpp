﻿// Copyright Surround, Inc. All Rights Reserved.


#include "SMRoomSession.h"

#include "StereoMix.h"
#include "Connection/SMGameServerConnectionSubsystem.h"


// Sets default values
ASMRoomSession::ASMRoomSession()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxPlayers = 6;
}

void ASMRoomSession::RegisterServer()
{
	Super::RegisterServer();
}

// Called when the game starts or when spawned
void ASMRoomSession::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogStereoMix, Verbose, TEXT("MaxPlayers set to %d"), MaxPlayers);
}

// Called every frame
void ASMRoomSession::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
