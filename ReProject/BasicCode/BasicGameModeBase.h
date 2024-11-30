#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BasicGameModeBase.generated.h"

DECLARE_EVENT(ABasicGameModeBase,NotifyGameMode);
//单播
DECLARE_DELEGATE(NotifyGmaeModeDelegate);
DECLARE_DELEGATE_RetVal(int32,NotifyGameModeDelegateWithReturnValue);
//多播
DECLARE_MULTICAST_DELEGATE(MultiNotifyGameModeDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(MultiNotifyGameModeDelegateWithOneParam,int32);
//动态代理
//动态单播
DECLARE_DYNAMIC_DELEGATE(FDynNotifyNoParamNoRetDelegate);
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(int32,FDynNotifyWithOneParamRetDelegate,int32,Num);
//动态多播
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynMulDelegateWithOneParam,int32,Num);


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
	UFUNCTION(Exec)
	void MultiNotifyEvent();
	UFUNCTION(Exec)
	void DynNotifyEvent();
	UFUNCTION(Exec)
	void DynMultiNotifyEvent();
public:
	NotifyGameMode OneNotifyOne;
	//单播代理
	NotifyGmaeModeDelegate OneNotifyDelegate;
	NotifyGameModeDelegateWithReturnValue OneNotifyDelegateWithReturnValue;
	//多播代理
	MultiNotifyGameModeDelegate MultiNotifyDelegate;
	MultiNotifyGameModeDelegateWithOneParam MultiNotifyDelegateWithOneParam;
	//动态单播
	FDynNotifyNoParamNoRetDelegate DynNotifyDelegate;
	FDynNotifyWithOneParamRetDelegate DynNotifyDelegateWithOneParam;
	//动态多播
	FDynMulDelegateWithOneParam DynMulWithOneParam;
};
