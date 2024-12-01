#include "WidgetItem.h"

#include "CustomDragDropOperation.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
///拖拽的点击
FReply UWidgetItem::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	
	//return FReply::Handled();//消耗点击
	//点击拖拽
	return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent,this,EKeys::LeftMouseButton).NativeReply;
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
