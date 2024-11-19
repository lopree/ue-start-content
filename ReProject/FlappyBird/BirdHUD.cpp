#include "BirdHUD.h"
#include "Engine/Canvas.h"
ABirdHUD::ABirdHUD()
{
	GameplayButtonTexturePath = TEXT("/Script/Engine.Texture2D'/Game/_Game/Texture/UI/button_play.button_play'");
	bDrawGamePlayButton = true;
	GamePlayButtonTexture = nullptr;
}

void ABirdHUD::BeginPlay()
{
	Super::BeginPlay();
	//初始化按钮
	BeginPlayButtonInit();
}
void ABirdHUD::BeginPlayButtonInit()
{
	GamePlayButtonTexture = LoadObject<UTexture>(nullptr,*GameplayButtonTexturePath);
	Texture2D = Cast<UTexture2D>(GamePlayButtonTexture);
	TextureWidth = Texture2D->GetSizeX();
	TextureHeight = Texture2D->GetSizeY();
	UE_LOG(LogTemp, Warning, TEXT("Width: %.2f, Height: %.2f"), TextureWidth, TextureHeight);

}
void ABirdHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABirdHUD::DrawHUD()
{
	Super::DrawHUD();
	ScreenWidth = Canvas->SizeX/2 -TextureWidth + 60;
	ScreenHeight = Canvas->SizeY/2 - TextureHeight;
	if (bDrawGamePlayButton)
	{
		DrawGamePlayButton();
	}
}
void ABirdHUD::DrawGamePlayButton()
{
	if (GamePlayButtonTexture != nullptr)
	{
		DrawTextureSimple(GamePlayButtonTexture,ScreenWidth,ScreenHeight);
	}else
	{
		GamePlayButtonTexture = LoadObject<UTexture>(nullptr,*GameplayButtonTexturePath);
	}
}

void ABirdHUD::NotifyHitBoxClick(FName BoxName)
{
	Super::NotifyHitBoxClick(BoxName);
}

void ABirdHUD::NotifyHitBoxRelease(FName BoxName)
{
	Super::NotifyHitBoxRelease(BoxName);
}



