#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Inventory_Constant.generated.h"
//=====================================
//常量
//=====================================
//存储物品的管理器序号
#define INVENTORY_ITEM_MANAGER_INDEX 0
//=====================================
//定义枚举
//=====================================
/** 物品的稀有度 **/
UENUM(BlueprintType)
enum class EInventory_Quality_Type : uint8
{
	EQT_Normal UMETA(DisplayName = "Normal"),   // 普通物品
	EQT_Rare UMETA(DisplayName = "Rare"),       // 稀有物品
	EQT_Epic UMETA(DisplayName = "Epic"),       // 史诗物品
	EQT_Legendary UMETA(DisplayName = "Legendary"), // 传说物品
	EQT_Mythic UMETA(DisplayName = "Mythic")    // 神话物品
};
/** 定义物体的类型 **/
UENUM(BlueprintType)
enum class EInventory_Item_Type : uint8
{
	EIT_Equips UMETA(DisplayName = "Equips"),
	EIT_Consume   UMETA(DisplayName = "Consume"),
	EIT_Misc UMETA(DisplayName = "Misc"),
};

//=====================================
//定义结构体
//=====================================
/** 定义物品的基本信息 **/
USTRUCT()
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
	UStaticMeshComponent* Item_Static_Mesh_Component;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	
	FText Item_Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventory_Item_Type Item_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventory_Quality_Type Item_Quality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Value;//价格
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Max_Stack;//最大堆叠数量
};
