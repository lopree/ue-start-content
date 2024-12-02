#include "LoginUserWidget.h"

#include "FGHUD.h"
#include "MainMenuUserWidget.h"
#include "Components/Button.h"

bool ULoginUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		BackMainMenuButton = Cast<UButton>(GetWidgetFromName(TEXT("BackMain")));
		CreateRoomButton = Cast<UButton>(GetWidgetFromName(TEXT("CreateRoom")));
		return true; 
	}
	return false; 
}

void ULoginUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	hud = Cast<AFGHUD>(GetOwningPlayer()->GetHUD());
	BackMainMenuButton->OnClicked.AddDynamic(this,&ULoginUserWidget::BackMainMenuCallback);
	CreateRoomButton->OnClicked.AddDynamic(this,&ULoginUserWidget::CreateRoomCallback);
}

void ULoginUserWidget::CreateRoomCallback()
{
	hud->ShowErrorMessage(FText::FromString(TEXT("ERROR TITLE")),FText::FromString(TEXT("ERROR CONTENT")));
}

void ULoginUserWidget::BackMainMenuCallback()
{
	hud->MainMenuPanel->ReBackMainMenu();
	RemoveFromParent();
}
