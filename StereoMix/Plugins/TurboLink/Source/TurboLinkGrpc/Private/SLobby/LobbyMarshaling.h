//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "SLobby/LobbyMessage.h"
#include "TurboLinkGrpcContext.h"
#include "lobby.grpc.pb.h"

void GRPC_TO_TURBOLINK(const ::lobby::RoomPreview* in, FGrpcLobbyRoomPreview* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomPreview* in, ::lobby::RoomPreview* out);

void GRPC_TO_TURBOLINK(const ::lobby::CreateRoomRequest* in, FGrpcLobbyCreateRoomRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyCreateRoomRequest* in, ::lobby::CreateRoomRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::CreateRoomResponse* in, FGrpcLobbyCreateRoomResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyCreateRoomResponse* in, ::lobby::CreateRoomResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::JoinRoomRequest* in, FGrpcLobbyJoinRoomRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyJoinRoomRequest* in, ::lobby::JoinRoomRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::JoinRoomResponse* in, FGrpcLobbyJoinRoomResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyJoinRoomResponse* in, ::lobby::JoinRoomResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::GetRoomListRequest* in, FGrpcLobbyGetRoomListRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyGetRoomListRequest* in, ::lobby::GetRoomListRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::GetRoomListResponse* in, FGrpcLobbyGetRoomListResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyGetRoomListResponse* in, ::lobby::GetRoomListResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::RoomConnectionInfo* in, FGrpcLobbyRoomConnectionInfo* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomConnectionInfo* in, ::lobby::RoomConnectionInfo* out);

void GRPC_TO_TURBOLINK(const ::lobby::RoomPlayer* in, FGrpcLobbyRoomPlayer* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomPlayer* in, ::lobby::RoomPlayer* out);

void GRPC_TO_TURBOLINK(const ::lobby::Room* in, FGrpcLobbyRoom* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyRoom* in, ::lobby::Room* out);

void GRPC_TO_TURBOLINK(const ::lobby::RoomConfig* in, FGrpcLobbyRoomConfig* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomConfig* in, ::lobby::RoomConfig* out);

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomStateRequest* in, FGrpcLobbyUpdateRoomStateRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomStateRequest* in, ::lobby::UpdateRoomStateRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomStateResponse* in, FGrpcLobbyUpdateRoomStateResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomStateResponse* in, ::lobby::UpdateRoomStateResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomConfigRequest* in, FGrpcLobbyUpdateRoomConfigRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomConfigRequest* in, ::lobby::UpdateRoomConfigRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomConfigResponse* in, FGrpcLobbyUpdateRoomConfigResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomConfigResponse* in, ::lobby::UpdateRoomConfigResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::UpdatePlayerStateRequest* in, FGrpcLobbyUpdatePlayerStateRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdatePlayerStateRequest* in, ::lobby::UpdatePlayerStateRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::UpdatePlayerStateResponse* in, FGrpcLobbyUpdatePlayerStateResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdatePlayerStateResponse* in, ::lobby::UpdatePlayerStateResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomPasswordRequest* in, FGrpcLobbyChangeRoomPasswordRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomPasswordRequest* in, ::lobby::ChangeRoomPasswordRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomPasswordResponse* in, FGrpcLobbyChangeRoomPasswordResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomPasswordResponse* in, ::lobby::ChangeRoomPasswordResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomOwnerRequest* in, FGrpcLobbyChangeRoomOwnerRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomOwnerRequest* in, ::lobby::ChangeRoomOwnerRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomOwnerResponse* in, FGrpcLobbyChangeRoomOwnerResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomOwnerResponse* in, ::lobby::ChangeRoomOwnerResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::DeleteRoomRequest* in, FGrpcLobbyDeleteRoomRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyDeleteRoomRequest* in, ::lobby::DeleteRoomRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::DeleteRoomResponse* in, FGrpcLobbyDeleteRoomResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyDeleteRoomResponse* in, ::lobby::DeleteRoomResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::ListenRoomConfigUpdatesRequest* in, FGrpcLobbyListenRoomConfigUpdatesRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyListenRoomConfigUpdatesRequest* in, ::lobby::ListenRoomConfigUpdatesRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::ListenRoomConfigUpdatesResponse* in, FGrpcLobbyListenRoomConfigUpdatesResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyListenRoomConfigUpdatesResponse* in, ::lobby::ListenRoomConfigUpdatesResponse* out);

void GRPC_TO_TURBOLINK(const ::lobby::ListenPlayerListUpdatesRequest* in, FGrpcLobbyListenPlayerListUpdatesRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyListenPlayerListUpdatesRequest* in, ::lobby::ListenPlayerListUpdatesRequest* out);

void GRPC_TO_TURBOLINK(const ::lobby::ListenPlayerListUpdatesResponse* in, FGrpcLobbyListenPlayerListUpdatesResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcLobbyListenPlayerListUpdatesResponse* in, ::lobby::ListenPlayerListUpdatesResponse* out);

typedef grpc::ClientAsyncResponseReader<::lobby::CreateRoomResponse> LobbyService_CreateRoom_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::JoinRoomResponse> LobbyService_JoinRoom_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::GetRoomListResponse> LobbyService_GetRoomList_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::UpdateRoomStateResponse> LobbyService_UpdateRoomState_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::UpdateRoomConfigResponse> LobbyService_UpdateRoomConfig_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::UpdatePlayerStateResponse> LobbyService_UpdatePlayerState_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::ChangeRoomPasswordResponse> LobbyService_ChangeRoomPassword_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::ChangeRoomOwnerResponse> LobbyService_ChangeRoomOwner_ReaderWriter;
typedef grpc::ClientAsyncResponseReader<::lobby::DeleteRoomResponse> LobbyService_DeleteRoom_ReaderWriter;
typedef grpc::ClientAsyncReader<::lobby::ListenRoomConfigUpdatesResponse> LobbyService_UpdateRoomConfigStream_ReaderWriter;
typedef grpc::ClientAsyncReader<::lobby::ListenPlayerListUpdatesResponse> LobbyService_UpdatePlayerListStream_ReaderWriter;
