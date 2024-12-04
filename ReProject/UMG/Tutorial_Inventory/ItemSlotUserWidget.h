#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Manager/ItemManager.h"
#include "ItemSlotUserWidget.generated.h"
class UTextBlock;
class UImage;
UCLASS()
class REPROJECT_API UItemSlotUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//更新格子中的信息
	void UpdateSlotInfo(FItemDataBase* item_data,int32 item_counter);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* Item;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Item_Counter;
	
};
