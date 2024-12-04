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
		
	}else//装备
	{
		
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
