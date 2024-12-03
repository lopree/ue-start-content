#pragma once

#include "CoreMinimal.h"
#include "ManagerBase.h"
#include "UObject/NoExportTypes.h"
#include "ItemManager.generated.h"

UCLASS()
class REPROJECT_API UItemManager : public UManagerBase
{
	GENERATED_BODY()
public:
	virtual void Install() override;
	virtual void Uninstall() override;
	
};
