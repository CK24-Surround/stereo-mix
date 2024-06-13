// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SMGameplayCueNotify.h"
#include "Data/SMLocalTeam.h"
#include "SMGameplayCueNotify_WithLocalTeam.generated.h"

class UFMODEvent;
class UNiagaraSystem;

/**
 * 
 */
UCLASS()
class STEREOMIX_API USMGameplayCueNotify_WithLocalTeam : public USMGameplayCueNotify
{
	GENERATED_BODY()

public:
	USMGameplayCueNotify_WithLocalTeam();

protected:
	virtual void PlayNiagaraSystem(AActor* SourceActor, const FGameplayCueParameters& Parameters) const override;

	virtual void PlayNiagaraSystemWithAttach(AActor* SourceActor, const FGameplayCueParameters& Parameters) const override;

	virtual void PlaySound(AActor* SourceActor, const FGameplayCueParameters& Parameters) const override;

	virtual void PlaySoundWithAttach(AActor* SourceActor, const FGameplayCueParameters& Parameters) const override;

	/** 로컬에서 플레이하고 있는 팀과 시전자의 팀이 같은지 확인합니다. */
	bool IsSameTeamWithLocalTeam(AActor* SourceActor) const;

	UPROPERTY(EditAnywhere, Category = "Design|FX|Effect")
	TMap<ESMLocalTeam, TObjectPtr<UNiagaraSystem>> Effect;

	UPROPERTY(EditAnywhere, Category = "Design|FX|Sound")
	TMap<ESMLocalTeam, TObjectPtr<UFMODEvent>> Sound;
};
