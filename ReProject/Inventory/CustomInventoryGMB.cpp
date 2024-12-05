#include "CustomInventoryGMB.h"

ACustomInventoryGMB::ACustomInventoryGMB()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Demo_Inventory/BP/BP_CustomRPGCharacter.BP_CustomRPGCharacter_C'"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
