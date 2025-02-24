#include "SpaceEnergy.h"
#include "BaseItem.h"
#include "SpaceShip.h"

ASpaceEnergy::ASpaceEnergy()
{
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComp->SetupAttachment(Root);

	HealHP = 20;
	ItemType = "Energy";
}

void ASpaceEnergy::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (ASpaceShip* Player = Cast<ASpaceShip>(Activator))
	{
		Player->AddHealth(HealHP);
	}
	DestroyItem();
}