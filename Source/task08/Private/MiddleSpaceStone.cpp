#include "MiddleSpaceStone.h"

AMiddleSpaceStone::AMiddleSpaceStone()
{
	PointValue = 50;
	ItemType = "MiddleStone";
}

void AMiddleSpaceStone::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}