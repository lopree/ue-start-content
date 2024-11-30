#include "BasicActor.h"

#include "BasicGameModeBase.h"

ABasicActor::ABasicActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABasicActor::BeginPlay()
{
	Super::BeginPlay();
	if (ABasicGameModeBase* gm = Cast<ABasicGameModeBase>(GetWorld()->GetAuthGameMode()))
	{
		//gm->OneNotifyDelegate.BindUObject(this,&ABasicActor::DelegateCallback);
		gm->OneNotifyDelegateWithReturnValue.BindUObject(this,&ABasicActor::DelegateWithReturn);
		gm->MultiNotifyDelegate.AddUObject(this,&ABasicActor::MultiDelegateCallback);
		gm->MultiNotifyDelegateWithOneParam.AddUObject(this,&ABasicActor::MultiDelegateWithOneParamCallback);
		//动态多播
		gm->DynNotifyDelegate.BindUFunction(this,TEXT("DynDelegateCallback"));
		gm->DynNotifyDelegateWithOneParam.BindUFunction(this,TEXT("DynDelegateWithOneParamCallback"));
		//动态多播
		gm->DynMulWithOneParam.AddDynamic(this,&ABasicActor::DynMultiDelegateCallback);
	}
}

void ABasicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicActor::DelegateCallback()
{
	UE_LOG(LogTemp, Log, TEXT("Delegate callback for gm OneNotifyDelegate"));
}

int32 ABasicActor::DelegateWithReturn()
{
	UE_LOG(LogTemp, Log, TEXT("Delegate with return value"));
	return 100;
}

void ABasicActor::MultiDelegateCallback()
{
	UE_LOG(LogTemp, Log, TEXT("我：%s,接收到了一个多播"),*GetName());
}

void ABasicActor::MultiDelegateWithOneParamCallback(int32 int_param)
{
	UE_LOG(LogTemp, Warning, TEXT("多播带有一个参数：%d"), int_param);
}

void ABasicActor::DynDelegateCallback()
{
	UE_LOG(LogTemp, Warning, TEXT("动态单播，无参无返回值"));
}

int32 ABasicActor::DynDelegateWithOneParamCallback(int32 int_param)
{
	UE_LOG(LogTemp, Warning, TEXT("动态单播带有一个参数：%d"), int_param);
	return 1;
}

void ABasicActor::DynMultiDelegateCallback(int32 int_param)
{
	UE_LOG(LogTemp, Warning, TEXT("动态多播带有一个参数：%d"), int_param);
}

