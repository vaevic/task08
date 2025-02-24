#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawnRow.h"
#include "ItemSpawnVolume.generated.h"

class UBoxComponent;
class ABaseItem;

UCLASS()
class TASK08_API AItemSpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemSpawnVolume();

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	ABaseItem* SpawnRandomItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	UDataTable* ItemDataTable;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	FVector GetRandomPointInVolume() const;
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	ABaseItem* SpawnItem(TSubclassOf<ABaseItem> ItemClass);
	FItemSpawnRow* GetRandomItem() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
