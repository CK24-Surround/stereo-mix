//Generated by TurboLink CodeGenerator, do not edit!
#include "LobbyService_Private.h"

void ULobbyServiceCreateRoomLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyCreateRoomResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnCreateRoomResponse.RemoveDynamic(this, &ULobbyServiceCreateRoomLambdaWrapper::OnResponse);
}

void ULobbyServiceQuickMatchLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyQuickMatchResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnQuickMatchResponse.RemoveDynamic(this, &ULobbyServiceQuickMatchLambdaWrapper::OnResponse);
}

void ULobbyServiceJoinRoomLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyJoinRoomResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnJoinRoomResponse.RemoveDynamic(this, &ULobbyServiceJoinRoomLambdaWrapper::OnResponse);
}

void ULobbyServiceJoinRoomWithCodeLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyJoinRoomWithCodeResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnJoinRoomWithCodeResponse.RemoveDynamic(this, &ULobbyServiceJoinRoomWithCodeLambdaWrapper::OnResponse);
}

void ULobbyServiceGetRoomListLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyGetRoomListResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnGetRoomListResponse.RemoveDynamic(this, &ULobbyServiceGetRoomListLambdaWrapper::OnResponse);
}

void ULobbyServiceUpdateRoomStateLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomStateResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnUpdateRoomStateResponse.RemoveDynamic(this, &ULobbyServiceUpdateRoomStateLambdaWrapper::OnResponse);
}

void ULobbyServiceUpdateRoomConfigLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyUpdateRoomConfigResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnUpdateRoomConfigResponse.RemoveDynamic(this, &ULobbyServiceUpdateRoomConfigLambdaWrapper::OnResponse);
}

void ULobbyServiceChangeRoomPasswordLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyChangeRoomPasswordResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnChangeRoomPasswordResponse.RemoveDynamic(this, &ULobbyServiceChangeRoomPasswordLambdaWrapper::OnResponse);
}

void ULobbyServiceChangeRoomOwnerLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyChangeRoomOwnerResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnChangeRoomOwnerResponse.RemoveDynamic(this, &ULobbyServiceChangeRoomOwnerLambdaWrapper::OnResponse);
}

void ULobbyServiceDeleteRoomLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyDeleteRoomResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnDeleteRoomResponse.RemoveDynamic(this, &ULobbyServiceDeleteRoomLambdaWrapper::OnResponse);
}

void ULobbyServiceListenRoomUpdatesLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcLobbyRoom& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
}

void ULobbyServiceListenRoomUpdatesLambdaWrapper::OnContextStateChanged(FGrpcContextHandle _Handle, EGrpcContextState NewState)
{
	if (_Handle != this->Handle) return;
	if (NewState == EGrpcContextState::Done)
	{
		FinishLambda();

		InnerClient->OnListenRoomUpdatesResponse.RemoveDynamic(this, &ULobbyServiceListenRoomUpdatesLambdaWrapper::OnResponse);
		InnerClient->OnContextStateChange.RemoveDynamic(this, &ULobbyServiceListenRoomUpdatesLambdaWrapper::OnContextStateChanged);
	}
}

