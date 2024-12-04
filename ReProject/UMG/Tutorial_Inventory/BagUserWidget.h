// Bag是直接展示在用户界面中的，其中含有
//player info面板以及inventory面板，这两个面板不需要canvas，因为作为子控件

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BagUserWidget.generated.h"

class UInventoryUserWidget;

UCLASS()
class REPROJECT_API UBagUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;
	UPROPERTY(meta = (BindWidget))
	UInventoryUserWidget* PlayerInventory;
};
