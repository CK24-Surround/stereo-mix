// Copyright Surround, Inc. All Rights Reserved.


#include "SMGameMode.h"

#include "SMGameState.h"
#include "GameFramework/PlayerState.h"
#include "GameInstance/SMGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Projectiles/SMProjectilePool.h"
#include "Session/SMGameSession.h"
#include "Utilities/SMLog.h"

ASMGameMode::ASMGameMode()
{
	bDelayedStart = true;
	bUseSeamlessTravel = true;
	GameSessionClass = ASMGameSession::StaticClass();
}

void ASMGameMode::BeginPlay()
{
	Super::BeginPlay();
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

	InitProjectilePool();
}

void ASMGameMode::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();

	if (bIsIgnoreWait)
	{
		// 이 경우 즉시 호출합니다.
		OnWaitTimeEndCallback();
		return;
	}

	// 대기 시간동안 기다립니다.
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::OnWaitTimeEndCallback, WaitTime);
}

void ASMGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	NET_LOG(this, Warning, TEXT("게임 시작"));
	StartRound();
	OnStartMatch.Broadcast();
}

void ASMGameMode::HandleMatchHasEnded()
{
	Super::HandleMatchHasEnded();

	// 남은 시간을 승패 확인 시간으로 다시 초기화시킵니다.
	SetRemainRoundTime(VictoryDefeatTime);

	// 매치가 종료되어 스코어 계산을 합니다.
	if (ensure(CachedSMGameState.Get()))
	{
		CachedSMGameState->EndRoundVictoryDefeatResult();
	}
}

void ASMGameMode::HandleLeavingMap()
{
	Super::HandleLeavingMap();

	if (bUseRestart)
	{
		RestartGame();
		return;
	}

	USMGameInstance* GameInstance = GetGameInstance<USMGameInstance>();
	if (GameInstance->IsCustomGame())
	{
		ProcessServerTravel("/Game/StereoMix/Levels/Room/L_Room");
	}
	else
	{
		// 클라이언트들을 연결 종료시키고 서버를 종료합니다.
		ReturnToMainMenuHost();

		if (ASMGameSession* Session = CastChecked<ASMGameSession>(GameSession); Session->IsValidRoom())
		{
			Session->DeleteRoom();
		}
	}
}

void ASMGameMode::PrintPlayerNum()
{
	NET_LOG(this, Log, TEXT("플레이어 수: %d"), GetNumPlayers());
}

void ASMGameMode::BindToGameState()
{
	CachedSMGameState = GetGameState<ASMGameState>();
	if (ensureAlways(CachedSMGameState.Get()))
	{
		CachedSMGameState->SetReplicatedPhaseTime(PhaseTime);
	}
}

void ASMGameMode::OnWaitTimeEndCallback()
{
	const float OneSecond = GetWorldSettings()->GetEffectiveTimeDilation();

	SetRemainCountdownTime(CountdownTime);
	GetWorldTimerManager().SetTimer(CountdownTimeHandle, this, &ThisClass::PerformCountdownTime, OneSecond, true);
}

void ASMGameMode::SetRemainCountdownTime(int32 InRemainCountdownTime)
{
	RemainCountdownTime = InRemainCountdownTime;

	// 게임 스테이트로 복제합니다.
	if (ensure(CachedSMGameState.Get()))
	{
		CachedSMGameState->SetReplicatedRemainCountdownTime(RemainCountdownTime);
	}
}

void ASMGameMode::PerformCountdownTime()
{
	SetRemainCountdownTime(RemainCountdownTime - 1);

	if (RemainCountdownTime <= 0)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimeHandle);
		CountdownTimeHandle.Invalidate();

		OnCountdownTimeEnd();
	}
}

void ASMGameMode::OnCountdownTimeEnd()
{
	StartMatch();
}

void ASMGameMode::StartRound()
{
	const float OneSecond = GetWorldSettings()->GetEffectiveTimeDilation();

	// 남은 라운드 시간을 초기화해줍니다.
	SetRemainRoundTime(RoundTime);
	GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &ASMGameMode::PerformRoundTime, OneSecond, true);

	// 남은 페이즈 시간을 초기화해줍니다.
	SetRemainPhaseTime(PhaseTime);
	SetCurrentPhaseNumber(1);
	GetWorldTimerManager().SetTimer(PhaseTimerHandle, this, &ASMGameMode::PerformPhaseTime, OneSecond, true);
}

void ASMGameMode::SetRemainRoundTime(int32 InRemainRoundTime)
{
	RemainRoundTime = InRemainRoundTime;

	// 게임 스테이트로 복제합니다.
	if (ensure(CachedSMGameState.Get()))
	{
		CachedSMGameState->SetReplicatedRemainRoundTime(RemainRoundTime);
	}
}

void ASMGameMode::PerformRoundTime()
{
	// 라운드 타이머 종료 시
	if (!bIsRoundEnd && RemainRoundTime <= 0)
	{
		bIsRoundEnd = true;
		EndMatch();
		return;
	}

	// 승패 확인 타이머 종료 시
	if (bIsRoundEnd && RemainRoundTime <= 0)
	{
		SetMatchState(MatchState::LeavingMap);
		return;
	}

	// 매 초 남은 시간을 감소시킵니다.
	SetRemainRoundTime(RemainRoundTime - 1);
}

void ASMGameMode::SetRemainPhaseTime(int32 InRemainPhaseTime)
{
	RemainPhaseTime = InRemainPhaseTime;

	// 게임 스테이트로 복제합니다.
	if (ensure(CachedSMGameState.Get()))
	{
		CachedSMGameState->SetReplicatedRemainPhaseTime(RemainPhaseTime);
	}
}

void ASMGameMode::PerformPhaseTime()
{
	SetRemainPhaseTime(RemainPhaseTime - 1);

	if (RemainPhaseTime <= 0)
	{
		// 한 페이즈 종료시 마다 처리됩니다. 
		SetCurrentPhaseNumber(CurrentPhaseNumber + 1);
		SetRemainPhaseTime(PhaseTime);

		if (ensureAlways(CachedSMGameState.Get()))
		{
			CachedSMGameState->EndPhase();
		}
	}
}

void ASMGameMode::SetCurrentPhaseNumber(int32 InCurrentPhaseNumber)
{
	CurrentPhaseNumber = InCurrentPhaseNumber;

	if (ensureAlways(CachedSMGameState.Get()))
	{
		// 게임 스테이트에 복제해줍니다.
		CachedSMGameState->SetReplicatedCurrentPhaseNumber(CurrentPhaseNumber);
	}
}

ASMProjectile* ASMGameMode::GetProjectileFromProjectilePool(ESMTeam SourceTeam, ESMCharacterType SourceCharacterType)
{
	FProjectilePoolInstanceData* ProjectilePoolInstanceDataPtr = ProjectilePools.Find(SourceTeam);
	if (ensureAlways(ProjectilePoolInstanceDataPtr))
	{
		TMap<ESMCharacterType, TObjectPtr<USMProjectilePool>>& ProjectilePoolMap = ProjectilePoolInstanceDataPtr->ProjectilePoolMap;
		USMProjectilePool* ProjectilePool = ProjectilePoolMap.FindOrAdd(SourceCharacterType, nullptr);
		if (ensureAlways(ProjectilePool))
		{
			// 투사체 풀에서 투사체를 꺼내서 반환합니다.
			return ProjectilePool->GetProjectile();
		}
	}

	return nullptr;
}

void ASMGameMode::InitProjectilePool()
{
	// 투사체 풀을 생성합니다. 각 팀, 캐릭터에 맞는 투사체 풀을 생성하기위한 과정입니다. 이렇게 난해하게 처리하는 이유는 블루프린트에서 투사체 풀을 지정할 수 있도록하기 위함입니다.
	for (auto& ProjectilePoolCreateDataMapPair : ProjectilePoolCreateDataMap) // 팀을 순회합니다.
	{
		ESMTeam& Team = ProjectilePoolCreateDataMapPair.Key;
		TMap<ESMCharacterType, TSubclassOf<USMProjectilePool>>& ProjectilePoolClassMap = ProjectilePoolCreateDataMapPair.Value.ClassMapByCharacterType;

		for (auto& ProjectilePoolClassMapPair : ProjectilePoolClassMap) // 캐릭터 타입을 순회합니다.
		{
			ESMCharacterType& CharacterType = ProjectilePoolClassMapPair.Key;
			TSubclassOf<USMProjectilePool>& ProjectilePoolClass = ProjectilePoolClassMapPair.Value;

			if (!ProjectilePoolClass)
			{
				NET_LOG(this, Warning, TEXT("투사체 풀 클래스가 무효합니다."));
				continue;
			}

			// 투사체풀을 생성하고 초기화합니다.
			USMProjectilePool* ProjectilePool = NewObject<USMProjectilePool>(this, ProjectilePoolClass);
			ProjectilePool->Init();

			TMap<ESMCharacterType, TObjectPtr<USMProjectilePool>>& ProjectilePoolMap = ProjectilePools.FindOrAdd(Team).ProjectilePoolMap;
			ProjectilePoolMap.Add(CharacterType, ProjectilePool); // 투사체풀 인스턴스 맵에 팀과 캐릭터에 해당하는 투사체 풀을 저장합니다.
		}
	}
}