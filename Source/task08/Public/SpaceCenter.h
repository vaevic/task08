#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceCenter.generated.h"

UCLASS()
class TASK08_API ASpaceCenter : public APawn
{
	GENERATED_BODY()

public:
	ASpaceCenter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
