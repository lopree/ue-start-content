#include "Inventory_HUD.h"

#include "BagUserWidget.h"
#include "ItemTooltipUserWidget.h"
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

void AInventory_HUD::ShowItemInfo(FItemDataBase* item_data,int32 item_id)
{
	if (!ItemTooltip)
	{
		TSubclassOf<UItemTooltipUserWidget> tooltip_widget = LoadClass<UItemTooltipUserWidget>(this,TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Tutorial_Inventory01/BP/BP_ItemTooltipUserWidget.BP_ItemTooltipUserWidget_C'"));
		ItemTooltip = CreateWidget<UItemTooltipUserWidget>(GetOwningPlayerController(),tooltip_widget);
	}
	if (!ItemTooltip->IsInViewport())
	{
		ItemTooltip->InitTooltip(item_data,item_id);
		ItemTooltip->AddToViewport();
		ItemTooltip->SetDesiredSizeInViewport(FVector2d(330,400));
	}
}

void AInventory_HUD::HideItemInfo()
{
	if (!ItemTooltip)
	{
		return;
	}

	ItemTooltip->RemoveFromParent();
}

void AInventory_HUD::UpdateItemInfoPosition(FVector2d mouse_pos)
{
	if (!ItemTooltip)
	{
		return;
	}
	ItemTooltip->UpdatePosition(mouse_pos);
}

