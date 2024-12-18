#pragma once

#include "CoreMinimal.h"
#include "BGActor.h"
#include "BirdGameStateBase.h"
#include "LandActor.h"
#include "PipeActor.h"
#include "GameFramework/GameModeBase.h"
#include "BirdGameModeBase.generated.h"


UCLASS()
class REPROJECT_API ABirdGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	ABirdGameModeBase();
	virtual void BeginPlay() override;

private:
	ABGActor* BirdActor;
	ALandActor* LandActor;
	APipeActor* PipeActor;
	ABirdGameStateBase* BirdGameState;
};
