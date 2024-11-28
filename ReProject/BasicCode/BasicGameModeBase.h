#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BasicGameModeBase.generated.h"


UCLASS()
class REPROJECT_API ABasicGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UFUNCTION(Exec)
	void NativPointer();
};
