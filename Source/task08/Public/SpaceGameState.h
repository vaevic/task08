#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpaceGameState.generated.h"


UCLASS()
class TASK08_API ASpaceGameState : public AGameState
{
	GENERATED_BODY()

public:

	ASpaceGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 Score;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawn")
	int32 ItemToSpawn;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stone")
	int32 SpawnedStoneCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stone")
	int32 CollectedStoneCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	float WaveDuration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWaveIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWaves;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Wave")
	TArray<int32> WaveNum;

	FTimerHandle WaveTimerHandle;
	FTimerHandle HUDUpdateTimerHandle;

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Wave")
	void OnGameOver();

	void StartWave();
	void OnWaveTimeUp();
	void OnStoneCollected();
	void EndWave();
	void UpdateHUD();
};
