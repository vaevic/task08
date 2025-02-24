#pragma once

#include "CoreMinimal.h"
#include "SpaceStone.h"
#include "MiddleSpaceStone.generated.h"

UCLASS()
class TASK08_API AMiddleSpaceStone : public ASpaceStone
{
	GENERATED_BODY()

public:
	AMiddleSpaceStone();

	virtual void ActivateItem(AActor* Activator) override;
};
