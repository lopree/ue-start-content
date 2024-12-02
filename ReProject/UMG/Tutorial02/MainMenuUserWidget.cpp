#include "MainMenuUserWidget.h"

#include "FGHUD.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"

class UObjectProperty;

bool UMainMenuUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		CreateRoomButton = Cast<UButton>(GetWidgetFromName(TEXT("CreateRoom")));
		return true; 
	}
	return false; 
}

void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (TitleAnimation)
	{
		//播放title动画
		PlayAnimation(TitleAnimation);
		//播放按钮动画
		//PlayAnimation(MainMenuAnimation);
	}
	//按钮事件绑定
	hud =Cast<AFGHUD>(GetOwningPlayer()->GetHUD());
	//寻找button
	CreateRoomButton->OnClicked.AddDynamic(this,&UMainMenuUserWidget::CreateRoomCallback);
}

void UMainMenuUserWidget::ReBackMainMenu()
{
	PlayAnimation(MainMenuAnimation);
	PlayAnimation(BGAnimation,0,1,EUMGSequencePlayMode::Reverse,2,false);
}

void UMainMenuUserWidget::PlayOtherAnimation()
{
	PlayAnimation(MainMenuAnimation);
}

void UMainMenuUserWidget::CreateRoomCallback()
{
	PlayAnimation(MainMenuAnimation,0,1,EUMGSequencePlayMode::Reverse,3,false);
	PlayAnimation(BGAnimation,0,1,EUMGSequencePlayMode::Forward,2,false);
	hud->ShowLogin();
}



