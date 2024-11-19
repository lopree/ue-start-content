#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BirdPawn.generated.h"
class UPaperFlipbookComponent;
class USpringArmComponent;
class UCameraComponent;
class USphereComponent;
class UPaperFlipbook;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
UCLASS()
class REPROJECT_API ABirdPawn : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

public:
	ABirdPawn();
	UPaperFlipbookComponent* RenderBird;
	USpringArmComponent* SpringArm;
	UCameraComponent* MainCamera;
	USphereComponent* SphereCollision;
	UPaperFlipbook* BirdFlipbook;
	//设置重力
	void SetGravity(bool isGravity);
	//设置皮肤
	void SetSkin(int32 skin_index);
	

protected:
	virtual void BeginPlay() override;

	void JumpBird();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
