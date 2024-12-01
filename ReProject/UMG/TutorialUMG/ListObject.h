#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ListObject.generated.h"
class UWidgetItem;
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
	//所属控件信息
	UPROPERTY()
	UWidgetItem* widget_item;
	//是否打开
	bool bOpen;
};
