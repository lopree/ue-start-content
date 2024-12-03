#include "BagActorComponent.h"

#include "ReProject/UMG/Tutorial_Inventory/Manager/ItemManager.h"
#include "ReProject/UMG/Tutorial_Inventory/Tool/InventoryBFL.h"

UBagActorComponent::UBagActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	//默认的堆叠数量
	MaxStack = 30;
}

void UBagActorComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UBagActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UBagActorComponent::AddItem(int32 Item_ID, int32 Item_Counter)
{
	bool bSuccess = false;
	//第一步，先查询要存储的item是否可以堆叠
	//可以堆叠的为消耗品
	//不可堆叠的可装备物品
	if (UInventoryBFL::GetItemManager(this)->CheckCanStack(Item_ID))
	{
		
	}else
	{
		int32 free_grid_site = GetFreeSite();
		if (free_grid_site != -1)
		{
			//GridMap.Add(free_grid_site,FGridData(Item_ID,1));
			bSuccess = true;
		}
	}
	return bSuccess;
}

int32 UBagActorComponent::GetFreeSite()
{
	for (int32 i = 0; i < MaxStack; i++)
	{
		if (!GridMap.Contains(i))
		{
			return i;
		}
	}
	return -1;
}

