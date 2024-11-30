#include "TutorialUserWidget.h"

#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "DSP/BufferDiagnostics.h"
#include "UObject/UnrealTypePrivate.h"

bool UTutorialUserWidget::Initialize()
{
	if (Super::Initialize())
	{
		NameText = Cast<UTextBlock>(GetWidgetFromName(TEXT("NameBlock")));
		return true; 
	}
	return false; 
}

void UTutorialUserWidget::ChangeText()
{
	//NameText->SetText(NSLOCTEXT("FGG","K1","文本"));
	//NameText->SetText(FText::FromString("文本")); 会出错
	FString target_text = TEXT("文本更改"); 
	NameText->SetText(FText::FromString(target_text));
}
