#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReProject/Inventory/Item/Inventory_ItemManager.h"
#include "Inventory_BFL.generated.h"

UCLASS()
class REPROJECT_API UInventory_BFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UInventory_ItemManager* GetItemManager(UObject* WorldContext);
	static FInventory_ItemDataBase* GetItemData(int32 item_id);

};
