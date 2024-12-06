#include "CustomRPGCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/LODSyncComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Item/Inventory_ItemActor.h"

ACustomRPGCharacter::ACustomRPGCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); 

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; 
	CameraBoom->bUsePawnControlRotation = true; 

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false;
	//碰撞区域
	// 创建 Sphere Collision 组件
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

	// 设置 Sphere Collision 组件的大小
	SphereCollision->InitSphereRadius(100.f);

	// 将 Sphere Collision 组件设置为根组件
	SphereCollision->SetupAttachment(RootComponent);
	
}
void ACustomRPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	// 碰撞堆叠
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this,&ACustomRPGCharacter::OnOverlapBegin);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this,&ACustomRPGCharacter::OnOverlapEnd);
}
void ACustomRPGCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ACustomRPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACustomRPGCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACustomRPGCharacter::Look);

		// pick
		EnhancedInputComponent->BindAction(PickAction, ETriggerEvent::Completed, this, &ACustomRPGCharacter::Pick);
	}
}



void ACustomRPGCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ACustomRPGCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ACustomRPGCharacter::Pick()
{
	if (InventoryArray.Num() > 0)
	{
		//接口函数实现
		Cast<IInteractables>(InventoryArray[0])->InteractPure();
		//AInventory_ItemActor* ItemToPickup = InventoryArray[0]; // 获取数组中的第一个物品

		//IInteractables::Execute_Interact(InventoryArray[0], 1); // 调用接口方法，传递参数，如果Interact方法中有参数
	}
}

void ACustomRPGCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		// 检查物体的标签
		if (OtherActor->ActorHasTag("Interactable")) 
		{
			InventoryArray.Add(OtherActor);
		}
	}
}

void ACustomRPGCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this)
	{
		// 检查物体的标签
		if (OtherActor->ActorHasTag("Interactable")) 
		{
			InventoryArray.Remove(OtherActor);
		}
	}
}

