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
	

private:
	FString GameplayButtonTexturePath;
	float TextureWidth,TextureHeight;
	float ScreenWidth;
	float ScreenHeight;
	UTexture2D* Texture2D;
	
};
