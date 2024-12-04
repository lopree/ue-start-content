#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Inventory_HUD.generated.h"
class UBagUserWidget;

UCLASS()
class REPROJECT_API AInventory_HUD : public AHUD
{
	GENERATED_BODY()
public:
	UBagUserWidget* GetBagUserWidget();
	void ShowBag();
	//改变bag ui显示的状态
	void ToggleBag();
protected:
	UPROPERTY()
	UBagUserWidget* BagPanel;
	
};
