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
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyConnectionInfo& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FCreateRoomResponseLambda ResponseLambda;
};

UCLASS()
class ULobbyServiceJoinRoomLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyConnectionInfo& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FJoinRoomResponseLambda ResponseLambda;
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
class ULobbyServiceUpdateRoomInfoLambdaWrapper : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	ULobbyServiceClient* InnerClient;

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomInfoResponse& Response);
public:
	FGrpcContextHandle Handle;
	ULobbyService::FUpdateRoomInfoResponseLambda ResponseLambda;
};

