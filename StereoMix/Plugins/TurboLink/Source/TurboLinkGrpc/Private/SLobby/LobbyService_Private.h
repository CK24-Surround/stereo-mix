//Generated by TurboLink CodeGenerator, do not edit!
#pragma once

#include "SLobby/LobbyService.h"
#include "TurboLinkGrpcManager_Private.h"
#include "lobby.grpc.pb.h"
#include "LobbyService_Private.generated.h"

class ULobbyService::Private
{
public:
	std::shared_ptr<UTurboLinkGrpcManager::Private::ServiceChannel> Channel;
	std::unique_ptr<::lobby::LobbyService::Stub> Stub;
};


UCLASS()
class ULobbyServiceCreateRoomLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyCreateRoomResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FCreateRoomResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceQuickMatchLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyQuickMatchResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FQuickMatchResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceJoinRoomLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyJoinRoomResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FJoinRoomResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceJoinRoomWithCodeLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyJoinRoomWithCodeResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FJoinRoomWithCodeResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceGetRoomListLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyGetRoomListResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FGetRoomListResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceUpdateRoomStateLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomStateResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FUpdateRoomStateResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceUpdateRoomConfigLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomConfigResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FUpdateRoomConfigResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceChangeRoomPasswordLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyChangeRoomPasswordResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FChangeRoomPasswordResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceChangeRoomOwnerLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyChangeRoomOwnerResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FChangeRoomOwnerResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceDeleteRoomLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyDeleteRoomResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FDeleteRoomResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceListenRoomUpdatesLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyRoom& Response);
	UFUNCTION()
	void OnContextStateChanged(FGrpcContextHandle Handle, EGrpcContextState NewState);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FListenRoomUpdatesResponseLambda ResponseLambda;
	ULobbyService::FListenRoomUpdatesFinishLambda FinishLambda;
};

