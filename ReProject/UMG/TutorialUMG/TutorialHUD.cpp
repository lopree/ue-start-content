#include "TutorialHUD.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

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
	//set mouse cursor
	// 获取玩家控制器
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		// 显示鼠标
		PlayerController->bShowMouseCursor = true;
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("[rookstein]cant find player"));
	}
}
