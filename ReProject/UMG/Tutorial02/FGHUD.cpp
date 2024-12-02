#include "FGHUD.h"

#include "ErrorUserWidget.h"
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
	if (LoginPanel == nullptr)
	{
		TSubclassOf<UUserWidget> Login_UserWidget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_UMG02/BP/BP_LoginUserWidget.BP_LoginUserWidget_C'"));
		LoginPanel = CreateWidget<ULoginUserWidget>(GetOwningPlayerController(),Login_UserWidget);
	}
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

UErrorUserWidget* AFGHUD::GetErrorPanel()
{
	if (ErrorPanel == nullptr)
	{
		TSubclassOf<UUserWidget> Error_UserWidget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_UMG02/BP/BP_ErrorUserWidget.BP_ErrorUserWidget_C'"));
		ErrorPanel = CreateWidget<UErrorUserWidget>(GetOwningPlayerController(),Error_UserWidget);
	}
	return ErrorPanel;
}

void AFGHUD::ShowError()
{
	GetErrorPanel()->AddToViewport();
}

void AFGHUD::HideError()
{
	GetErrorPanel()->RemoveFromParent();
}

UErrorUserWidget* AFGHUD::ShowErrorMessage(FText title, FText content)
{
	GetErrorPanel()->SetErrorTitleAndContent(title,content);
	GetErrorPanel()->ToggleErrorPanel();
	return ErrorPanel;
}
