#include "SpaceGameMode.h"
#include "SpaceShip.h"
#include "SpaceShipPlayerController.h"
#include "SpaceGameState.h"

ASpaceGameMode::ASpaceGameMode()
{
	static ConstructorHelpers::FClassFinder<ASpaceShip>
		PlayerCharacter(TEXT("/Game/Blueprints/BP_SpaceShip"));
	if (PlayerCharacter.Succeeded())
	{
		DefaultPawnClass = PlayerCharacter.Class;
	}

	static ConstructorHelpers::FClassFinder<ASpaceShipPlayerController>
		PlayerController(TEXT("/Game/Blueprints/BP_SpaceShipPlayerController"));
	if (PlayerController.Succeeded())
	{
		PlayerControllerClass = PlayerController.Class;
	}

	/*static ConstructorHelpers::FClassFinder<ASpaceGameState>
		GameState(TEXT("/Game/Blueprints/BP_SpaceGameState"));
	if (GameState.Succeeded())
	{
		GameStateClass = GameState.Class;
	}*/
}

