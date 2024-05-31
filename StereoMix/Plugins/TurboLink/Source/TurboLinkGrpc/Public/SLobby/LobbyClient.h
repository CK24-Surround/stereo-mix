//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "TurboLinkGrpcClient.h"
#include "SLobby/LobbyMessage.h"
#include "LobbyClient.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceCreateRoomResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyCreateRoomResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceQuickMatchResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyQuickMatchResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceJoinRoomResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyJoinRoomResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceJoinRoomWithCodeResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyJoinRoomWithCodeResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceGetRoomListResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyGetRoomListResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceUpdateRoomStateResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyUpdateRoomStateResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceUpdateRoomConfigResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyUpdateRoomConfigResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceChangeRoomPasswordResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyChangeRoomPasswordResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceChangeRoomOwnerResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyChangeRoomOwnerResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceDeleteRoomResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyDeleteRoomResponse&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLobbyServiceListenRoomUpdatesResponse, FGrpcContextHandle, Handle, const FGrpcResult&, GrpcResult, const FGrpcLobbyRoom&, Response);

UCLASS(ClassGroup = TurboLink, BlueprintType)
class TURBOLINKGRPC_API ULobbyServiceClient : public UGrpcClient
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceCreateRoomResponse OnCreateRoomResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceQuickMatchResponse OnQuickMatchResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceJoinRoomResponse OnJoinRoomResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceJoinRoomWithCodeResponse OnJoinRoomWithCodeResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceGetRoomListResponse OnGetRoomListResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceUpdateRoomStateResponse OnUpdateRoomStateResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceUpdateRoomConfigResponse OnUpdateRoomConfigResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceChangeRoomPasswordResponse OnChangeRoomPasswordResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceChangeRoomOwnerResponse OnChangeRoomOwnerResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceDeleteRoomResponse OnDeleteRoomResponse;

	UPROPERTY(BlueprintAssignable)
	FOnLobbyServiceListenRoomUpdatesResponse OnListenRoomUpdatesResponse;

public:
	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitCreateRoom();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void CreateRoom(FGrpcContextHandle Handle, const FGrpcLobbyCreateRoomRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitQuickMatch();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void QuickMatch(FGrpcContextHandle Handle, const FGrpcLobbyQuickMatchRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitJoinRoom();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void JoinRoom(FGrpcContextHandle Handle, const FGrpcLobbyJoinRoomRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitJoinRoomWithCode();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void JoinRoomWithCode(FGrpcContextHandle Handle, const FGrpcLobbyJoinRoomWithCodeRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitGetRoomList();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void GetRoomList(FGrpcContextHandle Handle, const FGrpcLobbyGetRoomListRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitUpdateRoomState();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void UpdateRoomState(FGrpcContextHandle Handle, const FGrpcLobbyUpdateRoomStateRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitUpdateRoomConfig();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void UpdateRoomConfig(FGrpcContextHandle Handle, const FGrpcLobbyUpdateRoomConfigRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitChangeRoomPassword();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void ChangeRoomPassword(FGrpcContextHandle Handle, const FGrpcLobbyChangeRoomPasswordRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitChangeRoomOwner();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void ChangeRoomOwner(FGrpcContextHandle Handle, const FGrpcLobbyChangeRoomOwnerRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitDeleteRoom();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void DeleteRoom(FGrpcContextHandle Handle, const FGrpcLobbyDeleteRoomRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	FGrpcContextHandle InitListenRoomUpdates();

	UFUNCTION(BlueprintCallable, Category = TurboLink, meta = (AdvancedDisplay = 2))
	void ListenRoomUpdates(FGrpcContextHandle Handle, const FGrpcLobbyListenRoomUpdatesRequest& Request, FGrpcMetaData MetaData = FGrpcMetaData(), float DeadLineSeconds = 0.f);

public:
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = TurboLink)
	void TryCancel(FGrpcContextHandle Handle);
};

