#pragma once

#include "CoreMinimal.h"
#include "CharacterEnum.h"
#include "GameFramework/Character.h"
#include "InventoryCharacter.generated.h"

class UBagActorComponent;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class REPROJECT_API AInventoryCharacter : public ACharacter
{
	GENERATED_BODY()
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	AInventoryCharacter();

protected:
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:	
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
public:
	EPlayerJob GetJob(){return Job;}
	UBagActorComponent* GetBagActorComponent(){return Bag_Component;}
protected:
	UPROPERTY(EditAnywhere)
	EPlayerJob Job;
	UPROPERTY(VisibleAnywhere)
	UBagActorComponent* Bag_Component;

};
