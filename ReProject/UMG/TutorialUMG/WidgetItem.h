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
	protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* ArrowWidget;
	UPROPERTY(meta=(BindWidget))
	UImage* Icon;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* TileWidget;
};
