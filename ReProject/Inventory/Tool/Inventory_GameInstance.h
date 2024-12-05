//=====================================
//管理各种管理器。比如管理item，场景，服务器等manager
//=====================================
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Inventory_GameInstance.generated.h"


class UInventory_ManagerBase;

UCLASS()
class REPROJECT_API UInventory_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	//注册以及查询
	void RegisterManager(uint32 manager_key,UInventory_ManagerBase* manager);
	template<typename TClass>
	TClass* GetManager(uint32 manager_key);
protected:
	virtual void Init() override;
	UPROPERTY()
	TMap<uint32, UInventory_ManagerBase*> ManagerMap;
};
template <typename TClass>
TClass* UInventory_GameInstance::GetManager(uint32 manager_key)
{
	if (!ManagerMap.Contains(manager_key))
	{
		return nullptr;
	}	
	return Cast<TClass>(ManagerMap[manager_key]);
}
