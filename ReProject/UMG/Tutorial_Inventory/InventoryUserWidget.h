#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryUserWidget.generated.h"
class UWrapBox;

UCLASS()
class REPROJECT_API UInventoryUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void InitInventory();
protected:
	UPROPERTY(meta=(BindWidget))
	UWrapBox* ItemGridWrapBox;
	//需要创建的格子类型
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> item_slot;
};
