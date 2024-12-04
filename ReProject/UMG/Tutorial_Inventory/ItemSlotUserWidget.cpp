#include "ItemSlotUserWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"

void UItemSlotUserWidget::UpdateSlotInfo(FItemDataBase* item_data,int32 item_counter)
{
	FSlateBrush brush;
	brush.TintColor = FLinearColor(1, 1, 1, 1);
	brush.SetResourceObject(item_data->Item_Sprite);
	Item->SetBrush(brush);
	if (item_counter >1)
	{
		Item_Counter->SetText(FText::AsNumber(item_counter));
	}
}
