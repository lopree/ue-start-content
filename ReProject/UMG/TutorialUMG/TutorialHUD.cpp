#include "TutorialHUD.h"

#include "Blueprint/UserWidget.h"

void ATutorialHUD::BeginPlay()
{
	Super::BeginPlay();
	//load class of widget
	TSubclassOf<UUserWidget> TestUserWidget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_UMG/BP/BP_TutorialUserWidget.BP_TutorialUserWidget_C'"));
	//set widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetOwningPlayerController(),TestUserWidget);
	if (Widget)
	{
		Widget->AddToViewport();
	}
}
