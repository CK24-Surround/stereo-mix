//Generated by TurboLink CodeGenerator, do not edit!
#include "AuthMarshaling.h"

void GRPC_TO_TURBOLINK(const ::auth::UserAccount* in, FGrpcAuthUserAccount* out)
{
    out->UserId=StringCast<TCHAR>((const UTF8CHAR*)(in->user_id().c_str())).Get();
    out->UserName=StringCast<TCHAR>((const UTF8CHAR*)(in->user_name().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcAuthUserAccount* in, ::auth::UserAccount* out)
{
    out->set_user_id((const char*)StringCast<UTF8CHAR>(*(in->UserId)).Get());
    out->set_user_name((const char*)StringCast<UTF8CHAR>(*(in->UserName)).Get());
}

void GRPC_TO_TURBOLINK(const ::auth::GuestLoginRequest* in, FGrpcAuthGuestLoginRequest* out)
{
    out->UserName=StringCast<TCHAR>((const UTF8CHAR*)(in->user_name().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcAuthGuestLoginRequest* in, ::auth::GuestLoginRequest* out)
{
    out->set_user_name((const char*)StringCast<UTF8CHAR>(*(in->UserName)).Get());
}

void GRPC_TO_TURBOLINK(const ::auth::LoginResponse* in, FGrpcAuthLoginResponse* out)
{
    out->AccessToken=StringCast<TCHAR>((const UTF8CHAR*)(in->access_token().c_str())).Get();
    out->RefreshToken=StringCast<TCHAR>((const UTF8CHAR*)(in->refresh_token().c_str())).Get();
    GRPC_TO_TURBOLINK(&(in->user_account()), &(out->UserAccount));
}

void TURBOLINK_TO_GRPC(const FGrpcAuthLoginResponse* in, ::auth::LoginResponse* out)
{
    out->set_access_token((const char*)StringCast<UTF8CHAR>(*(in->AccessToken)).Get());
    out->set_refresh_token((const char*)StringCast<UTF8CHAR>(*(in->RefreshToken)).Get());
    TURBOLINK_TO_GRPC(&(in->UserAccount), out->mutable_user_account());
}

void GRPC_TO_TURBOLINK(const ::auth::ValidateUserTokenRequest* in, FGrpcAuthValidateUserTokenRequest* out)
{
    out->AccessToken=StringCast<TCHAR>((const UTF8CHAR*)(in->access_token().c_str())).Get();
}

void TURBOLINK_TO_GRPC(const FGrpcAuthValidateUserTokenRequest* in, ::auth::ValidateUserTokenRequest* out)
{
    out->set_access_token((const char*)StringCast<UTF8CHAR>(*(in->AccessToken)).Get());
}

void GRPC_TO_TURBOLINK(const ::auth::ValidateUserTokenResponse* in, FGrpcAuthValidateUserTokenResponse* out)
{
    out->IsValid=in->is_valid();
    GRPC_TO_TURBOLINK(&(in->user_account()), &(out->UserAccount));
}

void TURBOLINK_TO_GRPC(const FGrpcAuthValidateUserTokenResponse* in, ::auth::ValidateUserTokenResponse* out)
{
    out->set_is_valid(in->IsValid);
    TURBOLINK_TO_GRPC(&(in->UserAccount), out->mutable_user_account());
}

