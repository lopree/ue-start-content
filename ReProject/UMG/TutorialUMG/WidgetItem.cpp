#include "WidgetItem.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
///拖拽的点击
FReply UWidgetItem::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	
	//return FReply::Handled();//消耗点击
	//mouse position
	MousePos = USlateBlueprintLibrary::AbsoluteToLocal(InGeometry,InMouseEvent.GetScreenSpacePosition());
	//霍比奥点击拖拽
	return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent,this,EKeys::LeftMouseButton).NativeReply;
}
///拖拽过程
void UWidgetItem::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDropOperation::StaticClass());
	OutOperation->Payload = this;
	OutOperation->DefaultDragVisual = this;
}
