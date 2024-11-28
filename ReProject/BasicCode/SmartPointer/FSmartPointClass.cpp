#include "FSmartPointClass.h"

FSmartPointClass::FSmartPointClass()
{
	UE_LOG(LogTemp,Log,TEXT("初始化自定义类"));
	Num = 50;
}

FSmartPointClass::~FSmartPointClass()
{
}

void FSmartPointClass::TestPointer()
{
	UE_LOG(LogTemp, Warning, TEXT("TestPointer"));
}
