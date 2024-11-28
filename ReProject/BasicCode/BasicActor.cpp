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
		gm->OneNotifyDelegate.BindUObject(this,&ABasicActor::DelegateCallback);
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

