#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetItem.generated.h"
class UTextBlock;
class UImage;

UCLASS()
class REPROJECT_API UWidgetItem : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* ArrowWidget;
	UPROPERTY(meta=(BindWidget))
	UImage* Icon;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* TileWidget;

	FVector2d MousePos;
	
};
