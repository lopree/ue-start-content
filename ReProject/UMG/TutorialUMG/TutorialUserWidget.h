#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "TutorialUserWidget.generated.h"
class UButton;
class UTextBlock;
class UTreeView;
UCLASS()
class REPROJECT_API UTutorialUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;
public:
	UPROPERTY(meta = (BindWidget))
	UButton* ForceNameButton;
	UPROPERTY()
	UTextBlock* NameText;
	UPROPERTY(meta = (BindWidget))
	UTreeView* CustomTreeView;
	UPROPERTY(meta = (BindWidget))
	UButton* AddItemButton;
protected:
	UFUNCTION(BlueprintCallable)
	void ChangeText();
	//松开鼠标的时候触发的事件
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	//往listview中添加item
	UFUNCTION()
	void AddCallback();
	UFUNCTION()
	void OnGetItemChildren(UObject* Item, TArray<UObject*>& Children);
	
};
