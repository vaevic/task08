#pragma once

#include "CoreMinimal.h"
#include "SpaceStone.h"
#include "BigSpaceStone.generated.h"


UCLASS()
class TASK08_API ABigSpaceStone : public ASpaceStone
{
	GENERATED_BODY()

public:
	ABigSpaceStone();

	virtual void ActivateItem(AActor* Activator) override;
};
