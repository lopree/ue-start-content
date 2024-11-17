#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BirdPawn.generated.h"

UCLASS()
class REPROJECT_API ABirdPawn : public APawn
{
	GENERATED_BODY()

public:
	ABirdPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
