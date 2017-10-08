// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{ 
	Barrel = BarrelToSet; 
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{ 
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString(); 

	if (!(HitLocation.IsZero()))
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAimingComponent.cpp - %s aiming at: %s"), *OurTankName, *(HitLocation.ToString()));
		UE_LOG(LogTemp, Warning, TEXT("TankAimingComponent.cpp - Tank cannon barrel location: %s"), *BarrelLocation);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TankAimingComponent.cpp - %s could NOT get HitLocation.  Possible out of range target status."), *(HitLocation.ToString()));
	}
}

