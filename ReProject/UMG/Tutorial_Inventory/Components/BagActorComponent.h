#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BagActorComponent.generated.h"
///每一个格子的信息
USTRUCT(BlueprintType)
struct FGridData
{
	GENERATED_BODY()
	// 默认构造函数
	FGridData()
		: Item_ID(0), Item_Counter(0)  // 给成员变量一个默认值
	{
	}

	// 带参数的构造函数
	FGridData(int32 InItem_ID, int32 InItem_Counter)
		: Item_ID(InItem_ID), Item_Counter(InItem_Counter)
	{
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Counter;

	
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REPROJECT_API UBagActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBagActorComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//获取物品堆叠数量
	int32 GetItemStack(){return MaxBagStack;}
	//往背包中添加item
	bool AddItem(int32 Item_ID,int32 Item_Counter);
protected:
	UPROPERTY(EditAnywhere)
	int32 MaxBagStack;//背包容量
	//存储已经存放item的格子信息
	TMap<int32, FGridData> GridMap;
	//查询空闲的格子
	int32 GetFreeSite();
};
