#include "LandActor.h"

ALandActor::ALandActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	FirstLandSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("FirstLand"));
	FirstLandSprite->SetupAttachment(RootComponent);
	SecondLandSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SecondLand"));
	SecondLandSprite->SetupAttachment(RootComponent);
	//get sprite
	LandSprite = LoadObject<UPaperSprite>(nullptr,TEXT("/Script/Paper2D.PaperSprite'/Game/_Game/Texture/PipeAndLand/land_Sprite.land_Sprite'"));
}

void ALandActor::BeginPlay()
{
	Super::BeginPlay();
	FirstLandSprite->SetSprite(LandSprite);
	SecondLandSprite->SetSprite(LandSprite);
	FirstLandSprite->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	SecondLandSprite->SetRelativeLocation(FVector(336.f, 0.0f, 0.0f));
}

void ALandActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveLand();
}

void ALandActor::MoveLand()
{
	FirstLandSprite->AddRelativeLocation(FVector(-1,0,0));
	SecondLandSprite->AddRelativeLocation(FVector(-1,0,0));
	if (FirstLandSprite->GetRelativeLocation().X < -300.f)
	{
		FirstLandSprite->SetRelativeLocation(FVector(SecondLandSprite->GetRelativeLocation().X+336,0,0));
	}
	if (SecondLandSprite->GetRelativeLocation().X < -300.f)
	{
		SecondLandSprite->SetRelativeLocation(FVector(FirstLandSprite->GetRelativeLocation().X+336,0,0));
	}
}

