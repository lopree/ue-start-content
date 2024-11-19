#include "BirdHUD.h"

#include "BirdPawn.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"

ABirdHUD::ABirdHUD()
{
	gameplay_button_texture_path = TEXT("/Script/Engine.Texture2D'/Game/_Game/Texture/UI/button_play.button_play'");
	bDrawGamePlayButton = true;
	bDrawBlackRect = true;
	GamePlayButtonTexture = nullptr;
	RectAlpha = 0.45f;
	RectOpenSpeed = 0.005f;
	PlayrBtnName = TEXT("Play");
	bDrawSkinToggle = true;
	SkinIndex = -1;
}

void ABirdHUD::BeginPlay()
{
	Super::BeginPlay();
	//初始化按钮
	BeginPlayButtonInit();
	SkinInit();
}
void ABirdHUD::BeginPlayButtonInit()
{
	APlayerController* player_controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (player_controller != nullptr)
	{
		player_controller->bShowMouseCursor = true;
		player_controller->bEnableClickEvents = true;
	}
	GamePlayButtonTexture = LoadObject<UTexture>(nullptr,*gameplay_button_texture_path);
	Texture2D = Cast<UTexture2D>(GamePlayButtonTexture);
	TextureWidth = Texture2D->GetSizeX();
	TextureHeight = Texture2D->GetSizeY();
	//get pawn
	PlayerBirdPawn =Cast<ABirdPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
}
void ABirdHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABirdHUD::DrawHUD()
{
	Super::DrawHUD();
	ScreenWidth = Canvas->SizeX/2 -TextureWidth + 60;
	ScreenHeight = Canvas->SizeY/2 - TextureHeight + 100;
	if (RectAlpha > 0.f)
	{
		DrawRect(FLinearColor(0,0,0,RectAlpha),0,0,Canvas->SizeX,Canvas->SizeY);
	}
	SetGamePlayRect();
	if (bDrawGamePlayButton)
	{
		DrawGamePlayButton();
	}
	if (bDrawSkinToggle)
	{
		DrawBirdsSkinTab();
	}

	
}
//遮罩
void ABirdHUD::SetGamePlayRect()
{
	if (bDrawBlackRect) return;
	RectAlpha -= RectOpenSpeed;
}

void ABirdHUD::DrawBirdsSkinTab()
{
	box_position_x = Canvas->SizeX/2 - 170;
	box_position_y = Canvas->SizeY/2 - 160;
	//选项卡周围的线框
	FCanvasBoxItem box_item(FVector2D(box_position_x,box_position_y), FVector2D(340.f, 120.f));
	Canvas->DrawItem(box_item);
	//绘制内容物
	DrawTextureSimple(redBirdSkinTexture,box_position_x + 10,box_position_y+10);//red bird
	DrawTextureSimple(yellowBirdSkinTexture,box_position_x + 10 + 100+ 10,box_position_y+10);//red bird
	DrawTextureSimple(blueBirdSkinTexture,box_position_x + 10 + 100 + 10+100+10,box_position_y+10);//red bird
	//可点击区域
	AddHitBox(FVector2D(box_position_x + 10,box_position_y+10),FVector2D(100,100),TEXT("red_bird"),true);
	AddHitBox(FVector2D(box_position_x + 10 + 100+ 10,box_position_y+10),FVector2D(100,100),TEXT("yellow_bird"),true);
	AddHitBox(FVector2D(box_position_x + 10 + 100 + 10+100+10,box_position_y+10),FVector2D(100,100),TEXT("blue_bird"),true);
	
}

void ABirdHUD::SkinInit()
{
	redBirdSkinTexture = LoadObject<UTexture2D>(nullptr,TEXT("/Script/Engine.Texture2D'/Game/_Game/Texture/Bird/red_bird.red_bird'"));
	yellowBirdSkinTexture = LoadObject<UTexture2D>(nullptr,TEXT("/Script/Engine.Texture2D'/Game/_Game/Texture/Bird/yellow_bird.yellow_bird'"));
	blueBirdSkinTexture = LoadObject<UTexture2D>(nullptr,TEXT("/Script/Engine.Texture2D'/Game/_Game/Texture/Bird/blue_bird.blue_bird'"));
}

//开始按钮
void ABirdHUD::DrawGamePlayButton()
{
	if (GamePlayButtonTexture != nullptr)
	{
		DrawTextureSimple(GamePlayButtonTexture,ScreenWidth,ScreenHeight);
		//添加交互区域
		AddHitBox(FVector2D(ScreenWidth,ScreenHeight),FVector2D(TextureWidth,TextureHeight),*PlayrBtnName,true);
	}else
	{
		GamePlayButtonTexture = LoadObject<UTexture>(nullptr,*gameplay_button_texture_path);
	}
}

void ABirdHUD::NotifyHitBoxClick(FName BoxName)
{
	Super::NotifyHitBoxClick(BoxName);
	if (BoxName == PlayrBtnName)
	{
		//取消遮罩
		bDrawBlackRect = false;
		bDrawGamePlayButton = false;
	}
}

void ABirdHUD::NotifyHitBoxRelease(FName BoxName)
{
	Super::NotifyHitBoxRelease(BoxName);
	if (BoxName == TEXT("red_bird"))
	{
		SkinIndex = 0;
		PlayerBirdPawn->SetSkin(0);
	}else if (BoxName == TEXT("yellow_bird"))
	{
		SkinIndex = 1;
		PlayerBirdPawn->SetSkin(1);
	}else if (BoxName == TEXT("blue_bird"))
	{
		SkinIndex = 2;
		PlayerBirdPawn->SetSkin(2);
	}
}



