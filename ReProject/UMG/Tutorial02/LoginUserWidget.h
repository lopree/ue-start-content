#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginUserWidget.generated.h"

class AFGHUD;
class UButton;

UCLASS()
class REPROJECT_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;
private:
	AFGHUD* hud;
	UButton* BackMainMenuButton;
	//隐藏自己
	UFUNCTION()
	void BackMainMenuCallback();
	
};
