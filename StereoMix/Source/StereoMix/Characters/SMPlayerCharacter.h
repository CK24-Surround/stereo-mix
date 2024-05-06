// Copyright Surround, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "SMCharacter.h"
#include "Interfaces/SMCatchableInterface.h"
#include "Interfaces/SMDamageInterface.h"
#include "Interfaces/SMTeamInterface.h"
#include "SMPlayerCharacter.generated.h"

class UWidgetComponent;
DECLARE_MULTICAST_DELEGATE(FOnLandedSignature);

class USMTeamComponent;
class USMAbilitySystemComponent;
class UGameplayEffect;
class UGameplayAbility;
class ASMPlayerController;
struct FInputActionValue;
class USphereComponent;
class UCameraComponent;
class USpringArmComponent;
class USMDesignData;
class USMWidgetComponent;

UENUM(BlueprintType)
enum class EActiveAbility : uint8
{
	None,
	Launch,
	Catch,
	Smash
};

UCLASS()
class STEREOMIX_API ASMPlayerCharacter : public ASMCharacter, public IAbilitySystemInterface, public ISMTeamInterface, public ISMCatchInteractionInterface, public ISMDamageInterface
{
	GENERATED_BODY()

public:
	ASMPlayerCharacter();

public:
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void OnRep_Controller() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void OnRep_PlayerState() override;

protected:
	// 카메라 관련 데이터를 초기화합니다.
	void InitCamera();

// ~Component Section
public:
	FORCEINLINE virtual USMTeamComponent* GetTeamComponent() const override { return TeamComponent; }

	virtual ESMTeam GetTeam() const override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Component|HitBox")
	TObjectPtr<USphereComponent> HitBox;

	UPROPERTY(VisibleAnywhere, Category = "Component|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Component|Camera")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, Category = "Component|Team")
	TObjectPtr<USMTeamComponent> TeamComponent;

	UPROPERTY(VisibleAnywhere, Category = "UI|PlayerState")
	TObjectPtr<USMWidgetComponent> CharacterStateWidgetComponent;
// ~Component Section

// ~Data Section
protected:
	UPROPERTY()
	TObjectPtr<const USMDesignData> DesignData;
// ~Data Section

// ~Caching Section
protected:
	UPROPERTY()
	TObjectPtr<ASMPlayerController> CachedStereoMixPlayerController;
// ~Caching Section

// ~GAS Section
protected:
	// GAS에서 사용할 액티브 GA들을 바인드합니다.
	void SetupGASInputComponent();

	// ASC를 초기화하고 기본 GA들을 부여합니다.
	void InitASC();

	void GiveDefaultAbilities();

	// 액티브 GA와 바인드 된 함수입니다. 입력할때 트리거됩니다.
	void GAInputPressed(EActiveAbility InInputID);

	// 액티브 GA와 바인드 된 함수입니다. 놓을때 트리거됩니다.
	void GAInputReleased(EActiveAbility InInputID);

protected:
	UPROPERTY()
	TWeakObjectPtr<USMAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere, Category = "GAS|GA")
	TMap<EActiveAbility, TSubclassOf<UGameplayAbility>> DefaultActiveAbilities;

	UPROPERTY(EditAnywhere, Category = "GAS|GA")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditAnywhere, Category = "GAS|GE")
	TSubclassOf<UGameplayEffect> ForInitGE;

	UPROPERTY(EditAnywhere, Category = "GAS|Tag")
	FGameplayTagContainer LockAimTags;

	UPROPERTY(EditAnywhere, Category = "GAS|Tag")
	FGameplayTagContainer LockMovementTags;
// ~GAS Section

// ~Movement Section
public:
	/** 현재 마우스커서가 위치한 곳의 좌표를 반환합니다. 기본값은 플레이어 캐릭터의 중심을 기준으로 하는 평면으로 계산됩니다. */
	FVector GetCursorTargetingPoint(bool bIsZeroBasis = false);

	void SetMaxWalkSpeed(float InSpeed);

	/** 땅에 박히는 것을 방지하기 위한 코드입니다. 서버에서 호출되어야합니다. */
	UFUNCTION(Server, Reliable)
	void ServerRPCPreventGroundEmbedding();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastRPCSetLocation(const FVector_NetQuantize10 InLocation);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastRPCSetYawRotation(float InYaw);

	/** 어태치할 경우 루트컴포넌트를 기준으로 어태치 되다보니 메시와는 어긋나게됩니다. 이때 오프셋을 맞춰주는 함수입니다.*/
	UFUNCTION(NetMulticast, Reliable)
	void MulticastRPCApplyAttachOffset();

public:
	FOnLandedSignature OnLanded;

protected:
	void Move(const FInputActionValue& InputActionValue);

	void FocusToCursor();

	UFUNCTION()
	void OnRep_MaxWalkSpeed();

	void OnChangeMoveSpeed(const FOnAttributeChangeData& OnAttributeChangeData);

	virtual void Landed(const FHitResult& Hit) override;

protected:
	// 이동속도 리플리케이션을 위한 변수로 직접 수정되어서는 안됩니다. SetMaxWalkSpeed를 사용해 수정해주세요.
	UPROPERTY(ReplicatedUsing = "OnRep_MaxWalkSpeed")
	float MaxWalkSpeed;
// ~Movement Section

// ~Widget Section
public:
	/** 캐릭터 상태 위젯의 가시성을 조절합니다. */
	UFUNCTION(NetMulticast, Unreliable)
	void SetCharacterStateVisibility(bool bEnable);
// ~Widget Section

// ~State Section
public:
	void SetEnableCollision(bool bInEnableCollision);

	void SetUseControllerRotation(bool bInUseControllerRotation);

	void SetEnableMovement(bool bInEnableMovementMode);

protected:
	UFUNCTION()
	void OnRep_EnableCollision();

	UFUNCTION()
	void OnRep_UseControllerRotation();

	UFUNCTION()
	void OnRep_EnableMovement();

protected:
	UPROPERTY(ReplicatedUsing = "OnRep_EnableCollision")
	uint32 bEnableCollision:1 = true;

	UPROPERTY(ReplicatedUsing = "OnRep_UseControllerRotation")
	uint32 bUseControllerRotation:1 = true;

	UPROPERTY(ReplicatedUsing = "OnRep_EnableMovement")
	uint32 bEnableMovement:1 = true;
// ~State Section

// ~Catch Section
public:
	FORCEINLINE AActor* GetMyCaughtActor() { return MyCaughtActor.Get(); }

	FORCEINLINE void SetMyCaughtActor(AActor* InMyCaughtActor) { MyCaughtActor = InMyCaughtActor; }

	FORCEINLINE virtual AActor* GetActorCatchingMe() override { return CatchingMeActor.Get(); }

	FORCEINLINE virtual void SetActorCatchingMe(AActor* InCatchingMeActor) override { CatchingMeActor = InCatchingMeActor; }

	virtual bool OnCaught(AActor* TargetActor) override;

	virtual bool OnCaughtReleased(AActor* TargetActor) override;

	virtual bool IsCatchble(AActor* TargetActor) override;

protected:
	TWeakObjectPtr<AActor> MyCaughtActor;

	TWeakObjectPtr<AActor> CatchingMeActor;
	
	/** 한 캐릭터에게 여러번 잡히지 않도록 자신을 잡았던 캐릭터들을 담아둡니다. 서버에서만 유효합니다. */
	TArray<TWeakObjectPtr<ASMPlayerCharacter>> CapturedCharcters;

// TODO: 제거 예정
protected:
	// 자신이 잡고 있는 폰을 의미합니다.
	UPROPERTY(Replicated)
	TWeakObjectPtr<ASMPlayerCharacter> CatchCharacter;

	// 자신이 잡혀 있는 폰을 의미합니다.
	UPROPERTY(Replicated)
	TWeakObjectPtr<ASMPlayerCharacter> CaughtCharacter;
// TODO: 제거 예정
// ~Catch Section

// ~Damage Section
public:
	FORCEINLINE virtual AActor* GetLastAttackInstigator() override { return LastAttackInstigator.Get(); };

	FORCEINLINE virtual void SetLastAttackInstigator(AActor* NewStunInstigator) override { LastAttackInstigator = NewStunInstigator; }

protected:
	UPROPERTY(Replicated)
	TWeakObjectPtr<AActor> LastAttackInstigator;
// ~Damage Section

protected:
	UFUNCTION()
	void OnTeamChangeCallback();
};
