#include "Inventory_GameInstance.h"

#include "Inventory_Constant.h"
#include "ReProject/Inventory/Item/Inventory_ItemManager.h"

void UInventory_GameInstance::Init()
{
	Super::Init();
	//手动安装管理器
	RegisterManager(INVENTORY_ITEM_MANAGER_INDEX,NewObject<UInventory_ItemManager>(this));
}

void UInventory_GameInstance::RegisterManager(uint32 manager_key, UInventory_ManagerBase* manager)
{
	if (!manager) return;//如果传入空指针
	if (ManagerMap.Contains(manager_key))
	{
		UE_LOG(LogTemp, Warning, TEXT("[rookstein]管理器已经存在，不需要注册！"));
		return;
	}

	ManagerMap.Add(manager_key, manager);
	manager->Install();
}

