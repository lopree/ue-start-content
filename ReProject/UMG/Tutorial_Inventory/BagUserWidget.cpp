#include "BagUserWidget.h"

#include "InventoryUserWidget.h"

void UBagUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//初始化背包，根据玩家背包组件中最大容量，初始化格数
	PlayerInventory->InitInventory();
}
