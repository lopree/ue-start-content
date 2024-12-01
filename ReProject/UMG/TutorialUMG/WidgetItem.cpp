#include "WidgetItem.h"
#include "CustomDragDropOperation.h"
#include "ListObject.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Border.h"
#include "Components/SizeBoxSlot.h"
#include "Components/TextBlock.h"
///拖拽的点击
FReply UWidgetItem::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	
	//return FReply::Handled();//消耗点击
	//点击拖拽
	//return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent,this,EKeys::LeftMouseButton).NativeReply;
	return FReply::Unhandled();
}
///拖拽过程
void UWidgetItem::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	
	DragDropOperation = NewObject<UCustomDragDropOperation>();
	DragDropOperation->DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	DragDropOperation->Payload = this;
	DragDropOperation->DefaultDragVisual = this;
	DragDropOperation->Pivot = EDragPivot::MouseDown;
	
	OutOperation = DragDropOperation;
}

void UWidgetItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	//将这个widget item的信息设置成传进来的参数
	if (UListObject* item = Cast<UListObject>(ListItemObject))
	{
		TileWidget->SetText(FText::FromString(item->ItemName));
		//为子控件设定缩进
		if (USizeBoxSlot* size_slot = Cast<USizeBoxSlot>(ItemBorder->Slot))
		{
			size_slot->SetPadding(FMargin(20*item->Level,0,0,0));
		}
		ArrowWidget->SetVisibility(item->Children.Num() == 0 ? ESlateVisibility::Hidden : ESlateVisibility::Visible);
		//更新信息
		item->widget_item = this;

		FString state = item->bOpen ? TEXT("v") : TEXT(">");
		ArrowWidget->SetText(FText::FromString(state));
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("[rookstein]无法正常抓换"));
	}
}
