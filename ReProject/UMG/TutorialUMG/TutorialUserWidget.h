#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TutorialUserWidget.generated.h"
class UButton;
class UTextBlock;
UCLASS()
class REPROJECT_API UTutorialUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;
	

public:
	UPROPERTY(meta = (BindWidget))
	UButton* ForceNameButton;
	UPROPERTY()
	UTextBlock* NameText;
protected:
	UFUNCTION(BlueprintCallable)
	void ChangeText();
	//松开鼠标的时候触发的事件
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	
};
