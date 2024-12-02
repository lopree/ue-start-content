#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ErrorUserWidget.generated.h"
class UTextBlock;
class UButton;
UCLASS()
class REPROJECT_API UErrorUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetErrorTitleAndContent(FText ErrorTitleText, FText ErrorContentText);
	//改变error面板的显示与隐藏
	void ToggleErrorPanel();
protected:
	virtual void NativeConstruct() override;
private:
	UPROPERTY(Transient,meta=(BindWidgetAnim))
	UWidgetAnimation* open;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ErrorTitle;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ErrorContent;
	UPROPERTY(meta = (BindWidget))
	UButton* OK_Button;
	//按钮的回调
	UFUNCTION()
	void OK_ButtonClicked();
	
};
