
#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/Actor.h"
#include "LandActor.generated.h"

UCLASS()
class REPROJECT_API ALandActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ALandActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	//land move
	void MoveLand();

private:
	//两个地块
	UPaperSpriteComponent* FirstLandSprite;
	UPaperSpriteComponent* SecondLandSprite;
	//sprite
	UPaperSprite* LandSprite;

};
