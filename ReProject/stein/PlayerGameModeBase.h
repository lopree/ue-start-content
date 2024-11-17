#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayerGameModeBase.generated.h"


UCLASS()
class REPROJECT_API APlayerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	AActor* PlayerActor;
public:
	UFUNCTION(Exec)
	void SelfDestroy();
	
};
