#include "TutorialHUD.h"

#include "Blueprint/UserWidget.h"

void ATutorialHUD::BeginPlay()
{
	Super::BeginPlay();
	//load class of widget
	TSubclassOf<UUserWidget> TestUserWidget = LoadClass<UUserWidget>(this,TEXT("/Game/Tutorial_UMG/BP/BP_TestUserWidget.BP_TestUserWidget_C"));
	//set widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetOwningPlayerController(),TestUserWidget);
	if (Widget)
	{
		Widget->AddToViewport();
	}
}
