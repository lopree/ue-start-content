#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "WidgetItem.generated.h"
class UTextBlock;
class UImage;
class UCustomDragDropOperation;
UCLASS()
class REPROJECT_API UWidgetItem : public UUserWidget,public IUserObjectListEntry
{
	GENERATED_BODY()
public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* ArrowWidget;
	UPROPERTY(meta=(BindWidget))
	UImage* Icon;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* TileWidget;

	UCustomDragDropOperation* DragDropOperation;

	
	
};
