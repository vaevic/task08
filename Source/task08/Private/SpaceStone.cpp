#include "SpaceStone.h"
#include "BaseItem.h"
#include "SpaceGameState.h"
#include "Components/SphereComponent.h"

ASpaceStone::ASpaceStone()
{

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComp->SetupAttachment(SphereCollision);

	PointValue = 0;
	ItemType = "DefaultStone";
}

void ASpaceStone::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (ASpaceGameState* GameState = World->GetGameState<ASpaceGameState>())
			{
				GameState->AddScore(PointValue);
			}
		}
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!")));
		
		DestroyItem();
	}
	
}