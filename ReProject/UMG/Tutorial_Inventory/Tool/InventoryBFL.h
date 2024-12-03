#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventoryBFL.generated.h"

class UItemManager;

UCLASS()
class REPROJECT_API UInventoryBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UItemManager* GetItemManager(UObject* WorldContext);
};
