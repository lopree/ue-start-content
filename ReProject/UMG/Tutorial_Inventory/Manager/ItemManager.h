#pragma once

#include "CoreMinimal.h"
#include "ManagerBase.h"
#include "UObject/NoExportTypes.h"
#include "ItemManager.generated.h"

class UDataTable;

/// 物品种类：消耗性的道具id从1000开始，别的从1开始
UENUM(BlueprintType)
enum class EItemType : uint8
{
	EIT_Consumable UMETA(DisplayName = "Consumable"),       // 消耗品
	EIT_Shoulder UMETA(DisplayName = "Shoulder"),           // 肩部
	EIT_Armor UMETA(DisplayName = "Armor"),                 // 护甲
	EIT_Helmet UMETA(DisplayName = "Helmet"),               // 头盔
	EIT_Boots UMETA(DisplayName = "Boots"),                 // 靴子
	EIT_Weapon UMETA(DisplayName = "Weapon"),               // 武器
	EIT_Accessory UMETA(DisplayName = "Accessory"),         // 配饰
};
///稀有度
UENUM(BlueprintType)  // BlueprintType 使得该枚举可以在蓝图中使用
enum class EQualityType : uint8
{
	EQT_Normal UMETA(DisplayName = "Normal"),   // 普通物品
	EQT_Rare UMETA(DisplayName = "Rare"),       // 稀有物品
	EQT_Epic UMETA(DisplayName = "Epic"),       // 史诗物品
	EQT_Legendary UMETA(DisplayName = "Legendary"), // 传说物品
	EQT_Mythic UMETA(DisplayName = "Mythic")    // 神话物品
};
///创建蓝图可调用的Data数据表

USTRUCT(BlueprintType)
struct FItemDataBase : public FTableRowBase
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
	EItemType Item_Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQualityType Item_Quality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Value;//价格
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Item_Max_Stack;//最大堆叠数量
};
///消耗品数据
USTRUCT(BlueprintType)
struct FConsumableData : public FItemDataBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HPValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MPValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ExpValue;
};
///装备数据
USTRUCT(BlueprintType)
struct FEquipData : public FItemDataBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Critical;
};

UCLASS()
class REPROJECT_API UItemManager : public UManagerBase
{
	GENERATED_BODY()
public:
	virtual void Install() override;
	virtual void Uninstall() override;

	bool CheckCanStack(int32 ID){return ID>=1000;}
	//获得物品信息
	FItemDataBase* GetItemData(int32 ID);
	//获得最大堆叠数量
	int32 GetItemMaxStack(int32 ID);
protected:
	//将物品数据加载到内存中
	UPROPERTY()
	UDataTable* EquipDataTable;
	UPROPERTY()
	UDataTable* ConsumableDataTable;
	
};
