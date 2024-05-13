//Generated by TurboLink CodeGenerator, do not edit!
#include "SGreet/GreetClient.h"
#include "SGreet/GreetService.h"
#include "GreetContext.h"
#include "TurboLinkGrpcManager_Private.h"
#include "Templates/SharedPointer.h"

FGrpcContextHandle UGreeterServiceClient::InitSayHello()
{
	FGrpcContextHandle handle = Service->TurboLinkManager->GetNextContextHandle();
	auto context = UGrpcClient::MakeContext<GrpcContext_GreeterService_SayHello>(handle);
	context->RpcContext = UTurboLinkGrpcManager::Private::CreateRpcClientContext();
	return context->GetHandle();
}

void UGreeterServiceClient::SayHello(FGrpcContextHandle Handle, const FGrpcGreetHelloRequest& Request, FGrpcMetaData MetaData, float DeadLineSeconds)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		auto contextSayHello = StaticCastSharedPtr<GrpcContext_GreeterService_SayHello>(*context);
		for (const auto& metaDataPair : MetaData.MetaData)
		{
			contextSayHello->RpcContext->AddMetadata(
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Key)).Get(),
				(const char*)StringCast<UTF8CHAR>(*(metaDataPair.Value)).Get()
			);
		}

		if (DeadLineSeconds > 0.f)
		{
			std::chrono::time_point deadLine = std::chrono::system_clock::now() + 
				std::chrono::milliseconds((int32)(1000.f * DeadLineSeconds));
			contextSayHello->RpcContext->set_deadline(deadLine);
		}
		contextSayHello->Call(Request);
	}
}

void UGreeterServiceClient::TryCancel(FGrpcContextHandle Handle)
{
	auto context = UGrpcClient::GetContext(Handle);
	if (context != nullptr)
	{
		(*context)->TryCancel();
	}
}

void UGreeterServiceClient::Shutdown()
{
	OnSayHelloResponse.Clear();
	Super::Shutdown();
}

