// Fill out your copyright notice in the Description page of Project Settings.


#include "SMUserWidget_CharacterState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AttributeSets/SMCharacterAttributeSet.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void USMUserWidget_CharacterState::SetASC(UAbilitySystemComponent* InASC)
{
	Super::SetASC(InASC);

	APlayerState* PlayerState = Cast<APlayerState>(InASC->GetOwnerActor());
	if (ensure(PlayerState))
	{
		UpdateNickname(PlayerState->GetPlayerName());
	}

	InASC->GetGameplayAttributeValueChangeDelegate(USMCharacterAttributeSet::GetPostureGaugeAttribute()).AddUObject(this, &USMUserWidget_CharacterState::OnChangeCurrentHealth);
	InASC->GetGameplayAttributeValueChangeDelegate(USMCharacterAttributeSet::GetMaxPostureGaugeAttribute()).AddUObject(this, &USMUserWidget_CharacterState::OnChangeMaxHealth);

	const USMCharacterAttributeSet* SourceAttributeSet = InASC->GetSet<USMCharacterAttributeSet>();
	if (ensure(SourceAttributeSet))
	{
		CurrentHealth = SourceAttributeSet->GetPostureGauge();
		MaxHealth = SourceAttributeSet->GetMaxPostureGauge();
		UpdateHealth();
	}
}

void USMUserWidget_CharacterState::UpdateNickname(const FString& InNickname)
{
	TB_Nickname->SetText(FText::FromString(InNickname));
}

void USMUserWidget_CharacterState::OnChangeCurrentHealth(const FOnAttributeChangeData& OnAttributeChangeData)
{
	CurrentHealth = OnAttributeChangeData.NewValue;
	UpdateHealth();
}

void USMUserWidget_CharacterState::OnChangeMaxHealth(const FOnAttributeChangeData& OnAttributeChangeData)
{
	MaxHealth = OnAttributeChangeData.NewValue;
	UpdateHealth();
}

void USMUserWidget_CharacterState::UpdateHealth()
{
	PB_Health->SetPercent(CurrentHealth / MaxHealth);
}