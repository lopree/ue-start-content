#include "TestActor.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATestActor::Destroyed()
{
	Super::Destroyed();
	UKismetSystemLibrary::PrintString(this,TEXT("我被摧毁了"));
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

