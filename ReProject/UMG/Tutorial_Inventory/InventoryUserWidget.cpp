#include "InventoryUserWidget.h"

#include "InventoryCharacter.h"
#include "ItemSlotUserWidget.h"
#include "Components/BagActorComponent.h"
#include "Components/WrapBox.h"
#include "Controller/MVC/BagUIController.h"
#include "Kismet/GameplayStatics.h"
#include "Manager/ItemManager.h"
#include "Tool/InventoryBFL.h"

void UInventoryUserWidget::InitInventory(UBagUIController* bag_ui_controller)
{
	//获得设定的背包容量
	if (AInventoryCharacter* player = Cast<AInventoryCharacter>(UGameplayStatics::GetPlayerCharacter(this,0)))
	{
		int32 bag_max_stack = player->GetBagActorComponent()->GetBagStack();
		for (int32 i = 0; i < bag_max_stack; i++)
		{
			if (UItemSlotUserWidget* item = CreateWidget<UItemSlotUserWidget>(GetOwningPlayer(),item_slot))
			{
				ItemGridWrapBox->AddChild(item);
			}
		}
	}

	this->BagUIController = bag_ui_controller;
}

void UInventoryUserWidget::UpdateSlotInfo()
{
	//格子位置，以及格子信息
	TMap<int32,FGridData> SlotInfoMap = BagUIController->GetPlayerBagItemsData();
	for (auto& SlotInfo : SlotInfoMap)
	{
		FItemDataBase* item_data = UInventoryBFL::GetItemManager(this)->GetItemData(SlotInfo.Value.Item_ID);
		if (!item_data)
		{
			UE_LOG(LogTemp, Warning, TEXT("[rookstein]背包中的数据在数据管理器中不存在"));
			continue;
		}
		//获取到具体的格子中的信息（修改图片）
		if (UItemSlotUserWidget* grid_slot = Cast<UItemSlotUserWidget>(ItemGridWrapBox->GetChildAt(SlotInfo.Key)))
		{
			grid_slot->UpdateSlotInfo(item_data, SlotInfo.Value.Item_Counter);
		}
	}
}
