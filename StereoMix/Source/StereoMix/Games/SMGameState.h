// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Utilities/SMTeam.h"
#include "SMGameState.generated.h"

DECLARE_DELEGATE_OneParam(FOnChangeRoundTime, int32 /*RoundTime*/);
DECLARE_DELEGATE_OneParam(FOnChangeTeamScore, int32 /*RoundTime*/);

class USMDesignData;
/**
 * 
 */
UCLASS()
class STEREOMIX_API ASMGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ASMGameState();

public:
	virtual void PostInitializeComponents() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY()
	TObjectPtr<USMDesignData> DesignData;

// ~Score Section
public:
	void SetTeamScores(ESMTeam InTeam, int32 InScore);

	FOnChangeTeamScore OnChangeEDMTeamScore;
	FOnChangeTeamScore OnChangeFutureBaseTeamScore;

protected:
	void OnChangeTile(ESMTeam PreviousTeam, ESMTeam NewTeam);

	void AddTeamScore(ESMTeam InTeam);

	void SwapScore(ESMTeam PreviousTeam, ESMTeam NewTeam);

	UFUNCTION()
	void OnRep_ReplicatedEDMTeamScore();

	UFUNCTION()
	void OnRep_ReplicatedFutureBaseTeamScore();

	// 점수를 출력하는 임시 코드입니다.
	void PrintScore();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Score")
	TMap<ESMTeam, int32> TeamScores;

	/** TMap은 리플리케이트 되지 않기 때문에 사용됩니다. */
	UPROPERTY(ReplicatedUsing = "OnRep_ReplicatedEDMTeamScore")
	int32 ReplicatedEDMTeamScore;

	/** TMap은 리플리케이트 되지 않기 때문에 사용됩니다. */
	UPROPERTY(ReplicatedUsing = "OnRep_ReplicatedFutureBaseTeamScore")
	int32 ReplicatedFutureBaseTeamScore;

	int32 TotalTileCount = 0;
// ~Score Section

// ~Round Time Section
public:
	void SetRemainRoundTime(int32 InRemainRoundTime);

public:
	FOnChangeRoundTime OnChangeRoundTime;

protected:
	void PerformRoundTime();

	UFUNCTION()
	void OnRep_RemainRoundTime();

protected:
	FTimerHandle RoundTimerHandle;
	int32 RoundTime = 0.0f;

	UPROPERTY(ReplicatedUsing = "OnRep_RemainRoundTime")
	int32 RemainRoundTime = 0.0f;
// ~Round Time Section
};
