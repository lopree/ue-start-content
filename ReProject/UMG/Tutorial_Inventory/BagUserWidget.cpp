#include "BagUserWidget.h"

#include "InventoryCharacter.h"
#include "InventoryUserWidget.h"
#include "Controller/MVC/BagUIController.h"
#include "Kismet/GameplayStatics.h"

void UBagUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	//绑定控制器和模型
	UIController = NewObject<UBagUIController>(this);
	UIController->BindPlayerAndUI(Cast<AInventoryCharacter>(UGameplayStatics::GetPlayerCharacter(this,0)),this);

	//初始化背包，根据玩家背包组件中最大容量，初始化格数
	BP_InventoryUserWidget->InitInventory(UIController);
	BP_InventoryUserWidget->UpdateSlotInfo();
}
