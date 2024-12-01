#include "ListObject.h"

void UListObject::CreatChildObject()
{
	int32 number_of_children = FMath::RandRange(1,5);
	for (int32 i = 0; i < number_of_children; i++)
	{
		UListObject* item = NewObject<UListObject>(this);
		item->ItemName = FString::Printf(TEXT("%s - %i"),*ItemName,i);
		Children.Add(item);
	}
}
