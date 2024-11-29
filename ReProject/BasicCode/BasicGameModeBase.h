#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BasicGameModeBase.generated.h"

DECLARE_EVENT(ABasicGameModeBase,NotifyGameMode);
//单播
DECLARE_DELEGATE(NotifyGmaeModeDelegate);
DECLARE_DELEGATE_RetVal(int32,NotifyGameModeDelegateWithReturnValue);
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
	//代理
	NotifyGmaeModeDelegate OneNotifyDelegate;
	NotifyGameModeDelegateWithReturnValue OneNotifyDelegateWithReturnValue;
};
