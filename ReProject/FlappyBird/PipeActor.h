#pragma once

#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PipeActor.generated.h"


UCLASS()
class REPROJECT_API APipeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APipeActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
private:
	USceneComponent* FirstRoot;
	USceneComponent* SecondRoot;
	USceneComponent* ThirdRoot;
	UPaperSpriteComponent* FirstPaperSpriteUP;
	UPaperSpriteComponent* SecondPaperSpriteUP;
	UPaperSpriteComponent* ThirdPaperSpriteUP;
	UPaperSpriteComponent* FirstPaperSpriteBottom;
	UPaperSpriteComponent* SecondPaperSpriteBottom;
	UPaperSpriteComponent* ThirdPaperSpriteBottom;
	//
	UPaperSprite* PipSpriteUP;
	UPaperSprite* PipSpriteBottom;

};
