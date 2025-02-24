#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "SpaceMine.generated.h"

class USkeletalMeshComponent;

UCLASS()
class TASK08_API ASpaceMine : public ABaseItem
{
	GENERATED_BODY()

public:
	ASpaceMine();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USkeletalMeshComponent* SkeletalMeshComp;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
    USphereComponent* ExplosionCollision;

    FTimerHandle ExplosionTimerHandle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionDelay;
    // ���� ����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionRadius;
    // ���� ������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    int32 ExplosionDamage;

    bool bHasExploded;

    virtual void ActivateItem(AActor* Activator) override;

    void Explode();

};
