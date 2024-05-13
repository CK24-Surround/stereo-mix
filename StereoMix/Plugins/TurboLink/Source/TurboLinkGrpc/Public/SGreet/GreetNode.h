//Generated by TurboLink CodeGenerator, do not edit!
#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TurboLinkGrpcClient.h"
#include "GreetMessage.h"
#include "GreetNode.generated.h"

class UGreeterService;
class UGreeterServiceClient;

UCLASS(ClassGroup = TurboLink)
class TURBOLINKGRPC_API UCallGreeterServiceSayHello : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGreeterServiceSayHelloDelegate, const FGrpcResult&, GrpcResult, const FGrpcGreetHelloResponse&, Response);

	UFUNCTION(BlueprintCallable, Category = "TurboLink|GreeterService", meta = (
		BlueprintInternalUseOnly = "true",
		WorldContext = "WorldContextObject",
		DisplayName = "Call GreeterService SayHello",
		AdvancedDisplay = 2))
	static UCallGreeterServiceSayHello* SayHello(UObject* WorldContextObject, const FGrpcGreetHelloRequest& request, FGrpcMetaData metaData = FGrpcMetaData(), float deadLineSeconds = 0.f);

	UPROPERTY(BlueprintAssignable)
	FGreeterServiceSayHelloDelegate OnSayHelloResponse;

	UPROPERTY(BlueprintAssignable)
	FGreeterServiceSayHelloDelegate OnFail;

private:
	virtual void Activate() override;

	UPROPERTY()
	UGreeterService* GreeterService;
	
	UPROPERTY()
	UGreeterServiceClient* GreeterServiceClient;
	
	FGrpcContextHandle Context;
	FGrpcGreetHelloRequest Request;
	EGrpcServiceState ServiceState;
	FGrpcMetaData MetaData;
	float DeadLineSeconds;

	UFUNCTION()
	void OnServiceStateChanged(EGrpcServiceState NewState);
	
	UFUNCTION()
	void OnContextStateChange(FGrpcContextHandle Handle, EGrpcContextState State);

	UFUNCTION()
	void OnResponse(FGrpcContextHandle Handle, const FGrpcResult& GrpcResult, const FGrpcGreetHelloResponse& Response);

	void Shutdown();
};
