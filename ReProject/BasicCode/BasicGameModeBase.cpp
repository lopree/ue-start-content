#include "BasicGameModeBase.h"

#include "SmartPointer/FSmartPointClass.h"

void ABasicGameModeBase::NativPointer()
{
	TSharedPtr<FSmartPointClass> pMyClassInstance(new FSmartPointClass);
	TSharedPtr<FSmartPointClass> pMyClassInstance_02 = MakeShared<FSmartPointClass>();

	pMyClassInstance->Num = 100;
	UE_LOG(LogTemp, Warning, TEXT("Num: %d"), pMyClassInstance->Num);}
