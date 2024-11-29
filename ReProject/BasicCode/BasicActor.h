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
	//委托回调
	void DelegateCallback();
	int32 DelegateWithReturn();
	

};
