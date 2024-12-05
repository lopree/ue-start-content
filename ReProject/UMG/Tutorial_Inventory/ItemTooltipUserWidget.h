#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Manager/ItemManager.h"
#include "ItemTooltipUserWidget.generated.h"
class UImage;
class UTextBlock;
UCLASS()
class REPROJECT_API UItemTooltipUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void UpdatePosition(FVector2d mouse_position);
	//初始化icon以及名称
	void InitTooltip(FItemDataBase* data_base,int32 item_id);
protected:
	UPROPERTY(meta = (BindWidget))
	UImage* ItemIcon;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemName;
	UPROPERTY(meta = (BindWidget))
	UImage* ItemFrame;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemQuality;
};
