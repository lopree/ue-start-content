#include "PipeActor.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
APipeActor::APipeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	ConstructorHelpers::FObjectFinder<UPaperSprite> UpPath(TEXT("/Script/Paper2D.PaperSprite'/Game/_Game/Texture/PipeAndLand/pipe_up_Sprite.pipe_up_Sprite'"));
	ConstructorHelpers::FObjectFinder<UPaperSprite> DownPath(TEXT("/Game/_Game/Texture/PipeAndLand/pipe_down_Sprite.pipe_down_Sprite"));
	for (int32 i = 0; i < 3; i++)
	{
		//循环添加组件
		FString scene_name = FString::Printf(TEXT("Scene%d"), i );
		USceneComponent* scene_component = CreateDefaultSubobject<USceneComponent>(*scene_name);
		scene_component->SetupAttachment(RootComponent);
		scene_component->SetRelativeLocation(FVector(170.f * i, 0, 0));
		FVector old_location = scene_component->GetRelativeLocation();
		old_location.Z = FMath::RandRange(-30.f,120.f);
		scene_component->SetRelativeLocation(old_location);
		//子组件
		FString up_name = FString::Printf(TEXT("UP%d"), i );
		FString down_name = FString::Printf(TEXT("Down%d"), i );
		UPaperSpriteComponent* pipe_up = CreateDefaultSubobject<UPaperSpriteComponent>(*up_name);
		pipe_up->SetupAttachment(scene_component);
		UPaperSpriteComponent* pipe_down = CreateDefaultSubobject<UPaperSpriteComponent>(*down_name);
		pipe_down->SetupAttachment(scene_component);
		//
		if (UpPath.Succeeded()) pipe_up->SetSprite(UpPath.Object);
		if (DownPath.Succeeded()) pipe_down->SetSprite(DownPath.Object);
		pipe_up->SetRelativeLocation(FVector(0,0,-240.f));
		pipe_down->SetRelativeLocation(FVector(0,0,240.f));

		SceneComponents.Add(scene_component);
		
	}

	
}

void APipeActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void APipeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

