#include "BasicGameModeBase.h"
#include "SmartPointer/FSmartPointClass.h"

ABasicGameModeBase::ABasicGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerActorBPClass(TEXT("/Script/Engine.Blueprint'/Game/_Game/BP/BP_BasicActor.BP_BasicActor_C'"));
	if (PlayerActorBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerActorBPClass.Class;
	}
}

void ABasicGameModeBase::NativePointer()
{
	TSharedPtr<FSmartPointClass> pMyClassInstance(new FSmartPointClass);
	UE_LOG(LogTemp,Log,TEXT("引用次数：%d"),pMyClassInstance.GetSharedReferenceCount());//1次，new FSmartPointClass这个空间被引用了一次，也就是首次记录
	pMyClassInstance->Num = 100;//这里并不计算
	UE_LOG(LogTemp,Log,TEXT("引用次数：%d"),pMyClassInstance.GetSharedReferenceCount());//1次
	TSharedPtr<FSmartPointClass> pMyClassInstance_02 = MakeShared<FSmartPointClass>();
	pMyClassInstance_02 = pMyClassInstance;
	UE_LOG(LogTemp,Log,TEXT("引用次数：%d"),pMyClassInstance.GetSharedReferenceCount());//2次
	TSharedPtr<FSmartPointClass> pMyClassInstance_03 (new FSmartPointClass);
	pMyClassInstance_02 = pMyClassInstance_03;//3. 异主释放
	UE_LOG(LogTemp,Log,TEXT("引用次数：%d"),pMyClassInstance.GetSharedReferenceCount());//1次
	//修改值
	pMyClassInstance_02->Num = 300;
	UE_LOG(LogTemp,Log,TEXT("值：%d"),pMyClassInstance_02->Num);
	
	//1. 主动释放
	//pMyClassInstance_02 = nullptr;
	//pMyClassInstance_02.Reset();

	
	//共享引用
	TSharedRef<FSmartPointClass> pMyClassInstance_04 (new FSmartPointClass);
	//解除引用
	pMyClassInstance_04->TestPointer();
	(*pMyClassInstance_04).TestPointer();
	pMyClassInstance_04->Num = 100;
	UE_LOG(LogTemp,Log,TEXT("Num :%d"),pMyClassInstance_04->Num);
	//弱指针
	TSharedPtr<FSmartPointClass> pMyClassInstance_05 (new FSmartPointClass);
	TWeakPtr<FSmartPointClass> pMyClassInstance_06 (pMyClassInstance_05);
	UE_LOG(LogTemp,Log,TEXT("被弱指针借用后，不会增加引用次数：%d"),pMyClassInstance_05.GetSharedReferenceCount());

	TSharedPtr<FSmartPointClass> pMyClassInstance_07 (pMyClassInstance_06.Pin());
	UE_LOG(LogTemp,Log,TEXT("被pin后，原来05指向的空间又被07指向，所以有2次：%d"),pMyClassInstance_05.GetSharedReferenceCount());//2次
	
	
}
///启用单播
void ABasicGameModeBase::NotifyEvent()
{
	//广播通知
	//bindraw演示
	FSmartPointClass* pMyClassInstance(new FSmartPointClass);
	OneNotifyDelegate.BindRaw(pMyClassInstance,&FSmartPointClass::TestPointer);
	OneNotifyDelegate.ExecuteIfBound();//如果是一对一的单播，不需要检查是否已经存在bind。后续的bind会替代前面的
	if (OneNotifyDelegateWithReturnValue.IsBound())
	{
		UE_LOG(LogTemp,Log,TEXT("返回的数值是：%d"), OneNotifyDelegateWithReturnValue.Execute());
	}
	
	delete pMyClassInstance;
	
}
///启用多播
void ABasicGameModeBase::MultiNotifyEvent()
{
	if (MultiNotifyDelegate.IsBound())
	{
		MultiNotifyDelegate.Broadcast();
	}

	if (MultiNotifyDelegateWithOneParam.IsBound())
	{
		MultiNotifyDelegateWithOneParam.Broadcast(100);
	}
}

void ABasicGameModeBase::DynNotifyEvent()
{
	DynNotifyDelegate.ExecuteIfBound();
	if (DynNotifyDelegateWithOneParam.IsBound())
	{
		int32 return_num = DynNotifyDelegateWithOneParam.Execute(100);
		UE_LOG(LogTemp,Log,TEXT("返回的值：%d"),return_num);
	}
	//解绑
	//DynNotifyDelegate.Clear();
}

void ABasicGameModeBase::DynMultiNotifyEvent()
{
	if (DynMulWithOneParam.IsBound())
	{
		DynMulWithOneParam.Broadcast(101);
	}
}
	
