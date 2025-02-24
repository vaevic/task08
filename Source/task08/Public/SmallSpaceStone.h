#pragma once

#include "CoreMinimal.h"
#include "SpaceStone.h"
#include "SmallSpaceStone.generated.h"

UCLASS()
class TASK08_API ASmallSpaceStone : public ASpaceStone
{
	GENERATED_BODY()

public:
	ASmallSpaceStone();

	virtual void ActivateItem(AActor* Activator) override;
};
