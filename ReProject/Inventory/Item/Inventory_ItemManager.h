#pragma once

#include "CoreMinimal.h"
#include "Inventory_ItemManager.generated.h"

UCLASS()
class REPROJECT_API UInventory_ItemManager : public UObject
{
	GENERATED_BODY()
public:
	//根据ID获得物品使用的static mesh component
	UStaticMeshComponent* GetItem_StaticMeshComponent(int32 ID);
	
private:
	UPROPERTY()
	UDataTable* Equips_DataTable;
};
