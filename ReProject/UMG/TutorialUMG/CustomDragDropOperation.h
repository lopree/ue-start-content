#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "CustomDragDropOperation.generated.h"

UCLASS()
class REPROJECT_API UCustomDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()
public:
	FVector2D DragOffset;
	
};
