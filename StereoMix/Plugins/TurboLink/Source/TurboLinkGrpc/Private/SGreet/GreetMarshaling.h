//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "SGreet/GreetMessage.h"
#include "TurboLinkGrpcContext.h"
#include "greet.grpc.pb.h"

void GRPC_TO_TURBOLINK(const ::greet::HelloRequest* in, FGrpcGreetHelloRequest* out);
void TURBOLINK_TO_GRPC(const FGrpcGreetHelloRequest* in, ::greet::HelloRequest* out);

void GRPC_TO_TURBOLINK(const ::greet::HelloResponse* in, FGrpcGreetHelloResponse* out);
void TURBOLINK_TO_GRPC(const FGrpcGreetHelloResponse* in, ::greet::HelloResponse* out);

typedef grpc::ClientAsyncResponseReader<::greet::HelloResponse> GreeterService_SayHello_ReaderWriter;
