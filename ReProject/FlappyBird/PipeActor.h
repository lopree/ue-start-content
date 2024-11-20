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
	void PipMove(float DeltaTime);
	//管道移动
	void SetPipInterDistance(USceneComponent* pip_root);
private:
	TArray<USceneComponent*> SceneComponents;
	float PipMoveSpeed;

};
