#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicActor.generated.h"

UCLASS()
class REPROJECT_API ABasicActor : public APawn
{
	GENERATED_BODY()
	
public:	
	ABasicActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	//委托回调--单播
	void DelegateCallback();
	int32 DelegateWithReturn();
	//委托回调--多播
	void MultiDelegateCallback();
	void MultiDelegateWithOneParamCallback(int32 int_param);
	//动态多播
	UFUNCTION()
	void DynDelegateCallback();
	UFUNCTION()
	int32 DynDelegateWithOneParamCallback(int32 int_param);
	UFUNCTION()
	void DynMultiDelegateCallback(int32 int_param);
};


