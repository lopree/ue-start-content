#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ManagerBase.generated.h"

UCLASS()
class REPROJECT_API UManagerBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void Install(){};
	virtual void Uninstall(){};
};
