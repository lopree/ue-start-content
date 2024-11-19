#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BGActor.generated.h"
class UPaperSprite;
UCLASS()
class REPROJECT_API ABGActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABGActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void SetDayNightSprite(int32 timeIndex);

private:
	//背景组件
	class UPaperSpriteComponent* BackGroundSpriteComponent;
	//背景图片
	UPaperSprite* DaySprite;
	UPaperSprite* NightSprite;
	//计时器
	float CurrentTime;
	float MaxTime;
	float mininter,maxinter;//间隔时间
	//时间记录
	int32 DayNightIndex;
	

};


