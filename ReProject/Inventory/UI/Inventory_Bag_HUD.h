#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Inventory_Bag.h"
#include "Inventory_Bag_HUD.generated.h"

UCLASS()
class REPROJECT_API AInventory_Bag_HUD : public AHUD
{
	GENERATED_BODY()
public:
	//打开背包
	void ToggleBag();
private:
	UPROPERTY()
	UInventory_Bag* bag;
	//
	UInventory_Bag* GetBag();
	
};
