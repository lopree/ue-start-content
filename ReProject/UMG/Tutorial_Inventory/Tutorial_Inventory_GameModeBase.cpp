#include "Tutorial_Inventory_GameModeBase.h"

#include "Inventory_HUD.h"
#include "Manager/ItemManager.h"
#include "Tool/InventoryBFL.h"

ATutorial_Inventory_GameModeBase::ATutorial_Inventory_GameModeBase()
{
	HUDClass = AInventory_HUD::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Tutorial_Inventory01/BP/BP_InventoryCharacter.BP_InventoryCharacter_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATutorial_Inventory_GameModeBase::AddItem(int32 id, int32 counter)
{
	if (FItemDataBase* data = UInventoryBFL::GetItemManager(this)->GetItemData(id))
	{
		UE_LOG(LogTemp, Warning, TEXT("[rookstein]添加了%d个%s"), counter,*data->Item_Name.ToString());
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("[rookstein]no this item"));
	}
}
