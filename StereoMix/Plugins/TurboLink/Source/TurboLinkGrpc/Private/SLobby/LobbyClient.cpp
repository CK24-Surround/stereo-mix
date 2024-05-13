//Generated by TurboLink CodeGenerator, do not edit!
#include "SLobby/LobbyClient.h"
#include "SLobby/LobbyService.h"
#include "LobbyContext.h"
#include "TurboLinkGrpcManager_Private.h"
#include "Templates/SharedPointer.h"

FGrpcContextHandle ULobbyServiceClient::InitCreateRoom()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_LobbyService_CreateRoom>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void ULobbyServiceClient::CreateRoom(FGrpcContextHandle Handle, const FGrpcLobbyCreateRoomRequest& Request, FGrpcMetaData MetaData, float DeadLineSeconds)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextCreateRoom = StaticCastSharedPtr<GrpcContext_LobbyService_CreateRoom>(*context);
		for (const auto& metaDataPair : MetaData.MetaData)
		{
			contextCreateRoom->RpcContext->AddMetadata(
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Key)).Get(),
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Value)).Get()
			);
		}

		if (DeadLineSeconds > 0.f)
		{
			std::chrono::time_point deadLine = std::chrono::system_clock::now() + 
				std::chrono::milliseconds((int32)(1000.f * DeadLineSeconds));
			contextCreateRoom->RpcContext->set_deadline(deadLine);
		}
		contextCreateRoom->Call(Request);
	}
}

FGrpcContextHandle ULobbyServiceClient::InitJoinRoom()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_LobbyService_JoinRoom>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void ULobbyServiceClient::JoinRoom(FGrpcContextHandle Handle, const FGrpcLobbyJoinRoomRequest& Request, FGrpcMetaData MetaData, float DeadLineSeconds)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextJoinRoom = StaticCastSharedPtr<GrpcContext_LobbyService_JoinRoom>(*context);
		for (const auto& metaDataPair : MetaData.MetaData)
		{
			contextJoinRoom->RpcContext->AddMetadata(
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Key)).Get(),
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Value)).Get()
			);
		}

		if (DeadLineSeconds > 0.f)
		{
			std::chrono::time_point deadLine = std::chrono::system_clock::now() + 
				std::chrono::milliseconds((int32)(1000.f * DeadLineSeconds));
			contextJoinRoom->RpcContext->set_deadline(deadLine);
		}
		contextJoinRoom->Call(Request);
	}
}

FGrpcContextHandle ULobbyServiceClient::InitGetRoomList()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_LobbyService_GetRoomList>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void ULobbyServiceClient::GetRoomList(FGrpcContextHandle Handle, const FGrpcLobbyGetRoomListRequest& Request, FGrpcMetaData MetaData, float DeadLineSeconds)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextGetRoomList = StaticCastSharedPtr<GrpcContext_LobbyService_GetRoomList>(*context);
		for (const auto& metaDataPair : MetaData.MetaData)
		{
			contextGetRoomList->RpcContext->AddMetadata(
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Key)).Get(),
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Value)).Get()
			);
		}

		if (DeadLineSeconds > 0.f)
		{
			std::chrono::time_point deadLine = std::chrono::system_clock::now() + 
				std::chrono::milliseconds((int32)(1000.f * DeadLineSeconds));
			contextGetRoomList->RpcContext->set_deadline(deadLine);
		}
		contextGetRoomList->Call(Request);
	}
}

FGrpcContextHandle ULobbyServiceClient::InitUpdateRoomInfo()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_LobbyService_UpdateRoomInfo>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void ULobbyServiceClient::UpdateRoomInfo(FGrpcContextHandle Handle, const FGrpcLobbyUpdateRoomInfoRequest& Request, FGrpcMetaData MetaData, float DeadLineSeconds)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextUpdateRoomInfo = StaticCastSharedPtr<GrpcContext_LobbyService_UpdateRoomInfo>(*context);
		for (const auto& metaDataPair : MetaData.MetaData)
		{
			contextUpdateRoomInfo->RpcContext->AddMetadata(
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Key)).Get(),
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Value)).Get()
			);
		}

		if (DeadLineSeconds > 0.f)
		{
			std::chrono::time_point deadLine = std::chrono::system_clock::now() + 
				std::chrono::milliseconds((int32)(1000.f * DeadLineSeconds));
			contextUpdateRoomInfo->RpcContext->set_deadline(deadLine);
		}
		contextUpdateRoomInfo->Call(Request);
	}
}

void ULobbyServiceClient::TryCancel(FGrpcContextHandle Handle)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		(*context)->TryCancel();
	}
}

void ULobbyServiceClient::Shutdown()
{
	OnCreateRoomResponse.Clear();
	OnJoinRoomResponse.Clear();
	OnGetRoomListResponse.Clear();
	OnUpdateRoomInfoResponse.Clear();
	Super::Shutdown();
}

