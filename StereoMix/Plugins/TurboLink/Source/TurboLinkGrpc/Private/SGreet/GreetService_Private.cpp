//Generated by TurboLink CodeGenerator, do not edit!
#include "GreetService_Private.h"

void UGreeterServiceSayHelloLambdaWrapper::OnResponse(FGrpcContextHandle _Handle, const FGrpcResult& GrpcResult, const FGrpcGreetHelloResponse& Response)
{
	if (_Handle != this->Handle) return;

	ResponseLambda(GrpcResult, Response);
	InnerClient->OnSayHelloResponse.RemoveDynamic(this, &UGreeterServiceSayHelloLambdaWrapper::OnResponse);
}

