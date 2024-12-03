#include "InventoryGameInstance.h"

#include "ItemManager.h"
#include "ManagerBase.h"
#include "ReProject/UMG/Tutorial_Inventory/CharacterEnum.h"

void UInventoryGameInstance::OnStart()
{
	Super::OnStart();
	//手动安装管理器
	RegisterManager(MGRID_ITEM,NewObject<UItemManager>(this));
}

void UInventoryGameInstance::RegisterManager(uint32 manager_key, UManagerBase* manager)
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