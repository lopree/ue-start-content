#include "ListObject.h"

void UListObject::CreatChildObject()
{
	if (FMath::RandBool())
	{
		return;
	}
	int32 number_of_children = FMath::RandRange(1,5);
	for (int32 i = 0; i < number_of_children; i++)
	{
		UListObject* item = NewObject<UListObject>(this);
		item->ItemName = FString::Printf(TEXT("%s - %i"),*ItemName,i);
		item->Level = 1;
		Children.Add(item);
	}
}
