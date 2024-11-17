#include "PlayerGameModeBase.h"

#include "TestActor.h"

void APlayerGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	PlayerActor =  GetWorld()->SpawnActor<ATestActor>();
	//通过映射
	//GetWorld()->SpawnActor(ATestActor::StaticClass());
}

void APlayerGameModeBase::SelfDestroy()
{
	if (PlayerActor != nullptr)
	{
		PlayerActor->Destroy();
	}
}
