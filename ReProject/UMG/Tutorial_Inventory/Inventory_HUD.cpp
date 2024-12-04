#include "Inventory_HUD.h"

#include "BagUserWidget.h"
#include "Blueprint/UserWidget.h"

UBagUserWidget* AInventory_HUD::GetBagUserWidget()
{
	if (!BagPanel)
	{
		TSubclassOf<UUserWidget> bag_widget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_Inventory01/BP/BP_BagUserWidget.BP_BagUserWidget_C'"));
		BagPanel = CreateWidget<UBagUserWidget>(GetOwningPlayerController(),bag_widget);
	}
	return BagPanel;
}

void AInventory_HUD::ShowBag()
{
	if (!GetBagUserWidget()->IsInViewport())
	{
		GetBagUserWidget()->AddToViewport();
	}
}

void AInventory_HUD::ToggleBag()
{
	if (!GetBagUserWidget()->IsInViewport())
	{
		GetBagUserWidget()->AddToViewport();
	}else
	{
		GetBagUserWidget()->RemoveFromViewport();
	}
}

