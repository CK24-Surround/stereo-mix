// Fill out your copyright notice in the Description page of Project Settings.


#include "SMAbilitySystemComponent.h"

#include "Abilities/GameplayEffect/SMGameplayEffect_DynamicTag.h"
#include "Characters/SMPlayerCharacter.h"

void USMAbilitySystemComponent::OnTagUpdated(const FGameplayTag& Tag, bool TagExists)
{
	OnChangedTag.Broadcast(Tag, TagExists);
}

void USMAbilitySystemComponent::AddTag(const FGameplayTag& InGameplayTag)
{
	const TSubclassOf<UGameplayEffect> DynamicTagGE = USMGameplayEffect_DynamicTag::StaticClass();
	if (!ensure(DynamicTagGE))
	{
		return;
	}

	const FGameplayEffectSpecHandle GESpecHandle = MakeOutgoingSpec(DynamicTagGE, 1.0f, MakeEffectContext());
	FGameplayEffectSpec* GESpec = GESpecHandle.Data.Get();
	if (!ensure(GESpec))
	{
		return;
	}

	GESpec->DynamicGrantedTags.AddTag(InGameplayTag);
	ApplyGameplayEffectSpecToSelf(*GESpec);
}

void USMAbilitySystemComponent::RemoveTag(const FGameplayTag& InGameplayTag)
{
	const TSubclassOf<UGameplayEffect> DynamicTagGE = USMGameplayEffect_DynamicTag::StaticClass();
	if (!ensure(DynamicTagGE))
	{
		return;
	}

	FGameplayEffectQuery GEQuery = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(FGameplayTagContainer(InGameplayTag));
	GEQuery.EffectDefinition = DynamicTagGE;
	
	RemoveActiveEffects(GEQuery);
}