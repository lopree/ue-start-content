#include "BirdPawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"

ABirdPawn::ABirdPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	//初始化组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RenderBird = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("RenderBird"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	//组件依附
	RenderBird ->SetupAttachment(RootComponent);
	SpringArm ->SetupAttachment(RootComponent);
	MainCamera -> SetupAttachment(SpringArm);
	SphereCollision -> SetupAttachment(RenderBird);
	SphereCollision->bHiddenInGame = false;
	SphereCollision->SetSphereRadius(15.f);
	//组件设置
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(0, -90.0f, 0));
	MainCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	MainCamera->SetOrthoWidth(900.0f);
	//
	BirdFlipbook = nullptr;
}

void ABirdPawn::SetGravity(bool isGravity)
{
	//重力
	RenderBird->SetSimulatePhysics(isGravity);
}

void ABirdPawn::SetSkin(int32 skin_index)
{
	if (skin_index != -1)
	{
		switch (skin_index)
		{
			case 0:
				BirdFlipbook = LoadObject<UPaperFlipbook>(nullptr,TEXT("/Game/_Game/Animation/Bird/PF_RedBird.PF_RedBird"));
			break;
			case 1:
				BirdFlipbook = LoadObject<UPaperFlipbook>(nullptr,TEXT("/Script/Paper2D.PaperFlipbook'/Game/_Game/Animation/Bird/PF_YellowBird.PF_YellowBird'"));
			break;
			case 2:
				BirdFlipbook = LoadObject<UPaperFlipbook>(nullptr,TEXT("/Script/Paper2D.PaperFlipbook'/Game/_Game/Animation/Bird/PF_BlueBird.PF_BlueBird'"));
			break;
		}
		RenderBird->SetFlipbook(BirdFlipbook);
	}
}

void ABirdPawn::OnBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Display, TEXT("OnBeginOverlapEvent"));
}


void ABirdPawn::BeginPlay()
{
	Super::BeginPlay();
	BirdFlipbook = LoadObject<UPaperFlipbook>(nullptr,TEXT("/Game/_Game/Animation/Bird/PF_RedBird.PF_RedBird"));
	if (RenderBird && BirdFlipbook)
	{
		RenderBird->SetFlipbook(BirdFlipbook);
	}

	// 获取玩家控制器并添加输入映射上下文
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0); // 优先级为 0
		}
	}
	SetGravity(true);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this,&ABirdPawn::OnBeginOverlapEvent);
}

void ABirdPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABirdPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* enhanced_input_component = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhanced_input_component->BindAction(JumpAction,ETriggerEvent::Started,this,&ABirdPawn::JumpBird);
	}

}

void ABirdPawn::JumpBird()
{
	//UE_LOG(LogTemp, Warning, TEXT("Press SpaceBar!"));
	RenderBird->SetPhysicsLinearVelocity(FVector(0.0f, 0.0f, 0.0f));
	RenderBird->AddImpulse(FVector(0.0f, 0.0f, 2200.0f));
}


