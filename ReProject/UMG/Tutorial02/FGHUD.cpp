#include "FGHUD.h"

#include "LoginUserWidget.h"
#include "MainMenuUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
void AFGHUD::BeginPlay()
{
	Super::BeginPlay();
	//设置画面
	GetMainMenPanel();
	ShowMainMenu();
	//set mouse cursor
	// 获取玩家控制器
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
	{
		// 显示鼠标
		PlayerController->bShowMouseCursor = true;
	}
}
///main panel
UMainMenuUserWidget* AFGHUD::GetMainMenPanel()
{
	TSubclassOf<UUserWidget> MainUI_UserWidget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_UMG02/BP/BP_MainMenuUserWidget.BP_MainMenuUserWidget_C'"));
	MainMenuPanel = CreateWidget<UMainMenuUserWidget>(GetOwningPlayerController(),MainUI_UserWidget);
	return MainMenuPanel;
}

void AFGHUD::ShowMainMenu()
{
	GetMainMenPanel()->AddToViewport();
}

void AFGHUD::HideMainMenu()
{
	GetMainMenPanel()->RemoveFromParent();
}
///login panel
ULoginUserWidget* AFGHUD::GetLoginPanel()
{
	TSubclassOf<UUserWidget> Login_UserWidget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_UMG02/BP/BP_LoginUserWidget.BP_LoginUserWidget_C'"));
	LoginPanel = CreateWidget<ULoginUserWidget>(GetOwningPlayerController(),Login_UserWidget);
	return LoginPanel;
}

void AFGHUD::ShowLogin()
{
	GetLoginPanel()->AddToViewport();
}

void AFGHUD::HideLogin()
{
	GetLoginPanel()->RemoveFromParent();
}