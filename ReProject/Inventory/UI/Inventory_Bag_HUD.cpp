#include "Inventory_Bag_HUD.h"
#include "Blueprint/UserWidget.h"

void AInventory_Bag_HUD::ToggleBag()
{
	if (!GetBag()->IsInViewport())
	{
		GetBag()->AddToViewport();
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		PC->bShowMouseCursor = true;
	}else
	{
		GetBag()->RemoveFromParent();
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		PC->bShowMouseCursor = false;
	}
}

UInventory_Bag* AInventory_Bag_HUD::GetBag()
{
	if (!bag)
	{
		TSubclassOf<UUserWidget> bag_widget = LoadClass<UUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Demo_Inventory/BP/UI/BP_Inventory_Bag.BP_Inventory_Bag_C'"));
		bag = CreateWidget<UInventory_Bag>(GetOwningPlayerController(),bag_widget);
	}
	return bag;
}
