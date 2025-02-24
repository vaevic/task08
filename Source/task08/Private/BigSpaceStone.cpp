#include "BigSpaceStone.h"

ABigSpaceStone::ABigSpaceStone()
{
	PointValue = 100;
	ItemType = "BigStone";
}

void ABigSpaceStone::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}