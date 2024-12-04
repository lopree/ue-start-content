#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Manager/ItemManager.h"
#include "Inventory_HUD.generated.h"
class UBagUserWidget;
class UItemTooltipUserWidget;
UCLASS()
class REPROJECT_API AInventory_HUD : public AHUD
{
	GENERATED_BODY()
public:
	UBagUserWidget* GetBagUserWidget();
	void ShowBag();
	//改变bag ui显示的状态
	void ToggleBag();
	//隐藏和显示item的信息
	void ShowItemInfo(FItemDataBase* item_data,int32 item_id = -1);
	void HideItemInfo();

	void UpdateItemInfoPosition(FVector2d mouse_pos);
protected:
	UPROPERTY()
	UBagUserWidget* BagPanel;
	UPROPERTY()
	UItemTooltipUserWidget* ItemTooltip;
	
};
