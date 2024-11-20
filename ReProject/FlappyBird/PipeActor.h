#pragma once


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
	TArray<USceneComponent*> SceneComponents;

};
