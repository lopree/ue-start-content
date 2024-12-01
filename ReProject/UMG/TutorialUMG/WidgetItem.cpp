#include "WidgetItem.h"
#include "CustomDragDropOperation.h"
#include "ListObject.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
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
	UListObject* item = Cast<UListObject>(ListItemObject);
	if (item)
	{
		TileWidget->SetText(FText::FromString(item->ItemName));
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("[rookstein]无法正常抓换"));
	}
}
