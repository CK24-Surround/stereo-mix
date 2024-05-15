//Generated by TurboLink CodeGenerator, do not edit!
#include "LobbyMarshaling.h"
#include "SGoogleProtobuf/TimestampMarshaling.h"

void GRPC_TO_TURBOLINK(const ::lobby::RoomPreview* in, FGrpcLobbyRoomPreview* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    {
        FGrpcLobbyRoomConfig field;
        GRPC_TO_TURBOLINK(&(in->config()), &field);
        out->Config = MakeShareable(new FGrpcLobbyRoomConfig(field));
    }
    out->CurrentPlayers=in->current_players();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomPreview* in, ::lobby::RoomPreview* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    TURBOLINK_TO_GRPC(in->Config.Get(), out->mutable_config());
    out->set_current_players(in->CurrentPlayers);
}

void GRPC_TO_TURBOLINK(const ::lobby::CreateRoomRequest* in, FGrpcLobbyCreateRoomRequest* out)
{
    {
        FGrpcLobbyRoomConfig field;
        GRPC_TO_TURBOLINK(&(in->config()), &field);
        out->Config = MakeShareable(new FGrpcLobbyRoomConfig(field));
    }
    out->Password=StringCast<TCHAR>((const UTF8CHAR*)(in->password().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyCreateRoomRequest* in, ::lobby::CreateRoomRequest* out)
{
    TURBOLINK_TO_GRPC(in->Config.Get(), out->mutable_config());
    out->set_password((const char*)StringCast<UTF8CHAR>(*(in->Password)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::CreateRoomResponse* in, FGrpcLobbyCreateRoomResponse* out)
{
    {
        FGrpcLobbyRoomConnectionInfo field;
        GRPC_TO_TURBOLINK(&(in->connection()), &field);
        out->Connection = MakeShareable(new FGrpcLobbyRoomConnectionInfo(field));
    }
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyCreateRoomResponse* in, ::lobby::CreateRoomResponse* out)
{
    TURBOLINK_TO_GRPC(in->Connection.Get(), out->mutable_connection());
}

void GRPC_TO_TURBOLINK(const ::lobby::JoinRoomRequest* in, FGrpcLobbyJoinRoomRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    out->Password=StringCast<TCHAR>((const UTF8CHAR*)(in->password().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyJoinRoomRequest* in, ::lobby::JoinRoomRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    out->set_password((const char*)StringCast<UTF8CHAR>(*(in->Password)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::JoinRoomResponse* in, FGrpcLobbyJoinRoomResponse* out)
{
    {
        FGrpcLobbyRoomConnectionInfo field;
        GRPC_TO_TURBOLINK(&(in->connection()), &field);
        out->Connection = MakeShareable(new FGrpcLobbyRoomConnectionInfo(field));
    }
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyJoinRoomResponse* in, ::lobby::JoinRoomResponse* out)
{
    TURBOLINK_TO_GRPC(in->Connection.Get(), out->mutable_connection());
}

void GRPC_TO_TURBOLINK(const ::lobby::GetRoomListRequest* in, FGrpcLobbyGetRoomListRequest* out)
{
    out->Visibility=StaticCast<EGrpcLobbyRoomVisibility>(in->visibility());
    out->Mode=StaticCast<EGrpcLobbyGameMode>(in->mode());
    out->Map=StaticCast<EGrpcLobbyGameMap>(in->map());
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyGetRoomListRequest* in, ::lobby::GetRoomListRequest* out)
{
    out->set_visibility(::lobby::RoomVisibility(static_cast<uint8>(in->Visibility)));
    out->set_mode(::lobby::GameMode(static_cast<uint8>(in->Mode)));
    out->set_map(::lobby::GameMap(static_cast<uint8>(in->Map)));
}

void GRPC_TO_TURBOLINK(const ::lobby::GetRoomListResponse* in, FGrpcLobbyGetRoomListResponse* out)
{
    out->Rooms.Empty();
    for (int i=0; i<in->rooms_size(); ++i) {
        GRPC_TO_TURBOLINK(&(in->rooms(i)), &(out->Rooms.AddZeroed_GetRef()));
    }
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyGetRoomListResponse* in, ::lobby::GetRoomListResponse* out)
{
    for(const auto& value : in->Rooms) {
        TURBOLINK_TO_GRPC(&value, out->add_rooms());
    } 
}

void GRPC_TO_TURBOLINK(const ::lobby::RoomConnectionInfo* in, FGrpcLobbyRoomConnectionInfo* out)
{
    out->Host=StringCast<TCHAR>((const UTF8CHAR*)(in->host().c_str())).Get();
    out->Port=in->port();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomConnectionInfo* in, ::lobby::RoomConnectionInfo* out)
{
    out->set_host((const char*)StringCast<UTF8CHAR>(*(in->Host)).Get());
    out->set_port(in->Port);
}

void GRPC_TO_TURBOLINK(const ::lobby::RoomPlayer* in, FGrpcLobbyRoomPlayer* out)
{
    out->UserId=StringCast<TCHAR>((const UTF8CHAR*)(in->user_id().c_str())).Get();
    out->UserName=StringCast<TCHAR>((const UTF8CHAR*)(in->user_name().c_str())).Get();
    out->State=StaticCast<EGrpcLobbyPlayerState>(in->state());
    out->IsOwner=in->is_owner();
    GRPC_TO_TURBOLINK(&(in->joined_at()), &(out->JoinedAt));
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomPlayer* in, ::lobby::RoomPlayer* out)
{
    out->set_user_id((const char*)StringCast<UTF8CHAR>(*(in->UserId)).Get());
    out->set_user_name((const char*)StringCast<UTF8CHAR>(*(in->UserName)).Get());
    out->set_state(::lobby::PlayerState(static_cast<uint8>(in->State)));
    out->set_is_owner(in->IsOwner);
    TURBOLINK_TO_GRPC(&(in->JoinedAt), out->mutable_joined_at());
}

void GRPC_TO_TURBOLINK(const ::lobby::Room* in, FGrpcLobbyRoom* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    out->PasswordEncrypted=StringCast<TCHAR>((const UTF8CHAR*)(in->password_encrypted().c_str())).Get();
    out->State=StaticCast<EGrpcLobbyRoomState>(in->state());
    out->OwnerId=StringCast<TCHAR>((const UTF8CHAR*)(in->owner_id().c_str())).Get();
    {
        FGrpcLobbyRoomConfig field;
        GRPC_TO_TURBOLINK(&(in->config()), &field);
        out->Config = MakeShareable(new FGrpcLobbyRoomConfig(field));
    }
    out->Players.Empty();
    for (int i=0; i<in->players_size(); ++i) {
        GRPC_TO_TURBOLINK(&(in->players(i)), &(out->Players.AddZeroed_GetRef()));
    }
    out->PlayerCount=in->player_count();
    GRPC_TO_TURBOLINK(&(in->connection()), &(out->Connection));
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyRoom* in, ::lobby::Room* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    out->set_password_encrypted((const char*)StringCast<UTF8CHAR>(*(in->PasswordEncrypted)).Get());
    out->set_state(::lobby::RoomState(static_cast<uint8>(in->State)));
    out->set_owner_id((const char*)StringCast<UTF8CHAR>(*(in->OwnerId)).Get());
    TURBOLINK_TO_GRPC(in->Config.Get(), out->mutable_config());
    for(const auto& value : in->Players) {
        TURBOLINK_TO_GRPC(&value, out->add_players());
    } 
    out->set_player_count(in->PlayerCount);
    TURBOLINK_TO_GRPC(&(in->Connection), out->mutable_connection());
}

void GRPC_TO_TURBOLINK(const ::lobby::RoomConfig* in, FGrpcLobbyRoomConfig* out)
{
    out->RoomName=StringCast<TCHAR>((const UTF8CHAR*)(in->room_name().c_str())).Get();
    out->Visibility=StaticCast<EGrpcLobbyRoomVisibility>(in->visibility());
    out->Mode=StaticCast<EGrpcLobbyGameMode>(in->mode());
    out->Map=StaticCast<EGrpcLobbyGameMap>(in->map());
    out->MaxPlayers=in->max_players();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyRoomConfig* in, ::lobby::RoomConfig* out)
{
    out->set_room_name((const char*)StringCast<UTF8CHAR>(*(in->RoomName)).Get());
    out->set_visibility(::lobby::RoomVisibility(static_cast<uint8>(in->Visibility)));
    out->set_mode(::lobby::GameMode(static_cast<uint8>(in->Mode)));
    out->set_map(::lobby::GameMap(static_cast<uint8>(in->Map)));
    out->set_max_players(in->MaxPlayers);
}

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomStateRequest* in, FGrpcLobbyUpdateRoomStateRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    out->State=StaticCast<EGrpcLobbyRoomState>(in->state());
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomStateRequest* in, ::lobby::UpdateRoomStateRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    out->set_state(::lobby::RoomState(static_cast<uint8>(in->State)));
}

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomStateResponse* in, FGrpcLobbyUpdateRoomStateResponse* out)
{
    out->UpdatedState=StaticCast<EGrpcLobbyRoomState>(in->updated_state());
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomStateResponse* in, ::lobby::UpdateRoomStateResponse* out)
{
    out->set_updated_state(::lobby::RoomState(static_cast<uint8>(in->UpdatedState)));
}

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomConfigRequest* in, FGrpcLobbyUpdateRoomConfigRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    GRPC_TO_TURBOLINK(&(in->config()), &(out->Config));
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomConfigRequest* in, ::lobby::UpdateRoomConfigRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    TURBOLINK_TO_GRPC(&(in->Config), out->mutable_config());
}

void GRPC_TO_TURBOLINK(const ::lobby::UpdateRoomConfigResponse* in, FGrpcLobbyUpdateRoomConfigResponse* out)
{
    GRPC_TO_TURBOLINK(&(in->updated_config()), &(out->UpdatedConfig));
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdateRoomConfigResponse* in, ::lobby::UpdateRoomConfigResponse* out)
{
    TURBOLINK_TO_GRPC(&(in->UpdatedConfig), out->mutable_updated_config());
}

void GRPC_TO_TURBOLINK(const ::lobby::UpdatePlayerStateRequest* in, FGrpcLobbyUpdatePlayerStateRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    out->UserId=StringCast<TCHAR>((const UTF8CHAR*)(in->user_id().c_str())).Get();
    out->State=StaticCast<EGrpcLobbyPlayerState>(in->state());
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdatePlayerStateRequest* in, ::lobby::UpdatePlayerStateRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    out->set_user_id((const char*)StringCast<UTF8CHAR>(*(in->UserId)).Get());
    out->set_state(::lobby::PlayerState(static_cast<uint8>(in->State)));
}

void GRPC_TO_TURBOLINK(const ::lobby::UpdatePlayerStateResponse* in, FGrpcLobbyUpdatePlayerStateResponse* out)
{
    out->UserId=StringCast<TCHAR>((const UTF8CHAR*)(in->user_id().c_str())).Get();
    out->UpdatedState=StaticCast<EGrpcLobbyPlayerState>(in->updated_state());
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyUpdatePlayerStateResponse* in, ::lobby::UpdatePlayerStateResponse* out)
{
    out->set_user_id((const char*)StringCast<UTF8CHAR>(*(in->UserId)).Get());
    out->set_updated_state(::lobby::PlayerState(static_cast<uint8>(in->UpdatedState)));
}

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomPasswordRequest* in, FGrpcLobbyChangeRoomPasswordRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    out->Password=StringCast<TCHAR>((const UTF8CHAR*)(in->password().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomPasswordRequest* in, ::lobby::ChangeRoomPasswordRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    out->set_password((const char*)StringCast<UTF8CHAR>(*(in->Password)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomPasswordResponse* in, FGrpcLobbyChangeRoomPasswordResponse* out)
{
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomPasswordResponse* in, ::lobby::ChangeRoomPasswordResponse* out)
{
}

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomOwnerRequest* in, FGrpcLobbyChangeRoomOwnerRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
    out->UserId=StringCast<TCHAR>((const UTF8CHAR*)(in->user_id().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomOwnerRequest* in, ::lobby::ChangeRoomOwnerRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
    out->set_user_id((const char*)StringCast<UTF8CHAR>(*(in->UserId)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::ChangeRoomOwnerResponse* in, FGrpcLobbyChangeRoomOwnerResponse* out)
{
    out->OwnerId=StringCast<TCHAR>((const UTF8CHAR*)(in->owner_id().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyChangeRoomOwnerResponse* in, ::lobby::ChangeRoomOwnerResponse* out)
{
    out->set_owner_id((const char*)StringCast<UTF8CHAR>(*(in->OwnerId)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::DeleteRoomRequest* in, FGrpcLobbyDeleteRoomRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyDeleteRoomRequest* in, ::lobby::DeleteRoomRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::DeleteRoomResponse* in, FGrpcLobbyDeleteRoomResponse* out)
{
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyDeleteRoomResponse* in, ::lobby::DeleteRoomResponse* out)
{
}

void GRPC_TO_TURBOLINK(const ::lobby::ListenRoomConfigUpdatesRequest* in, FGrpcLobbyListenRoomConfigUpdatesRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyListenRoomConfigUpdatesRequest* in, ::lobby::ListenRoomConfigUpdatesRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::ListenRoomConfigUpdatesResponse* in, FGrpcLobbyListenRoomConfigUpdatesResponse* out)
{
    GRPC_TO_TURBOLINK(&(in->updated_config()), &(out->UpdatedConfig));
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyListenRoomConfigUpdatesResponse* in, ::lobby::ListenRoomConfigUpdatesResponse* out)
{
    TURBOLINK_TO_GRPC(&(in->UpdatedConfig), out->mutable_updated_config());
}

void GRPC_TO_TURBOLINK(const ::lobby::ListenPlayerListUpdatesRequest* in, FGrpcLobbyListenPlayerListUpdatesRequest* out)
{
    out->RoomId=StringCast<TCHAR>((const UTF8CHAR*)(in->room_id().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyListenPlayerListUpdatesRequest* in, ::lobby::ListenPlayerListUpdatesRequest* out)
{
    out->set_room_id((const char*)StringCast<UTF8CHAR>(*(in->RoomId)).Get());
}

void GRPC_TO_TURBOLINK(const ::lobby::ListenPlayerListUpdatesResponse* in, FGrpcLobbyListenPlayerListUpdatesResponse* out)
{
    out->Players.Empty();
    for (int i=0; i<in->players_size(); ++i) {
        GRPC_TO_TURBOLINK(&(in->players(i)), &(out->Players.AddZeroed_GetRef()));
    }
}

void TURBOLINK_TO_GRPC(const FGrpcLobbyListenPlayerListUpdatesResponse* in, ::lobby::ListenPlayerListUpdatesResponse* out)
{
    for(const auto& value : in->Players) {
        TURBOLINK_TO_GRPC(&value, out->add_players());
    } 
}

