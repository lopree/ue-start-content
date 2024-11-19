#include "BGActor.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
ABGActor::ABGActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//设置组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	BackGroundSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BackGround"));
	BackGroundSpriteComponent->SetupAttachment(RootComponent);
	//sprite
	DaySprite = LoadObject<UPaperSprite>(nullptr, TEXT("/Script/Paper2D.PaperSprite'/Game/_Game/Texture/Background/bg_day_Sprite.bg_day_Sprite'"));
	NightSprite = LoadObject<UPaperSprite>(nullptr, TEXT("/Script/Paper2D.PaperSprite'/Game/_Game/Texture/Background/bg_night_Sprite.bg_night_Sprite'"));
	
}

void ABGActor::BeginPlay()
{
	Super::BeginPlay();
	
	//随机一个背景
	int32 bg_value= FMath::RandRange(0, 100);
	if (bg_value > 30)
	{
		BackGroundSpriteComponent->SetSprite(DaySprite);
	}else
	{
		BackGroundSpriteComponent->SetSprite(NightSprite);
	}
	
}

void ABGActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

