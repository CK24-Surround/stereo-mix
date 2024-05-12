// Copyright Surround, Inc. All Rights Reserved.


#include "SMCatchableItem_AttributeChanger.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/SMTags.h"
#include "Components/BoxComponent.h"
#include "Components/SMCatchInteractionComponent_CatchableItem_AttributeChanger.h"
#include "Components/SMTeamComponent.h"
#include "Engine/OverlapResult.h"
#include "Tiles/SMTile.h"
#include "Utilities/SMCollision.h"
#include "Utilities/SMLog.h"


ASMCatchableItem_AttributeChanger::ASMCatchableItem_AttributeChanger()
{
	CIC = CreateDefaultSubobject<USMCatchInteractionComponent_CatchableItem_AttributeChanger>(TEXT("CIC"));

	TeamComponent = CreateDefaultSubobject<USMTeamComponent>(TEXT("TeamComponent"));
}

USMCatchInteractionComponent* ASMCatchableItem_AttributeChanger::GetCatchInteractionComponent()
{
	return CIC;
}

void ASMCatchableItem_AttributeChanger::ActivateItem(AActor* InActivator)
{
	if (!ensureAlways(InActivator))
	{
		return;
	}

	Activator = InActivator;

	ISMTeamInterface* InstigatorTeamInterface = Cast<ISMTeamInterface>(InActivator);
	if (!ensureAlways(InstigatorTeamInterface))
	{
		return;
	}

	ESMTeam SourceTeam = InstigatorTeamInterface->GetTeam();
	TeamComponent->SetTeam(SourceTeam);

	TriggerCount = Duration / Interval;
	TeamAmount = TeamTotalAmount / TriggerCount;

	ApplyGEToActivator();

	TriggerCountTimerStart();
}

void ASMCatchableItem_AttributeChanger::ApplyGEToActivator()
{
	if (!ensureAlways(Activator.Get()))
	{
		return;
	}

	UAbilitySystemComponent* ActivatorASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Activator.Get());
	if (!ensureAlways(ActivatorASC))
	{
		return;
	}

	if (ActivatorInstantGE)
	{
		FGameplayEffectSpecHandle GESpecHandle = ActivatorASC->MakeOutgoingSpec(ActivatorInstantGE, 1.0f, ActivatorASC->MakeEffectContext());
		if (ensureAlways(GESpecHandle.IsValid()))
		{
			GESpecHandle.Data->SetSetByCallerMagnitude(SMTags::Item::AttributeChanger, ActivatorInstantAmount);
			ActivatorASC->BP_ApplyGameplayEffectSpecToSelf(GESpecHandle);
		}
	}

	if (ActivatorDurationGE)
	{
		FGameplayEffectSpecHandle GESpecHandle = ActivatorASC->MakeOutgoingSpec(ActivatorDurationGE, 1.0f, ActivatorASC->MakeEffectContext());
		if (ensureAlways(GESpecHandle.IsValid()))
		{
			GESpecHandle.Data->Period = ActivatorInterval;

			const float Magnitude = ActivatorTotalAmount / (ActivatorDuration / ActivatorInterval);
			GESpecHandle.Data->SetByCallerTagMagnitudes.FindOrAdd(SMTags::Data::Duration, ActivatorDuration);
			GESpecHandle.Data->SetByCallerTagMagnitudes.FindOrAdd(SMTags::Item::AttributeChanger, Magnitude);
			ActivatorASC->BP_ApplyGameplayEffectSpecToSelf(GESpecHandle);
		}
	}
}

void ASMCatchableItem_AttributeChanger::TriggerCountTimerStart()
{
	TriggerData.CurrentTriggerCount = 0;

	ApplyItemByStart(GetConfirmedActorsToApplyItem());

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::TriggerCountTimerCallback, Interval, false);
}

void ASMCatchableItem_AttributeChanger::TriggerCountTimerCallback()
{
	if (TriggerData.CurrentTriggerCount++ < TriggerCount)
	{
		ApplyItemByWhile(GetConfirmedActorsToApplyItem());

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::TriggerCountTimerCallback, Interval, false);
	}
}

void ASMCatchableItem_AttributeChanger::ApplyItemByStart(TArray<AActor*> ActorsToApply)
{
	NET_LOG(this, Warning, TEXT("아이템 적용 시작"));
	for (const auto& ActorToApply : ActorsToApply)
	{
		// 활성자는 이 이펙트를 적용받으면 안 됩니다.
		if (ActorToApply == Activator)
		{
			continue;
		}

		UAbilitySystemComponent* ActorToApplyASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(ActorToApply);
		if (!ensureAlways(ActorToApplyASC))
		{
			return;
		}

		if (TeamInstantGE)
		{
			FGameplayEffectSpecHandle GESpecHandle = ActorToApplyASC->MakeOutgoingSpec(TeamInstantGE, 1.0f, ActorToApplyASC->MakeEffectContext());
			if (ensureAlways(GESpecHandle.IsValid()))
			{
				GESpecHandle.Data->SetSetByCallerMagnitude(SMTags::Item::AttributeChanger, TeamInstantAmount);
				ActorToApplyASC->BP_ApplyGameplayEffectSpecToSelf(GESpecHandle);
			}
		}

		NET_LOG(this, Warning, TEXT("%s"), *ActorToApply->GetName());
	}
}

void ASMCatchableItem_AttributeChanger::ApplyItemByWhile(TArray<AActor*> ActorsToApply)
{
	NET_LOG(this, Warning, TEXT("아이템 적용 중"));
	for (const auto& ActorToApply : ActorsToApply)
	{
		UAbilitySystemComponent* ActorToApplyASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(ActorToApply);
		if (!ensureAlways(ActorToApplyASC))
		{
			return;
		}

		if (TeamDurationGE)
		{
			FGameplayEffectSpecHandle GESpecHandle = ActorToApplyASC->MakeOutgoingSpec(TeamDurationGE, 1.0f, ActorToApplyASC->MakeEffectContext());
			if (ensureAlways(GESpecHandle.IsValid()))
			{
				GESpecHandle.Data->SetSetByCallerMagnitude(SMTags::Item::AttributeChanger, TeamAmount);
				ActorToApplyASC->BP_ApplyGameplayEffectSpecToSelf(GESpecHandle);
			}
		}

		NET_LOG(this, Warning, TEXT("%s"), *ActorToApply->GetName());
	}
}

TArray<AActor*> ASMCatchableItem_AttributeChanger::GetConfirmedActorsToApplyItem()
{
	TArray<AActor*> ActorsOnTriggeredTiles = GetActorsOnTriggeredTiles(SMCollisionTraceChannel::Action);

	TArray<AActor*> ConfirmedActorsToApplyItem;
	for (const auto& ActorOnTriggeredTiles : ActorsOnTriggeredTiles)
	{
		if (!ActorOnTriggeredTiles)
		{
			continue;
		}

		if (IsValidActorToApplyItem(ActorOnTriggeredTiles))
		{
			// 최종적으로 아이템이 적용될 수 있는 액터만 저장해둡니다.
			ConfirmedActorsToApplyItem.Add(ActorOnTriggeredTiles);
		}
	}

	return ConfirmedActorsToApplyItem;
}

TArray<AActor*> ASMCatchableItem_AttributeChanger::GetActorsOnTriggeredTiles(ECollisionChannel TraceChannel)
{
	TArray<AActor*> Result;
	for (const auto& TriggeredTile : TriggeredTiles)
	{
		if (!ensureAlways(TriggeredTile.Get()))
		{
			continue;
		}

		TArray<FOverlapResult> OverlapResults;
		const FVector TileLocation = TriggeredTile->GetTileLocation();
		FVector Start = TileLocation;
		UBoxComponent* TileBoxComponent = TriggeredTile->GetBoxComponent();
		float HalfTileHorizonSize = TileBoxComponent->GetScaledBoxExtent().X;

		FVector CollisionHalfExtend;
		if (HalfTileHorizonSize > 0.0f)
		{
			const float Height = 50.0f;
			CollisionHalfExtend = FVector(HalfTileHorizonSize, HalfTileHorizonSize, Height);
			Start.Z += Height;
		}

		const FCollisionShape CollisionShape = FCollisionShape::MakeBox(CollisionHalfExtend);
		const FCollisionQueryParams Params(SCENE_QUERY_STAT(AttributeChanger), false, this);
		const bool bSuccess = GetWorld()->OverlapMultiByChannel(OverlapResults, Start, FQuat::Identity, TraceChannel, CollisionShape, Params);
		if (bSuccess)
		{
			for (const auto& OverlapResult : OverlapResults)
			{
				AActor* ActorOnTriggeredTile = OverlapResult.GetActor();
				if (!ActorOnTriggeredTile)
				{
					continue;
				}

				// 트리거된 타일 위에 있는 액터를 중복되지 않게 저장합니다.
				Result.AddUnique(ActorOnTriggeredTile);
			}
		}

		// TODO: 이펙트를 활성화할 곳입니다.

		if (bDrawDebug)
		{
			const FColor DebugColor = bSuccess ? FColor::Cyan : FColor::Green;
			DrawDebugBox(GetWorld(), Start, CollisionHalfExtend, DebugColor, false, Interval / 2);
		}
	}

	return Result;
}

bool ASMCatchableItem_AttributeChanger::IsValidActorToApplyItem(AActor* TargetActor)
{
	if (!TargetActor)
	{
		return false;
	}

	ISMTeamInterface* TargetTeamInterface = Cast<ISMTeamInterface>(TargetActor);
	if (!ensureAlways(TargetTeamInterface))
	{
		return false;
	}

	// 팀이 같은 경우만 적용됩니다. 추후 변경될 수 있습니다.
	ESMTeam SourceTeam = TeamComponent->GetTeam();
	ESMTeam TargetTeam = TargetTeamInterface->GetTeam();
	if (SourceTeam != TargetTeam)
	{
		return false;
	}

	return true;
}
