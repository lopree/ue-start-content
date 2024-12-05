#pragma once

#include "CoreMinimal.h"
#include "Inventory_ManagerBase.generated.h"

UCLASS()
class REPROJECT_API UInventory_ManagerBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void Install(){}
	virtual void Uninstall(){}
	
};
