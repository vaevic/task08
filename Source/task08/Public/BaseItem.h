#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "ItemInterface.h"

#include "BaseItem.generated.h"

class USphereComponent;
class UArrowComponent;

UCLASS()
class TASK08_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()

public:
	ABaseItem();

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Component")
	USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Component")
	USphereComponent* SphereCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Component")
	UArrowComponent* ArrowGizmo;

	//virtual void SetBasicComp();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FName ItemType;

	virtual FName GetItemType() const override;

	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;
	
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;
	
	virtual void ActivateItem(AActor* Activator) override;
	virtual void DestroyItem();

	FTimerHandle RotatorHandle;
	FTimerHandle WaveHandle;
	float Frame;
	FRotator CurrentRotation;
	FRotator RandomRotateValue;
	FVector CurrentLocation;
	FVector StartLocation;
	bool bIsMoveUp;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
	float wavespeed;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange;

	virtual void RandomRotate();
	virtual void WaveUpDown();
};
