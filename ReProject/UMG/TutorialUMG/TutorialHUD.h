#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TutorialHUD.generated.h"

UCLASS()
class REPROJECT_API ATutorialHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
};
