#include "ItemManager.h"

void UItemManager::Install()
{
}

void UItemManager::Uninstall()
{
	
}

FItemDataBase* UItemManager::GetItemData(int32 ID)
{
	UDataTable* table = nullptr;
	if (ID >= 1000)//消耗品
	{
		if (!ConsumableDataTable)
		{
			ConsumableDataTable = LoadObject<UDataTable>(this,TEXT("/Script/Engine.DataTable'/Game/Tutorial_Inventory01/Data/DT_Consum.DT_Consum'"));
		}
		table = ConsumableDataTable;
	}else//装备
	{
		if (!EquipDataTable)
		{
			EquipDataTable = LoadObject<UDataTable>(this,TEXT("/Script/Engine.DataTable'/Game/Tutorial_Inventory01/Data/DT_Equip.DT_Equip'"));
		}
		table = EquipDataTable;
	}

	if (!table) return nullptr;

	TArray<FItemDataBase*> item_array;
	table->GetAllRows<FItemDataBase>(TEXT("无法读取数据表格"), item_array);
	for (auto  item : item_array)
	{
		if (item->Item_ID == ID)
		{
			return item;
		}
	}
	return nullptr;
}

int32 UItemManager::GetItemMaxStack(int32 ID)
{
	if (FItemDataBase* DT = GetItemData(ID))
	{
		return DT->Item_Max_Stack;
	}
	return -1;
}
