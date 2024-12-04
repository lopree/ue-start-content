#pragma once

#include "CoreMinimal.h"
#include "ItemSlotUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "InventoryUserWidget.generated.h"
class UWrapBox;
class UBagUIController;
UCLASS()
class REPROJECT_API UInventoryUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void InitInventory(UBagUIController* bag_ui_controller);
	//更新格子中的信息
	void UpdateSlotInfo();
protected:
	UPROPERTY()
	UBagUIController* BagUIController;
	UPROPERTY(meta=(BindWidget))
	UWrapBox* ItemGridWrapBox;
	//需要创建的格子类型
	UPROPERTY(EditAnywhere)
	TSubclassOf<UItemSlotUserWidget> item_slot;
};
