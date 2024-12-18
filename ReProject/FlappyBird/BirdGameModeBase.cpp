#include "BirdGameModeBase.h"

#include "BirdHUD.h"
#include "UObject/ConstructorHelpers.h"

ABirdGameModeBase::ABirdGameModeBase()
{
	// 使用 FClassFinder 查找蓝图类/Game/_Game/BP/BP_BirdPawn.BP_BirdPawn,不需要后缀
	static ConstructorHelpers::FClassFinder<APawn> BirdPawnBP(TEXT("/Game/_Game/BP/BP_BirdPawn"));
	if (BirdPawnBP.Class != nullptr)
	{
		DefaultPawnClass = BirdPawnBP.Class;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to find BP_BirdPawn class!"));
	}
	HUDClass = ABirdHUD::StaticClass();
	GameStateClass = ABirdGameStateBase::StaticClass();
}

void ABirdGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//不要在构造函数中生成物体，否则会崩溃。因为构造函数在游戏没有运行时就已经开始
	
	// 获取当前世界上下文
	UWorld* World = GetWorld();
	if (World)
	{
		World->SpawnActor<ABGActor>(ABGActor::StaticClass(),FVector(0,-100,0),FRotator::ZeroRotator);
		World->SpawnActor<APipeActor>(APipeActor::StaticClass(),FVector(0,-6,0),FRotator::ZeroRotator);
		World->SpawnActor<ALandActor>(ALandActor::StaticClass(),FVector(0,5,-200),FRotator::ZeroRotator);
	}
}
