
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UI/Inventory_Bag_HUD.h"
#include "CustomRPGCharacter.generated.h"

class AInventory_ItemActor;
class USphereComponent;
class ULODSyncComponent;
class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;
UCLASS()
class REPROJECT_API ACustomRPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	ACustomRPGCharacter();
protected:
	
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Pick();

	void ToggleBag();

	virtual void NotifyControllerChanged() override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
private:
	//=====================================
	//******** 组件 ********
	//=====================================
	/** Spring Arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** 碰撞 **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Custom, meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollision;
	//=====================================
	//******** 输入映射 ********
	//=====================================
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PickAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleBagAction;
	//=====================================
	//******** 碰撞回调 ********
	//=====================================
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
						const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	// 存储碰撞的物品
	UPROPERTY()
	TArray<AActor*> InventoryArray;
	//=====================================
	//******** 玩家控制器等 ********
	//=====================================
	APlayerController* InventoryOwner;
	AInventory_Bag_HUD* InventoryBag;
};
