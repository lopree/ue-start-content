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
	UItemSlotUserWidget(const FObjectInitializer& ObjectInitializer);
	//更新格子中的信息
	void UpdateSlotInfo(FItemDataBase* item_data,int32 item_counter);

protected:
	UPROPERTY(meta = (BindWidget))
	UImage* Item;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Item_Counter;
	UPROPERTY(meta = (BindWidget))
	UImage* Outline;
	//鼠标悬停显示
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

	//记录这个格子物品的id
	int32 ItemID;
	
};
