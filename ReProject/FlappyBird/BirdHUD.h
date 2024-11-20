#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BirdHUD.generated.h"


UCLASS()
class REPROJECT_API ABirdHUD : public AHUD
{
	GENERATED_BODY()
public:
	ABirdHUD();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void DrawHUD() override;
	virtual void NotifyHitBoxClick(FName BoxName) override;
	virtual void NotifyHitBoxRelease(FName BoxName) override;
	void DrawGamePlayButton();
	bool bDrawGamePlayButton;
	UTexture* GamePlayButtonTexture;
	void BeginPlayButtonInit();
	//屏幕遮罩
	void SetGamePlayRect();
	//绘制皮肤选项卡
	void DrawBirdsSkinTab();
	//初始化皮肤
	void SkinInit();
	int32 SkinIndex;
	

private:
	//按钮texture路径
	FString gameplay_button_texture_path;
	float TextureWidth,TextureHeight;
	float ScreenWidth;
	float ScreenHeight;
	UTexture2D* Texture2D;
	//遮罩参数
	float RectAlpha;
	float RectOpenSpeed;
	bool bDrawBlackRect;
	//按钮点击事件名称
	FString PlayrBtnName;
	//是否开启绘制皮肤
	bool bDrawSkinToggle;
	//bird pawn
	class ABirdPawn* PlayerBirdPawn;

	//小鸟皮肤
	UTexture2D* redBirdSkinTexture;
	UTexture2D* yellowBirdSkinTexture;
	UTexture2D* blueBirdSkinTexture;
	float box_position_x,box_position_y;
	//gamestate
	class ABirdGameStateBase* GameState;
	void DrawScoreToScreen();
	//font
	UFont* ScoreFont;
};
