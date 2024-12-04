#include "BagUIController.h"

void UBagUIController::BindPlayerAndUI(AInventoryCharacter* player, UInventoryUserWidget* inventory_user_widget)
{
	this->Character = player;
	this->InventoryUserWidger= inventory_user_widget;
}
