#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PipeActor.generated.h"

struct FPipInfo
{
	bool bToggle;
	USceneComponent* pipeScene;
	FPipInfo():bToggle(true)
	{
		UE_LOG(LogTemp, Warning, TEXT("无参结构体构造函数"));
	}
	FPipInfo(USceneComponent* scenePtr):pipeScene(scenePtr),bToggle(true)
	{
		UE_LOG(LogTemp, Warning, TEXT("有参结构体构造函数"));
	}
	//强制转换为bool
	operator bool()
	{
		return bToggle;
	}
	//强制转换为USceneComponent
	operator USceneComponent*()
	{
		return pipeScene;
	}
	USceneComponent* operator->()
	{
		return pipeScene;
	}
	bool operator=(bool bFlag)
	{
		bToggle = bFlag;
		return bToggle;
	}
	
};

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
	TArray<FPipInfo> SceneComponents;
	float PipMoveSpeed;

	USoundBase* PipSound;
	bool bPlayToggle;

};
