// Copyright Epic Games, Inc. All Rights Reserved.

#include "ReProjectGameMode.h"
#include "ReProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AReProjectGameMode::AReProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
