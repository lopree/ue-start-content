#include "TutorialUserWidget.h"

#include "CustomDragDropOperation.h"
#include "WidgetItem.h"
#include "Blueprint/DragDropOperation.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"

bool UTutorialUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		NameText = Cast<UTextBlock>(GetWidgetFromName(TEXT("NameBlock")));
		return true; 
	}
	return false; 
}

void UTutorialUserWidget::ChangeText()
{
	//NameText->SetText(NSLOCTEXT("FGG","K1","文本"));
	//NameText->SetText(FText::FromString("文本")); 会出错
	FString target_text = TEXT("文本更改"); 
	NameText->SetText(FText::FromString(target_text));
}

bool UTutorialUserWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	//获取鼠标的位置
	FVector2d new_pos = USlateBlueprintLibrary::AbsoluteToLocal(InGeometry,InDragDropEvent.GetScreenSpacePosition());
	//修改拖拽物体的位置
	UWidgetItem* widget_item = Cast<UWidgetItem>(InOperation->Payload);
	if (widget_item != nullptr)
	{
		Cast<UCanvasPanelSlot>(widget_item->Slot)->SetPosition(new_pos-widget_item->DragDropOperation->DragOffset);
	}
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}
