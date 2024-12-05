#pragma once

#include "CoreMinimal.h"
#include "ReProject/Inventory/Tool/Inventory_ManagerBase.h"
#include "Inventory_ItemManager.generated.h"

struct FInventory_ItemDataBase;

UCLASS()
class REPROJECT_API UInventory_ItemManager : public UInventory_ManagerBase
{
	GENERATED_BODY()
public:
	virtual void Install() override;
	virtual void Uninstall() override;
	//根据ID获得物品使用的static mesh component
	FInventory_ItemDataBase* GetItem_StaticMeshComponent(int32 ID);
	
private:
	UPROPERTY()
	UDataTable* Equips_DataTable;
	UPROPERTY()
	UDataTable* Consume_DataTable;
	//所有的物品信息
	TMap<int32,FInventory_ItemDataBase*> Item_Data_Map;
	//从数据表中加载信息
	void LoadDataTable(UDataTable*& DataTable, const FString& Path);
};
