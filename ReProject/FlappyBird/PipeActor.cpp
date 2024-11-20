#include "PipeActor.h"

APipeActor::APipeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	FirstRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FirstRoot"));
	FirstPaperSpriteUP = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("FirstPaperUp"));
	FirstPaperSpriteBottom = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("FirstPaperBottom"));
	SecondRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SecondRoot"));
	SecondPaperSpriteUP = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SecondPaperUp"));
	SecondPaperSpriteBottom = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SecondPaperBottom"));
	ThirdRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ThirdRoot"));
	ThirdPaperSpriteUP = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ThirdPaperUp"));
	ThirdPaperSpriteBottom = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ThirdPaperBottom"));
	FirstRoot->SetupAttachment(RootComponent);
	FirstPaperSpriteUP->SetupAttachment(FirstRoot);
	FirstPaperSpriteBottom->SetupAttachment(FirstRoot);
	SecondRoot->SetupAttachment(RootComponent);
	SecondPaperSpriteUP->SetupAttachment(SecondRoot);
	SecondPaperSpriteBottom->SetupAttachment(SecondRoot);
	ThirdRoot->SetupAttachment(RootComponent);
	ThirdPaperSpriteUP->SetupAttachment(ThirdRoot);
	ThirdPaperSpriteBottom->SetupAttachment(ThirdRoot);

	PipSpriteUP = LoadObject<UPaperSprite>(nullptr, TEXT("/Script/Paper2D.PaperSprite'/Game/_Game/Texture/PipeAndLand/pipe_up_Sprite.pipe_up_Sprite'"));
	PipSpriteBottom = LoadObject<UPaperSprite>(nullptr, TEXT("/Script/Paper2D.PaperSprite'/Game/_Game/Texture/PipeAndLand/pipe_down_Sprite.pipe_down_Sprite'"));
}

void APipeActor::BeginPlay()
{
	Super::BeginPlay();
	FirstPaperSpriteUP->SetSprite(PipSpriteUP);
	FirstPaperSpriteBottom->SetSprite(PipSpriteBottom);
	SecondPaperSpriteUP->SetSprite(PipSpriteUP);
	SecondPaperSpriteBottom->SetSprite(PipSpriteBottom);
	ThirdPaperSpriteUP->SetSprite(PipSpriteUP);
	ThirdPaperSpriteBottom->SetSprite(PipSpriteBottom);
	
}

void APipeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

