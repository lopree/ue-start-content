#include "Tutorial_Inventory_GameModeBase.h"

#include "Inventory_HUD.h"

ATutorial_Inventory_GameModeBase::ATutorial_Inventory_GameModeBase()
{
	HUDClass = AInventory_HUD::StaticClass();
}
