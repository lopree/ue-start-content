#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReProject/Inventory/Interface/Interactables.h"
#include "Inventory_ItemActor.generated.h"

class USphereComponent;

UCLASS()
class REPROJECT_API AInventory_ItemActor : public AActor,public IInteractables
{
	GENERATED_BODY()
	//物品ID，默认-1
	//装备：0~1000
	//消耗品：1001~2000
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CustomProperty, meta = (AllowPrivateAccess = "true"))
	int32 Item_ID = -1;
	
public:	
	AInventory_ItemActor();

protected:
	virtual void BeginPlay() override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	

public:	
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Custom, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent;
	//
	void Interact_Implementation() override;
	void InteractPure() override;
};
