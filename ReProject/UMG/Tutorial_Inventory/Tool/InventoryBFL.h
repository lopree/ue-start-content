#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReProject/UMG/Tutorial_Inventory/Inventory_HUD.h"
#include "ReProject/UMG/Tutorial_Inventory/Manager/ItemManager.h"
#include "InventoryBFL.generated.h"

class UItemManager;

UCLASS()
class REPROJECT_API UInventoryBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UItemManager* GetItemManager(UObject* WorldContext);
	//根据稀有度更改边框颜色
	static FLinearColor GetItemQuality(EQualityType item_quality);
	//get hud
	static AInventory_HUD* GetHUD(UObject* world_context);
};
