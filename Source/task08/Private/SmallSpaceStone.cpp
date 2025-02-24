#include "SmallSpaceStone.h"

ASmallSpaceStone::ASmallSpaceStone()
{
	PointValue = 10;
	ItemType = "SmallStone";
}

void ASmallSpaceStone::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}