#include "Inventory_ItemManager.h"

#include "ReProject/Inventory/Tool/Inventory_Constant.h"

void UInventory_ItemManager::Install()
{
	// 加载装备数据表
	LoadDataTable(Equips_DataTable, TEXT("/Script/Engine.DataTable'/Game/Demo_Inventory/Data/DT_Equip.DT_Equip'"));
    
	// 加载消耗品数据表
	LoadDataTable(Consume_DataTable, TEXT("/Script/Engine.DataTable'/Game/Demo_Inventory/Data/DT_Consume.DT_Consume'"));
}

void UInventory_ItemManager::LoadDataTable(UDataTable*& DataTable, const FString& Path)
{
	if (!DataTable)
	{
		DataTable = LoadObject<UDataTable>(this, *Path);
		if (DataTable)
		{
			TArray<FInventory_ItemDataBase*> ItemArray;
			DataTable->GetAllRows<FInventory_ItemDataBase>(TEXT("无法读取数据表格"), ItemArray);
			for (auto Item : ItemArray)
			{
				if (Item) // 确保 Item 不为空
				{
					Item_Data_Map.Add(Item->item_id, Item);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load DataTable from path: %s"), *Path);
		}
	}
}

void UInventory_ItemManager::Uninstall()
{
	
}

FInventory_ItemDataBase* UInventory_ItemManager::GetItem_StaticMeshComponent(int32 ID)
{
	for (auto Item : Item_Data_Map)
	{
		if (Item_Data_Map.Contains(ID))
		{
			return Item.Value;
		}
	}
	UE_LOG(LogTemp, Error, TEXT("[rookstein]查询的物品不存在"));
	return nullptr;
}
