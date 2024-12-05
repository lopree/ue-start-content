#include "ItemTooltipUserWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Tool/InventoryBFL.h"

void UItemTooltipUserWidget::UpdatePosition(FVector2d mouse_position)
{
	SetPositionInViewport(mouse_position); 
}

void UItemTooltipUserWidget::InitTooltip(FItemDataBase* data_base, int32 item_id)
{
	if (data_base == nullptr)
	{
		data_base = UInventoryBFL::GetItemManager(this)->GetItemData(item_id);
	}

	ItemName->SetText(data_base->Item_Name);
	FSlateBrush brush;
	brush.SetResourceObject(data_base->Item_Sprite);
	ItemIcon->SetBrush(brush);
	//
	ItemFrame->SetBrushTintColor(UInventoryBFL::GetItemQuality(data_base->Item_Quality));
	ItemQuality->SetText(data_base->Item_Description);
}
