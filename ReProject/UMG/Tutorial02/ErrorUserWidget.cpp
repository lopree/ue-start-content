#include "ErrorUserWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UErrorUserWidget::SetErrorTitleAndContent(FText ErrorTitleText, FText ErrorContentText)
{
	ErrorTitle->SetText(ErrorTitleText);
	ErrorContent->SetText(ErrorContentText);
}

void UErrorUserWidget::ToggleErrorPanel()
{
	if (IsInViewport())
	{
		RemoveFromParent();
	}else
	{
		AddToViewport();
		PlayAnimation(open,0,1,EUMGSequencePlayMode::Forward,3,false);

	}
}

void UErrorUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	OK_Button->OnClicked.AddDynamic(this,&UErrorUserWidget::OK_ButtonClicked);
}

void UErrorUserWidget::OK_ButtonClicked()
{
}
