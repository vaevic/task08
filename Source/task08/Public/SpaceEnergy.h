#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SpaceEnergy.generated.h"

UCLASS()
class TASK08_API ASpaceEnergy : public ABaseItem
{
	GENERATED_BODY()

public:
	ASpaceEnergy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 HealHP;

	virtual void ActivateItem(AActor* Activator) override;
};
