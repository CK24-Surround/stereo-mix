// Fill out your copyright notice in the Description page of Project Settings.


#include "SMProjectile.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Components/SMTeamComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "Data/SMDesignData.h"
#include "Data/SMProjectileAssetData.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Interfaces/SMTeamComponentInterface.h"
#include "Utilities/SMAssetPath.h"
#include "Utilities/SMCollision.h"
#include "Utilities/SMLog.h"
#include "AbilitySystem/SMTags.h"

ASMProjectile::ASMProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USMDesignData> DesignDataRef(SMAssetPath::DesignData);
	if (DesignDataRef.Object)
	{
		DesignData = DesignDataRef.Object;
	}
	else
	{
		NET_LOG(nullptr, Error, TEXT("DesignData 로드에 실패했습니다."));
	}

	static ConstructorHelpers::FObjectFinder<USMProjectileAssetData> ProjectileAssetDataRef(SMAssetPath::ProjectileAssetData);
	if (ProjectileAssetDataRef.Object)
	{
		AssetData = ProjectileAssetDataRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AssetData 로드에 실패했습니다."));
	}

	bReplicates = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = SphereComponent;
	SphereComponent->SetCollisionProfileName(SMCollisionProfileName::Projectile);
	SphereComponent->InitSphereRadius(1.0f);

	ProjectileFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	ProjectileFXComponent->SetupAttachment(SphereComponent);
	ProjectileFXComponent->SetCollisionProfileName(SMCollisionProfileName::NoCollision);
	ProjectileFXComponent->SetAutoActivate(false);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	ProjectileMovementComponent->SetAutoActivate(false);

	TeamComponent = CreateDefaultSubobject<USMTeamComponent>(TEXT("Team"));

	ProjectileFX.Add(ESMTeam::None, nullptr);
	ProjectileFX.Add(ESMTeam::EDM, nullptr);
	ProjectileFX.Add(ESMTeam::FutureBass, nullptr);

	ProjectileHitFX.Add(ESMTeam::None, nullptr);
	ProjectileHitFX.Add(ESMTeam::EDM, nullptr);
	ProjectileHitFX.Add(ESMTeam::FutureBass, nullptr);

	IgnoreTargetStateTags.AddTag(SMTags::Character::State::Stun);
}

void ASMProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);

	TeamComponent->OnChangeTeam.AddDynamic(this, &ASMProjectile::OnChangeTeamCallback);

	if (!HasAuthority())
	{
		NET_LOG(this, Warning, TEXT("투사체 생성"));
	}
}

void ASMProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ASMProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float DistanceSquaredFromStartLocation = FVector::DistSquared(StartLocation, GetActorLocation());
	if (DistanceSquaredFromStartLocation > FMath::Square(MaxDistance))
	{
		if (HasAuthority())
		{
			MulticastRPCEndLifeTime();
		}
		else
		{
			SetActorHiddenInGame(true);
		}
	}
}

void ASMProjectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor == GetOwner())
	{
		return;
	}

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!TargetASC)
	{
		return;
	}

	// 투사체가 무소속인 경우 무시합니다.
	ISMTeamComponentInterface* SourceTeamComponentInterface = Cast<ISMTeamComponentInterface>(GetOwner());
	if (SourceTeamComponentInterface)
	{
		USMTeamComponent* SourceTeamComponent = SourceTeamComponentInterface->GetTeamComponent();
		if (ensure(SourceTeamComponent))
		{
			if (SourceTeamComponent->GetTeam() == ESMTeam::None)
			{
				return;
			}
		}
	}

	ISMTeamComponentInterface* OtherTeamComponentInterface = Cast<ISMTeamComponentInterface>(OtherActor);
	if (OtherTeamComponentInterface)
	{
		USMTeamComponent* OtherTeamComponent = OtherTeamComponentInterface->GetTeamComponent();
		if (ensure(OtherTeamComponent))
		{
			// 적중 대상이 무소속인 경우 무시합니다.
			const ESMTeam OtherTeam = OtherTeamComponent->GetTeam();
			if (OtherTeam == ESMTeam::None)
			{
				return;
			}

			// 같은 팀의 투사체라면 무시합니다.
			if (TeamComponent->GetTeam() == OtherTeam)
			{
				return;
			}
		}
	}

	if (TargetASC->HasAnyMatchingGameplayTags(IgnoreTargetStateTags))
	{
		return;
	}

	if (HasAuthority())
	{
		if (TargetASC)
		{
			const FGameplayEffectContextHandle GEContext = TargetASC->MakeEffectContext();
			if (GEContext.IsValid())
			{
				TargetASC->BP_ApplyGameplayEffectToSelf(HitGE, 0, GEContext);

				const AActor* TargetActor = TargetASC->GetAvatarActor();
				if (ensure(TargetActor))
				{
					FGameplayCueParameters GCParams;
					GCParams.Location = TargetActor->GetActorLocation();
					GCParams.SourceObject = ProjectileHitFX[TeamComponent->GetTeam()];
					TargetASC->ExecuteGameplayCue(SMTags::GameplayCue::PlayNiagara, GCParams);
				}

				MulticastRPCEndLifeTime();
			}
		}
	}
	else
	{
		SetActorHiddenInGame(true);
	}
}

void ASMProjectile::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (HasAuthority())
	{
		MulticastRPCEndLifeTime();
	}
	else
	{
		SetActorHiddenInGame(true);
	}
}

void ASMProjectile::Launch(AActor* NewOwner, const FVector_NetQuantize10& InStartLocation, const FVector_NetQuantize10& InNormal, float InSpeed, float InMaxDistance)
{
	if (!HasAuthority())
	{
		return;
	}

	SetOwner(NewOwner);

	ISMTeamComponentInterface* OwnerTeamComponentInterface = Cast<ISMTeamComponentInterface>(NewOwner);
	if (OwnerTeamComponentInterface)
	{
		USMTeamComponent* OwnerTeamComponent = OwnerTeamComponentInterface->GetTeamComponent();
		if (ensure(OwnerTeamComponent))
		{
			TeamComponent->SetTeam(OwnerTeamComponent->GetTeam());
		}
	}

	MulticastRPCLaunch(InStartLocation, InNormal, InSpeed, InMaxDistance);
}

void ASMProjectile::MulticastRPCLaunch_Implementation(const FVector_NetQuantize10& InStartLocation, const FVector_NetQuantize10& InNormal, float InSpeed, float InMaxDistance)
{
	StartLocation = InStartLocation;
	MaxDistance = InMaxDistance;
	SetActorLocationAndRotation(InStartLocation, InNormal.Rotation());

	MulticastRPCStartLifeTime();
	ProjectileMovementComponent->Activate(true);
	ProjectileMovementComponent->SetUpdatedComponent(GetRootComponent());
	ProjectileMovementComponent->SetComponentTickEnabled(true);
	ProjectileMovementComponent->Velocity = InNormal * InSpeed;
}

void ASMProjectile::MulticastRPCStartLifeTime_Implementation()
{
	ProjectileFXComponent->ActivateSystem();
	SetActorTickEnabled(true);
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
}

void ASMProjectile::MulticastRPCEndLifeTime_Implementation()
{
	ProjectileFXComponent->DeactivateImmediate();
	ProjectileMovementComponent->Deactivate();
	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);

	(void)OnEndLifeTime.ExecuteIfBound(this);
}

void ASMProjectile::OnChangeTeamCallback()
{
	const ESMTeam Team = TeamComponent->GetTeam();

	if (!HasAuthority())
	{
		ProjectileFXComponent->SetAsset(ProjectileFX[Team]);
	}
}
