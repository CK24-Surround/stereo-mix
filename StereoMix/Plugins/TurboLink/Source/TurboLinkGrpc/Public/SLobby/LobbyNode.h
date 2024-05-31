//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TurboLinkGrpcClient.h"
#include "LobbyMessage.h"
#include "LobbyNode.generated.h"

class ULobbyService;
class ULobbyServiceClient;

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceCreateRoom : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceCreateRoomDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyCreateRoomResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService CreateRoom",
		AdvancedDisplay = 2))
	static UCallLobbyServiceCreateRoom* CreateRoom(UObject* WorldContextObject, const FGrpcLobbyCreateRoomRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceCreateRoomDelegate OnCreateRoomResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceCreateRoomDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyCreateRoomRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyCreateRoomResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceQuickMatch : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceQuickMatchDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyQuickMatchResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService QuickMatch",
		AdvancedDisplay = 2))
	static UCallLobbyServiceQuickMatch* QuickMatch(UObject* WorldContextObject, const FGrpcLobbyQuickMatchRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceQuickMatchDelegate OnQuickMatchResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceQuickMatchDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyQuickMatchRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyQuickMatchResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceJoinRoom : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceJoinRoomDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyJoinRoomResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService JoinRoom",
		AdvancedDisplay = 2))
	static UCallLobbyServiceJoinRoom* JoinRoom(UObject* WorldContextObject, const FGrpcLobbyJoinRoomRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceJoinRoomDelegate OnJoinRoomResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceJoinRoomDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyJoinRoomRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyJoinRoomResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceJoinRoomWithCode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceJoinRoomWithCodeDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyJoinRoomWithCodeResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService JoinRoomWithCode",
		AdvancedDisplay = 2))
	static UCallLobbyServiceJoinRoomWithCode* JoinRoomWithCode(UObject* WorldContextObject, const FGrpcLobbyJoinRoomWithCodeRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceJoinRoomWithCodeDelegate OnJoinRoomWithCodeResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceJoinRoomWithCodeDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyJoinRoomWithCodeRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyJoinRoomWithCodeResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceGetRoomList : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceGetRoomListDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyGetRoomListResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService GetRoomList",
		AdvancedDisplay = 2))
	static UCallLobbyServiceGetRoomList* GetRoomList(UObject* WorldContextObject, const FGrpcLobbyGetRoomListRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceGetRoomListDelegate OnGetRoomListResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceGetRoomListDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyGetRoomListRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyGetRoomListResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceUpdateRoomState : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceUpdateRoomStateDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyUpdateRoomStateResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService UpdateRoomState",
		AdvancedDisplay = 2))
	static UCallLobbyServiceUpdateRoomState* UpdateRoomState(UObject* WorldContextObject, const FGrpcLobbyUpdateRoomStateRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceUpdateRoomStateDelegate OnUpdateRoomStateResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceUpdateRoomStateDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyUpdateRoomStateRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomStateResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceUpdateRoomConfig : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceUpdateRoomConfigDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyUpdateRoomConfigResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService UpdateRoomConfig",
		AdvancedDisplay = 2))
	static UCallLobbyServiceUpdateRoomConfig* UpdateRoomConfig(UObject* WorldContextObject, const FGrpcLobbyUpdateRoomConfigRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceUpdateRoomConfigDelegate OnUpdateRoomConfigResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceUpdateRoomConfigDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyUpdateRoomConfigRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomConfigResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceChangeRoomPassword : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceChangeRoomPasswordDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyChangeRoomPasswordResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService ChangeRoomPassword",
		AdvancedDisplay = 2))
	static UCallLobbyServiceChangeRoomPassword* ChangeRoomPassword(UObject* WorldContextObject, const FGrpcLobbyChangeRoomPasswordRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceChangeRoomPasswordDelegate OnChangeRoomPasswordResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceChangeRoomPasswordDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyChangeRoomPasswordRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyChangeRoomPasswordResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceChangeRoomOwner : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceChangeRoomOwnerDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyChangeRoomOwnerResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService ChangeRoomOwner",
		AdvancedDisplay = 2))
	static UCallLobbyServiceChangeRoomOwner* ChangeRoomOwner(UObject* WorldContextObject, const FGrpcLobbyChangeRoomOwnerRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceChangeRoomOwnerDelegate OnChangeRoomOwnerResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceChangeRoomOwnerDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyChangeRoomOwnerRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyChangeRoomOwnerResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceDeleteRoom : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceDeleteRoomDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyDeleteRoomResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService DeleteRoom",
		AdvancedDisplay = 2))
	static UCallLobbyServiceDeleteRoom* DeleteRoom(UObject* WorldContextObject, const FGrpcLobbyDeleteRoomRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceDeleteRoomDelegate OnDeleteRoomResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceDeleteRoomDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyDeleteRoomRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyDeleteRoomResponse& Response);

	void Shutdown();
};

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallLobbyServiceListenRoomUpdates : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLobbyServiceListenRoomUpdatesDelegate, const FGrpcResult&, GrpcResult, const FGrpcLobbyRoom&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|LobbyService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call LobbyService ListenRoomUpdates",
		AdvancedDisplay = 2))
	static UCallLobbyServiceListenRoomUpdates* ListenRoomUpdates(UObject* WorldContextObject, const FGrpcLobbyListenRoomUpdatesRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceListenRoomUpdatesDelegate OnListenRoomUpdatesResponse;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceListenRoomUpdatesDelegate OnFinished;

	UPROPERTY(BlueprintAssignable)
	FLobbyServiceListenRoomUpdatesDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	ULobbyService* LobbyService;
	
	UPROPERTY()
	ULobbyServiceClient* LobbyServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcLobbyListenRoomUpdatesRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyRoom& Response);

	void Shutdown();
};
