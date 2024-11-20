#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BirdGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class REPROJECT_API ABirdGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	ABirdGameStateBase();
	int32 Score;
	int32 GetScore();
	void ResetScore();
	void AddScore();
	void AddDoubleScore();
	
};
