#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SpaceStone.generated.h"

UCLASS()
class TASK08_API ASpaceStone : public ABaseItem
{
	GENERATED_BODY()
	
public:
	ASpaceStone();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	int32 PointValue;

	virtual void ActivateItem(AActor* Activator) override;
};
