#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FGHUD.generated.h"

class UErrorUserWidget;
class ULoginUserWidget;
class UMainMenuUserWidget;

UCLASS()
class REPROJECT_API AFGHUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY()
	UMainMenuUserWidget* MainMenuPanel;
	UPROPERTY()
	ULoginUserWidget* LoginPanel;
	UPROPERTY()
	UErrorUserWidget* ErrorPanel;
	//main panel,主面板
	UMainMenuUserWidget* GetMainMenPanel();
	void ShowMainMenu();
	void HideMainMenu();
	//login panel 登录面板
	ULoginUserWidget* GetLoginPanel();
	void ShowLogin();
	void HideLogin();
	//error panel 错误面板
	UErrorUserWidget* GetErrorPanel();
	void ShowError();
	void HideError();

	//show error message
	UErrorUserWidget* ShowErrorMessage(FText title,FText content);
	
};
