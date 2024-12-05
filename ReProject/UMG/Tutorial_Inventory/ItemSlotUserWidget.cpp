#include "ItemSlotUserWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Tool/InventoryBFL.h"

UItemSlotUserWidget::UItemSlotUserWidget(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	ItemID = -1;
}

void UItemSlotUserWidget::UpdateSlotInfo(FItemDataBase* item_data,int32 item_counter) 
{
	//设置图片内容
	FSlateBrush brush;
	brush.TintColor = FLinearColor(1, 1, 1, 1);
	brush.SetResourceObject(item_data->Item_Sprite);
	Item->SetBrush(brush);
	//设置数量
	if (item_counter >1)
	{
		Item_Counter->SetText(FText::AsNumber(item_counter));
	}
	//设定边框颜色
	Outline->SetBrushTintColor(UInventoryBFL::GetItemQuality(item_data->Item_Quality));
	//
	ItemID = item_data->Item_ID;
}

void UItemSlotUserWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (ItemID!=-1)
	{
		Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
		UInventoryBFL::GetHUD(this)->ShowItemInfo(nullptr,ItemID);
	}
}

FReply UItemSlotUserWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (ItemID!=-1)
	{
		FVector2d MousePos;
		UGameplayStatics::GetPlayerController(this,0)->GetMousePosition(MousePos.X,MousePos.Y);
		UInventoryBFL::GetHUD(this)->UpdateItemInfoPosition(MousePos);
	}
	return FReply::Unhandled();
}

void UItemSlotUserWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	if (ItemID!=-1)
	{
		Super::NativeOnMouseLeave(InMouseEvent);
		UInventoryBFL::GetHUD(this)->HideItemInfo();
	}
}
