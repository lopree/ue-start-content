#include "InventoryBFL.h"

#include "Kismet/GameplayStatics.h"
#include "ReProject/UMG/Tutorial_Inventory/Manager/ItemManager.h"  
#include "ReProject/UMG/Tutorial_Inventory/CharacterEnum.h"
#include "ReProject/UMG/Tutorial_Inventory/Manager/InventoryGameInstance.h"

UItemManager* UInventoryBFL::GetItemManager(UObject* WorldContext)
{
	if (UInventoryGameInstance* gi = Cast<UInventoryGameInstance>(WorldContext->GetWorld()->GetGameInstance()))
	{
		UItemManager* ItemManager = gi->GetManager<UItemManager>(MGRID_ITEM);

		return ItemManager;
	}
	return nullptr;
}

FLinearColor UInventoryBFL::GetItemQuality(EQualityType item_quality)
{
	FLinearColor color;
	switch (item_quality)
	{
	case EQualityType::EQT_Normal:
		// 普通：白色
			color = FLinearColor::White;
		break;

	case EQualityType::EQT_Rare:
		// 稀有：蓝色
			color = FLinearColor(0.2f, 0.4f, 1.0f); // 浅蓝色，更有饱和度
		break;

	case EQualityType::EQT_Epic:
		// 史诗：紫色
			color = FLinearColor(0.75f, 0.0f, 1.0f); // 高饱和度紫色
		break;

	case EQualityType::EQT_Legendary:
		// 传说：金色
			color = FLinearColor(1.0f, 0.75f, 0.0f); // 明亮金色
		break;

	case EQualityType::EQT_Mythic:
		// 神话：红色
			color = FLinearColor(1.0f, 0.0f, 0.0f); // 高饱和度的红色
		break;

	default:
		// 默认：如果没有设置则为白色
			color = FLinearColor::White;
		break;
	}
	return color;
}

AInventory_HUD* UInventoryBFL::GetHUD(UObject* world_context)
{
	return Cast<AInventory_HUD>(UGameplayStatics::GetPlayerController(world_context,0)->GetHUD());
}
