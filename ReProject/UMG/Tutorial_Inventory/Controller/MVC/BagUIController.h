#pragma once

#include "CoreMinimal.h"
#include "ReProject/UMG/Tutorial_Inventory/InventoryUserWidget.h"
#include "ReProject/UMG/Tutorial_Inventory/Components/BagActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "BagUIController.generated.h"
class AInventoryCharacter;
class UBagUserWidget;
UCLASS()
class REPROJECT_API UBagUIController : public UObject
{
	GENERATED_BODY()
public:
	void BindPlayerAndUI(AInventoryCharacter* player,UBagUserWidget* bag_user_widget);
	TMap<int32,FGridData> GetPlayerBagItemsData();
protected:
	UPROPERTY()
	AInventoryCharacter* Character;
	UPROPERTY()
	UBagUserWidget* BagUserWidget;
};
