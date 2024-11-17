#include "BirdPawn.h"

ABirdPawn::ABirdPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABirdPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABirdPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABirdPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

