#include "InventoryBFL.h"
#include "ReProject/UMG/Tutorial_Inventory/Manager/ItemManager.h"  
#include "ReProject/UMG/Tutorial_Inventory/CharacterEnum.h"
#include "ReProject/UMG/Tutorial_Inventory/Manager/InventoryGameInstance.h"

UItemManager* UInventoryBFL::GetItemManager(UObject* WorldContext)
{
	if (UInventoryGameInstance* gi = Cast<UInventoryGameInstance>(WorldContext->GetWorld()->GetGameInstance()))
	{
		UItemManager* ItemManager = gi->GetManager<UItemManager>(MGRID_ITEM);

		return ItemManager;
	}
	return nullptr;
}
