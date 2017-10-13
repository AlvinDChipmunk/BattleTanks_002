// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankBarrelMesh.h"
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


void UTankAimingComponent::SetBarrelReference(UTankBarrelMesh * BarrelToSet)
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

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//UE_LOG(LogTemp, Error, TEXT("TankAimingComponent.cpp - Do I enter MoveBarrelTowards method??"));

	auto BarrelRotator = Barrel->GetComponentRotation();
	auto AimAsRotator = AimDirection.Rotation(); 
	auto DeltaRotator = AimAsRotator - BarrelRotator; 

	UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Aim Direction Rotation: %s"), *(AimAsRotator.ToString()));
	UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Delta Rotation: %s"), *(DeltaRotator.ToString()));

	Barrel->Elevate(2.5f);
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{ 
	if (!Barrel) { return; } // pop out of method if no barrel to begin with 

	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString(); 

	if (!(HitLocation.IsZero())) 
	{ UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Launch Speed: %f"), LaunchSpeed); }
	else 
	{ UE_LOG(LogTemp, Error, TEXT("TankAimingComponent.cpp - %s could NOT get HitLocation.  Possible out of range target status."), *(HitLocation.ToString())); }

	//now about to implement suggestprojectilevelocity

	//invoke suggestprojectilevelocity for OUT parameter OutLaunchVelocity
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Muzzle"));

	bool UseTheHighArc = false; 
	float ShellImpactRadius = 0.0f; 
	float OverrideGravityFactor = 0.0f;

	bool HaveValidAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::TraceFullPath
	); 

	if ( HaveValidAimSolution )
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Aiming at: %s"), *(AimDirection.ToString()));
		MoveBarrelTowards(AimDirection); 
	} 
	else
	{ UE_LOG(LogTemp, Error, TEXT("TankAimingComponent.cpp - NO VALID aiming point!!")); }




}

