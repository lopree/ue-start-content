#include "TutorialUserWidget.h"

#include "CustomDragDropOperation.h"
#include "ListObject.h"
#include "WidgetItem.h"
#include "Blueprint/DragDropOperation.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "Components/TreeView.h"

bool UTutorialUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		NameText = Cast<UTextBlock>(GetWidgetFromName(TEXT("NameBlock")));
		return true; 
	}
	return false; 
}


void UTutorialUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	AddItemButton->OnClicked.AddDynamic(this, &UTutorialUserWidget::AddCallback);
}

void UTutorialUserWidget::AddCallback()
{
	for (int32 i = 0; i < 10; i++)
	{
		UListObject* item = NewObject<UListObject>(this);
		item->ItemName = FString::Printf(TEXT("Item %i"), i);
		item->CreatChildObject();
		CustomTreeView->AddItem(item);
	}
	//为子控件添加点击事件
	CustomTreeView->SetOnGetItemChildren(this, &UTutorialUserWidget::OnGetItemChildren);
}

void UTutorialUserWidget::OnGetItemChildren(UObject* Item, TArray<UObject*>& Children)
{
	if (UListObject* item = Cast<UListObject>(Item))
	{
		Children.Append(item->Children);
		
	}
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

void UTutorialUserWidget::OnTreeItemClicked(UObject* obj)
{
	UListObject* item = Cast<UListObject>(obj);
	//改变开始的箭头方向
	if (item->widget_item)
	{
		item->bOpen = !item->bOpen;
		FString state = item->bOpen ? TEXT("v") : TEXT(">");
		item->widget_item->ArrowWidget->SetText(FText::FromString(state));
	}
}
