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
	eqt_normal UMETA(DisplayName = "Normal"),   // 普通物品
	eqt_rare UMETA(DisplayName = "Rare"),       // 稀有物品
	eqt_epic UMETA(DisplayName = "Epic"),       // 史诗物品
	eqt_legendary UMETA(DisplayName = "Legendary"), // 传说物品
	eqt_mythic UMETA(DisplayName = "Mythic")    // 神话物品
};
/** 定义物体的类型 **/
UENUM(BlueprintType)
enum class EInventory_Item_Type : uint8
{
	eit_equips UMETA(DisplayName = "Equips"),
	eit_consume   UMETA(DisplayName = "Consume"),
	eit_misc UMETA(DisplayName = "Misc"),
};

//=====================================
//定义结构体
//=====================================
/** 定义物品的基本信息 **/
USTRUCT()
struct FInventory_ItemDataBase : public FTableRowBase
{
	GENERATED_BODY()
	//id
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 item_id;
	//物品名
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText item_name;
	//icon
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* item_sprite;
	//mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* item_static_mesh_component;
	//描述
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	
	FText item_description;
	//物品类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventory_Item_Type item_type;
	//稀有度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInventory_Quality_Type item_quality;
	//价格
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 item_value;
	//最大堆叠数量
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 item_max_stack = 1;
};
///消耗品数据
USTRUCT(BlueprintType)
struct FInventory_ConsumableData : public FInventory_ItemDataBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float exp;
};
///装备数据
USTRUCT(BlueprintType)
struct FInventory_EquipData : public FInventory_ItemDataBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 defense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 mp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 critical;
};
