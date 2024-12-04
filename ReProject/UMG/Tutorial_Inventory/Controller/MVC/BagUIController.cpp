#include "BagUIController.h"

#include "ReProject/UMG/Tutorial_Inventory/InventoryCharacter.h"

void UBagUIController::BindPlayerAndUI(AInventoryCharacter* player, UBagUserWidget* bag_user_widget)
{
	this->Character = player;
	this->BagUserWidget= bag_user_widget;
}

TMap<int32, FGridData> UBagUIController::GetPlayerBagItemsData()
{
	return Character->GetBagActorComponent()->GetItemsData();
}
