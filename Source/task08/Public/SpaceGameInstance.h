#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SpaceGameInstance.generated.h"

UCLASS()
class TASK08_API USpaceGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	USpaceGameInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData");
	int32 TotalScore;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData");
	int32 CurrentWave;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);
};
