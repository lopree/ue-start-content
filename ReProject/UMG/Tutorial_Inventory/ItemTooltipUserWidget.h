#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemTooltipUserWidget.generated.h"

UCLASS()
class REPROJECT_API UItemTooltipUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void UpdatePosition(FVector2d mouse_position);
};
