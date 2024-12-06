#include "Inventory_BFL.h"

#include "Inventory_Constant.h"
#include "Inventory_GameInstance.h"
UInventory_ItemManager* UInventory_BFL::GetItemManager(UObject* WorldContext)
{
	if (UInventory_GameInstance* gi = Cast<UInventory_GameInstance>(WorldContext->GetWorld()->GetGameInstance()))
	{
		UInventory_ItemManager* ItemManager = gi->GetManager<UInventory_ItemManager>(INVENTORY_ITEM_MANAGER_INDEX);

		return ItemManager;
	}
	return nullptr;
}

FInventory_ItemDataBase* UInventory_BFL::GetItemData(int32 item_id)
{
	UInventory_ItemManager* ItemManager = NewObject<UInventory_ItemManager>();
	ItemManager->LoadDataTable(ItemManager->Equips_DataTable,TEXT("/Script/Engine.DataTable'/Game/Demo_Inventory/Data/DT_Equip.DT_Equip'"));
	ItemManager->LoadDataTable(ItemManager->Consume_DataTable,TEXT("/Script/Engine.DataTable'/Game/Demo_Inventory/Data/DT_Consume.DT_Consume'"));
	if (ItemManager->Item_Data_Map.Contains(item_id))
	{
		return ItemManager->Item_Data_Map[item_id];
	}
	return nullptr;
}



