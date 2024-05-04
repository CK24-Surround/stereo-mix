// Copyright Surround, Inc. All Rights Reserved.


#include "SMGameplayAbility_Launch_ElectricGuitar.h"

#include "Characters/SMPlayerCharacter.h"
#include "Games/SMGameMode.h"
#include "Projectiles/SMProjectile.h"
#include "Projectiles/SMProjectilePool.h"
#include "Utilities/SMLog.h"

class ASMGameMode;

void USMGameplayAbility_Launch_ElectricGuitar::LaunchProjectile(const FVector& InStartLocation, const FVector& InNormal)
{
	LaunchData.OffsetLocations.Empty();
	LaunchData.OffsetLocations.AddZeroed(ProjectileCount);
	LaunchData.Count = 0;
	LaunchData.Nomal = InNormal;

	const FVector RightVector = FVector::UpVector.Cross(LaunchData.Nomal);
	const float SegmentLength = ProjectileWidth / (ProjectileCount - 1);
	TArray<FVector> Points;
	for (int32 i = 0; i < ProjectileCount; ++i)
	{
		Points.Add(RightVector * (i * SegmentLength));
	}

	const int32 MidIndex = Points.Num() / 2;
	LaunchData.OffsetLocations[0] = Points[MidIndex];

	LaunchData.CenterOffsetLocation = -RightVector * (ProjectileWidth / 2.0);

	int32 Left = MidIndex - 1;
	int32 Right = MidIndex + 1;
	int32 Index = 1;

	while (Left >= 0 || Right < ProjectileCount)
	{
		if (Left >= 0)
		{
			LaunchData.OffsetLocations[Index++] = Points[Left--];
		}

		if (Right < ProjectileCount)
		{
			LaunchData.OffsetLocations[Index++] = Points[Right++];
		}
	}

	LaunchData.Rate = TotalLaunchTime / static_cast<float>(ProjectileCount - 1);

	// 첫 발은 즉시 발사합니다.
	LaunchTimerCallback();
}

void USMGameplayAbility_Launch_ElectricGuitar::LaunchTimerCallback()
{
	ASMPlayerCharacter* SourceCharacter = GetSMPlayerCharacterFromActorInfo();
	if (!ensureAlways(SourceCharacter))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	ASMGameMode* CachedSMGameMode = GetWorld()->GetAuthGameMode<ASMGameMode>();
	if (!ensureAlways(CachedSMGameMode))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	USMProjectilePool* ProjectilePool = CachedSMGameMode->GetEletricGuitarProjectilePool(SourceCharacter->GetTeam());
	if (!ensureAlways(ProjectilePool))
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	ASMProjectile* NewProjectile = ProjectilePool->GetProjectile();
	if (!NewProjectile)
	{
		EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	const FVector NewStartLocation = SourceCharacter->GetActorLocation() + LaunchData.CenterOffsetLocation;

	// 투사체를 발사합니다.
	NewProjectile->Launch(SourceCharacter, NewStartLocation + LaunchData.OffsetLocations[LaunchData.Count++], LaunchData.Nomal, ProjectileSpeed, MaxDistance, Damage);

	if (LaunchData.Count < ProjectileCount)
	{
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &USMGameplayAbility_Launch_ElectricGuitar::LaunchTimerCallback, LaunchData.Rate, false);
	}
	else
	{
		K2_EndAbility();
	}
}