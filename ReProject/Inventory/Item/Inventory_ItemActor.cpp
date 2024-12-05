#include "Inventory_ItemActor.h"

#include "Inventory_ItemManager.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "ReProject/Inventory/Tool/Inventory_BFL.h"
#include "ReProject/Inventory/Tool/Inventory_Constant.h"
#include "ReProject/Inventory/Tool/Inventory_GameInstance.h"
#include "ReProject/Inventory/Tool/Inventory_ManagerBase.h"

AInventory_ItemActor::AInventory_ItemActor()
{
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");
	StaticMeshComponent->SetupAttachment(RootComponent);
	
	// 设置静态网格组件的网格为方形（Cube）
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (CubeMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(CubeMesh.Object);  // 设置方形网格
	}

	// 可选：设置立方体的尺寸和位置
	StaticMeshComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));  // 设置方形的缩放比例
	StaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));  // 设置方形的位置
	StaticMeshComponent->SetEnableGravity(true);  // 启用重力
	StaticMeshComponent->SetSimulatePhysics(true);  // 启用物理模拟

	StaticMeshComponent->SetSimulatePhysics(true);
	
}

void AInventory_ItemActor::BeginPlay()
{
	Super::BeginPlay();
}

void AInventory_ItemActor::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	// 检查是否是目标属性
	if (PropertyChangedEvent.Property != nullptr)
	{
		// 获取修改的属性名称
		FString PropertyName = PropertyChangedEvent.Property->GetName();

		// 检查是哪个枚举发生了变化，并打印出对应的枚举值
		if (PropertyName == TEXT("Item_ID"))
		{
			if (Item_ID < 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("[rookstein]<0"));
				UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
				StaticMeshComponent->SetStaticMesh(CubeMesh);  // 设置方形网格
			}
			else
			{
				FInventory_ItemDataBase* item = UInventory_BFL::GetItemData(Item_ID);
				StaticMeshComponent->SetStaticMesh(item->item_static_mesh_component);	
			}
		}
		
	}
}

void AInventory_ItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

