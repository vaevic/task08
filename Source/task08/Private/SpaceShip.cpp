#include "SpaceShip.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SpaceShipPlayerController.h"
#include "EnhancedInputComponent.h"


ASpaceShip::ASpaceShip()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxComp->SetupAttachment(Root);
	BoxComp->SetRelativeLocation(FVector(0.0f, 0.0f, 290.0f));
	BoxComp->SetRelativeScale3D(FVector(26.0f, 19.0f, 9.0f));
	BoxComp->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(Root);
	StaticMeshComp->SetRelativeLocation(FVector(-1220.0f, 300.0f, 120.0f));
	StaticMeshComp->SetRelativeRotation(FRotator(3.0f, 0.0f, 0.0f));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fab/Space_Ranger_SR1/space_ranger_sr1"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}


	ArrowGizmo = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowGizmo->SetupAttachment(Root);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(Root);
	SpringArmComp->TargetArmLength = 1500.0f;
	SpringArmComp->SocketOffset = FVector(0.0f, 0.0f, 600.0f);
	//SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	//CameraComp->bUsePawnControlRotation = false;

	Movespeed = 20.0f;
	RotateValue = 1.0f;
	MaxRotateValue = 10.0f;

	MaxHealth = 100;
	Health = MaxHealth;
}

void ASpaceShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ASpaceShipPlayerController* PlayerController = Cast<ASpaceShipPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &ASpaceShip::Move);
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Completed, this, &ASpaceShip::MoveStop);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, this, &ASpaceShip::Look);
			}
		}
	}
}

void ASpaceShip::Move(const FInputActionValue& value)
{
	if (!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		CurrentLocation = FVector::ZeroVector;
		CurrentLocation.X = MoveInput.X * Movespeed;
		AddActorLocalOffset(CurrentLocation);
		//AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		CurrentLocation = FVector::ZeroVector;
		CurrentLocation.Y = MoveInput.Y * Movespeed;
		AddActorLocalOffset(CurrentLocation);
		//AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void ASpaceShip::MoveStop(const FInputActionValue& value)
{

}

void ASpaceShip::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	CurrentRotation = FRotator::ZeroRotator;
	CurrentRotation.Yaw = LookInput.X;
	CurrentRotation.Pitch = -LookInput.Y;
	AddActorLocalRotation(CurrentRotation);
	//AddControllerYawInput(LookInput.X);
	//AddControllerPitchInput(LookInput.Y);

}

int32 ASpaceShip::GetHealth() const
{
	return Health;
}

void ASpaceShip::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);
}

float ASpaceShip::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);

	if (Health <= 0.0f)
	{
		OnDeath();
	}

	return ActualDamage;
}

void ASpaceShip::OnDeath()
{

}

void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

