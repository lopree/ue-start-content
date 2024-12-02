#include "LoginUserWidget.h"

#include "FGHUD.h"
#include "MainMenuUserWidget.h"
#include "Components/Button.h"

bool ULoginUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		BackMainMenuButton = Cast<UButton>(GetWidgetFromName(TEXT("BackMain")));
		return true; 
	}
	return false; 
}

void ULoginUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	hud = Cast<AFGHUD>(GetOwningPlayer()->GetHUD());
	BackMainMenuButton->OnClicked.AddDynamic(this,&ULoginUserWidget::BackMainMenuCallback);
}

void ULoginUserWidget::BackMainMenuCallback()
{
	hud->MainMenuPanel->ReBackMainMenu();
	RemoveFromParent();
}
