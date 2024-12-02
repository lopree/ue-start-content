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
	UButton* CreateRoomButton;
	//创建房间的时候，检查错误
	UFUNCTION()
	void CreateRoomCallback();
	//隐藏自己
	UFUNCTION()
	void BackMainMenuCallback();
	
};
