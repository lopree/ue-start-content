#include "BirdGameModeBase.h"

#include "BirdHUD.h"
#include "BirdPawn.h"

ABirdGameModeBase::ABirdGameModeBase()
{
	DefaultPawnClass = ABirdPawn::StaticClass();
	HUDClass = ABirdHUD::StaticClass();
}
