///管理各种管理器。比如管理item，场景，服务器等manager
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InventoryGameInstance.generated.h"

class UManagerBase;

UCLASS()
class REPROJECT_API UInventoryGameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
	virtual void OnStart() override;
public:
	//注册以及查询
	void RegisterManager(uint32 manager_key,UManagerBase* manager);
	template<typename TClass>
	TClass* GetManager(uint32 manager_key);
protected:
	UPROPERTY()
	TMap<uint32, UManagerBase*> ManagerMap;
};


