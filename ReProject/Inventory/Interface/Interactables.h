#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactables.generated.h"

UINTERFACE()
class UInteractables : public UInterface
{
	GENERATED_BODY()
};

class REPROJECT_API IInteractables
{
	GENERATED_BODY()
public:
	// 蓝图可覆写，优先实现蓝图中实现的方法
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item")
	void Interact();
	//c++ 纯实现
	//按E键位，通知对应的物体对应的行为
	UFUNCTION()
	virtual void InteractPure() = 0;
};
