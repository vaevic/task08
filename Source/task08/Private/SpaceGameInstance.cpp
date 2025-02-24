#include "SpaceGameInstance.h"

USpaceGameInstance::USpaceGameInstance()
{
	TotalScore = 0;
	CurrentWave = 1;

}

void USpaceGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;

}