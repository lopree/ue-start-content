#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BasicGameModeBase.generated.h"

DECLARE_EVENT(ABasicGameModeBase,NotifyGameMode);
DECLARE_DELEGATE(NotifyGmaeModeDelegate);
UCLASS()
class REPROJECT_API ABasicGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ABasicGameModeBase();
protected:
	UFUNCTION(Exec)
	void NativePointer();
	UFUNCTION(Exec)
	void NotifyEvent();
public:
	NotifyGameMode OneNotifyOne;
	NotifyGmaeModeDelegate OneNotifyDelegate;
};
