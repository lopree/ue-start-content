#include "BagActorComponent.h"

#include "ReProject/UMG/Tutorial_Inventory/Manager/ItemManager.h"
#include "ReProject/UMG/Tutorial_Inventory/Tool/InventoryBFL.h"

UBagActorComponent::UBagActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	//默认的堆叠数量
	MaxBagStack = 30;
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
	//临时的格子数据
	struct FGridTemp
	{
		int32 Grid_Site;//格子的位置
		int32 Need_Add_Item_Counter;//格子中存储的物品数量
	};
	//返回是否存储成功
	bool bSuccess = false;
	UItemManager* ItemMgr = UInventoryBFL::GetItemManager(this);
	if (!ItemMgr) return false;
	//第一步，先查询要存储的item是否可以堆叠
	//可以堆叠的为消耗品
	//不可堆叠的可装备物品
	if (ItemMgr->CheckCanStack(Item_ID))
	{
		int32 _item_counter = Item_Counter;//需要添加的物品数量
		int32 _max_stack = ItemMgr->GetItemMaxStack(Item_ID);
		if (_max_stack == -1) return false;
		//存储临时格子的数组
		//临时的格子信息，里面存储这个物品的位置，以及需要往这个格子里添加的物品数量
		TArray<FGridTemp> GridTempArray;
		//遍历格子
		for (auto& grid : GridMap)
		{
			//查找是否有要存储的物品id
			if (grid.Value.Item_ID == Item_ID)
			{
				int32 need_add_counter = _max_stack - grid.Value.Item_Counter;//可容纳最大数量减去格子中已经存储的物品数量
				if (need_add_counter > 0)//如果这个格子可以容纳物品，则将需要添加的减少这一部分。
				{
					_item_counter -= need_add_counter;
					FGridTemp grid_temp;
					grid_temp.Grid_Site = grid.Key;
					grid_temp.Need_Add_Item_Counter = need_add_counter;
					GridTempArray.Add(grid_temp);
				}
			}
		}
		//如果所有已有物品，往里面添加物品后，需要添加的物品还有剩余
		if (_item_counter > 0)
		{
			for (int32 i = 0; i < MaxBagStack && _item_counter > 0; i++)
			{
				if (!GridMap.Contains(i))//如果格子数组中没有记录这个格子被使用
				{
					FGridTemp grid_temp;
					grid_temp.Grid_Site = i;
					grid_temp.Need_Add_Item_Counter = _item_counter >= _max_stack ? _max_stack : _item_counter;
					GridTempArray.Add(grid_temp);
					_item_counter -= _max_stack;
				}
			}
		}
		///如果此时手中持有数量仍然大于0，背包控件不足
		if (_item_counter > 0)
		{
			return false;
		}

		bSuccess = true;
		//数据回填，将临时的格子信息中的信息填入Gridmap
		for (auto& grid_temp : GridTempArray)
		{
			if (GridMap.Contains(grid_temp.Grid_Site))
			{
				GridMap[grid_temp.Grid_Site].Item_Counter += grid_temp.Need_Add_Item_Counter;
			}else
			{
				//新格子
				FGridData GD(Item_ID,grid_temp.Need_Add_Item_Counter);
				GridMap.Add(grid_temp.Grid_Site,GD);
			}
		}
	}else
	{
		int32 free_grid_site = GetFreeSite();
		if (free_grid_site != -1)
		{
			GridMap.Add(free_grid_site,FGridData(Item_ID,1));
			bSuccess = true;
		}
	}
	return bSuccess;
}

int32 UBagActorComponent::GetFreeSite()
{
	for (int32 i = 0; i < MaxBagStack; i++)
	{
		if (!GridMap.Contains(i))
		{
			return i;
		}
	}
	return -1;
}

