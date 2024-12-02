#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuUserWidget.generated.h"


class AFGHUD;
class UButton;

UCLASS()
class REPROJECT_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(Transient,meta=(BindWidgetAnim))
	UWidgetAnimation* TitleAnimation;
	UPROPERTY(Transient,meta=(BindWidgetAnim))
	UWidgetAnimation* MainMenuAnimation;
	UPROPERTY(Transient,meta=(BindWidgetAnim))
	UWidgetAnimation* BGAnimation;
	//当返回主界面的时候，需要播放动画
	void ReBackMainMenu();
	UFUNCTION(BlueprintCallable)
	void PlayOtherAnimation();
protected:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;
private:
	//hud
	AFGHUD* hud;
	//create room
	UButton* CreateRoomButton;
	UFUNCTION()
	void CreateRoomCallback();
	
};
