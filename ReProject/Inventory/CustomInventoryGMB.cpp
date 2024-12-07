#include "CustomInventoryGMB.h"

#include "UI/Inventory_Bag_HUD.h"

ACustomInventoryGMB::ACustomInventoryGMB()
{
	//hud
	HUDClass = AInventory_Bag_HUD::StaticClass();
	//player
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Demo_Inventory/BP/BP_CustomRPGCharacter.BP_CustomRPGCharacter_C'"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
