#include "BaseItem.h"
#include "Components/SphereComponent.h"
#include "Components/ArrowComponent.h"
#include "TimerManager.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
	Frame = 1.0f / 24.0f;
	wavespeed = 2.0f;
	MaxRange = 30.0f;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	SphereCollision->SetupAttachment(Root);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);

	ArrowGizmo = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowGizmo->SetupAttachment(Root);
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	CurrentLocation = GetActorLocation();

	GetWorld()->GetTimerManager().SetTimer(
		RotatorHandle,
		this,
		&ABaseItem::RandomRotate,
		Frame,
		true);

	GetWorld()->GetTimerManager().SetTimer(
		WaveHandle,
		this,
		&ABaseItem::WaveUpDown,
		Frame,
		true);
}

//void ABaseItem::SetBasicComp()
//{
//	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
//	SetRootComponent(Root);
//
//	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
//	SphereCollision->SetupAttachment(Root);
//	SphereCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
//	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
//	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);
//
//	ArrowGizmo = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
//	ArrowGizmo->SetupAttachment(Root);
//}

FName ABaseItem::GetItemType() const
{
	return ItemType;
}

void ABaseItem::OnItemOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!")));

		ActivateItem(OtherActor);
	}
}
void ABaseItem::OnItemEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{

}


void ABaseItem::ActivateItem(AActor* Activator)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!")));
}

void ABaseItem::DestroyItem()
{
	Destroy();
}

void ABaseItem::RandomRotate()
{
	RandomRotateValue.Yaw = FMath::RandRange(0.0f, 2.0f);
	CurrentRotation += RandomRotateValue;
	SetActorRotation(CurrentRotation);
}

void ABaseItem::WaveUpDown()
{
	if (bIsMoveUp)
	{
		CurrentLocation.Z += wavespeed;
		if (CurrentLocation.Z >= StartLocation.Z + MaxRange)
		{
			bIsMoveUp = true;
		}
	}
	else
	{
		CurrentLocation.Z -= wavespeed;
		if (CurrentLocation.Z <= StartLocation.Z - MaxRange)
		{
			bIsMoveUp = false;
		}
	}
}
