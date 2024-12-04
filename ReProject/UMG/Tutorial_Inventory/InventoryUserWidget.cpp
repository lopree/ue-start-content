#include "InventoryUserWidget.h"

#include "InventoryCharacter.h"
#include "ItemSlotUserWidget.h"
#include "Components/BagActorComponent.h"
#include "Components/WrapBox.h"
#include "Kismet/GameplayStatics.h"

void UInventoryUserWidget::InitInventory()
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
}
