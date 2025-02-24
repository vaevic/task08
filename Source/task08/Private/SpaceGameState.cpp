#include "SpaceGameState.h"
#include "Kismet/GameplayStatics.h"
#include "ItemSpawnVolume.h"
#include "SpaceStone.h"
#include "SpaceGameInstance.h"
#include "SpaceShipPlayerController.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"

ASpaceGameState::ASpaceGameState()
{
	Score = 0;
	ItemToSpawn = 30;
	SpawnedStoneCount = 0;
	CollectedStoneCount = 0;
	WaveDuration = 30.0f;
	CurrentWaveIndex = 0;
	MaxWaves = 3;
	

}

void ASpaceGameState::BeginPlay()
{
	Super::BeginPlay();

	UpdateHUD();
	StartWave();

	GetWorldTimerManager().SetTimer(
		HUDUpdateTimerHandle,
		this,
		&ASpaceGameState::UpdateHUD,
		0.1f,
		true);
}


int32 ASpaceGameState::GetScore() const
{
	return Score;
}

void ASpaceGameState::AddScore(int32 Amount)
{
	/*if (USpaceGameInstance* GameInstance = GetGameInstance())
	{
		
	}
		*/
}

void ASpaceGameState::OnGameOver()
{

}

void ASpaceGameState::StartWave()
{
	SpawnedStoneCount = 0;
	CollectedStoneCount = 0;

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItemSpawnVolume::StaticClass(), FoundVolumes);
	
	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			AItemSpawnVolume* ItemSpawnVolume = Cast<AItemSpawnVolume>(FoundVolumes[0]);
			if (ItemSpawnVolume)
			{
				ABaseItem* SpawnedItem = ItemSpawnVolume->SpawnRandomItem();
				if (SpawnedItem && SpawnedItem->IsA(ASpaceStone::StaticClass()))
				{
					SpawnedStoneCount++;
				}
			}

		}
	}

	GetWorldTimerManager().SetTimer(
		WaveTimerHandle,
		this,
		&ASpaceGameState::OnWaveTimeUp,
		WaveDuration,
		false
	);

	UE_LOG(LogTemp, Warning, TEXT("Wave %d Start!"),CurrentWaveIndex + 1);
}
void ASpaceGameState::OnWaveTimeUp()
{
	EndWave();
}
void ASpaceGameState::OnStoneCollected()
{
	CollectedStoneCount++;

	if (SpawnedStoneCount > 0 && CollectedStoneCount >= SpawnedStoneCount)
	{
		EndWave();
	}
}
void ASpaceGameState::EndWave()
{
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);
	CurrentWaveIndex++;

	if (CurrentWaveIndex >= MaxWaves)
	{
		OnGameOver();
		return;
	}

	//if (WaveNum.IsValidIndex(CurrentWaveIndex))
	//{
	//	//새 웨이브 시작
	//}
}

void ASpaceGameState::UpdateHUD()
{
	if (ASpaceShipPlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		ASpaceShipPlayerController* SpaceShipController = Cast<ASpaceShipPlayerController>(PlayerController);
		{
			if (UUserWidget* HUDWidget = SpaceShipController->GetHUDWidget())
			{

			}
		}
	}
}