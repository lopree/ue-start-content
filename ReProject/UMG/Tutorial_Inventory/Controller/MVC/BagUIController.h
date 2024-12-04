#pragma once

#include "CoreMinimal.h"
#include "ReProject/UMG/Tutorial_Inventory/InventoryUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "BagUIController.generated.h"
class AInventoryCharacter;
class UInventoryUserWidget;
UCLASS()
class REPROJECT_API UBagUIController : public UObject
{
	GENERATED_BODY()
public:
	void BindPlayerAndUI(AInventoryCharacter* player,UInventoryUserWidget* inventory_user_widget);
protected:
	UPROPERTY()
	AInventoryCharacter* Character;
	UPROPERTY()
	UInventoryUserWidget* InventoryUserWidger;
};
