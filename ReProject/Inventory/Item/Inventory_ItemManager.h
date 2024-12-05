#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory_ItemManager.generated.h"
/// 物品种类：消耗性的道具id从1000开始，别的从1开始
///稀有度
UENUM(BlueprintType)  // BlueprintType 使得该枚举可以在蓝图中使用
enum class EInventory_QualityType : uint8
{
	EQT_Normal UMETA(DisplayName = "Normal"),   // 普通物品
	EQT_Rare UMETA(DisplayName = "Rare"),       // 稀有物品
	EQT_Epic UMETA(DisplayName = "Epic"),       // 史诗物品
	EQT_Legendary UMETA(DisplayName = "Legendary"), // 传说物品
	EQT_Mythic UMETA(DisplayName = "Mythic")    // 神话物品
};
// 定义外层的枚举
UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	IC_None UMETA(DisplayName = "None"),
	IC_Equips UMETA(DisplayName = "Equips"),
	IC_Consume   UMETA(DisplayName = "Consume"),
	IC_Misc UMETA(DisplayName = "Misc"),
};

// 定义内层的枚举
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	WT_Sword   UMETA(DisplayName = "Sword"),
	WT_Bow     UMETA(DisplayName = "Bow"),
	WT_Axe     UMETA(DisplayName = "Axe"),
};

USTRUCT(BlueprintType)
struct FInventory_ItemDataBase : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Item_Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Item_Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* Item_SkeletalMesh;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	
	FText Item_Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemCategory Item_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventory_QualityType Item_Quality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Value;//价格
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Max_Stack;//最大堆叠数量
};
UCLASS()
class REPROJECT_API UInventory_ItemManager : public UObject
{
	GENERATED_BODY()
	
};
