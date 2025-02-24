#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BaseItem.h"
#include "ItemSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ItemName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<ABaseItem> ItemClass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnChance;

};
