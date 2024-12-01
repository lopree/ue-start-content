#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ListObject.generated.h"

UCLASS()
class REPROJECT_API UListObject : public UObject
{
	GENERATED_BODY()
public:
	int32 Level;
	FString ItemName;
	UPROPERTY()
	TArray<UListObject*> Children;
	//创建子物体
	void CreatChildObject();
	
};
