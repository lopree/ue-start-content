#include "Tutorial_Inventory_GameModeBase.h"

#include "Inventory_HUD.h"

ATutorial_Inventory_GameModeBase::ATutorial_Inventory_GameModeBase()
{
	HUDClass = AInventory_HUD::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Tutorial_Inventory01/BP/BP_InventoryCharacter.BP_InventoryCharacter_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
