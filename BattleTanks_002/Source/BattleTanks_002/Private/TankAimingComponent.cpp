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

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{ 
	if (!Barrel) { return; } // pop out of method if no barrel to begin with 

	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString(); 

	if (!(HitLocation.IsZero()))
	{
		/*
			UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - %s aiming at: %s"), *OurTankName, *(HitLocation.ToString()));
			UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Tank cannon barrel location: %s"), *BarrelLocation);	
		*/
		UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Launch Speed: %f"), LaunchSpeed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TankAimingComponent.cpp - %s could NOT get HitLocation.  Possible out of range target status."), *(HitLocation.ToString()));
	}

	/*
	static bool SuggestProjectileVelocity
(
    const UObject * WorldContextObject, // use keyword this 
    FVector & TossVelocity, //need OUT parameter, calling it FVector OutLaunchVelocity
    FVector StartLocation, //need FVector StartLocation 
    FVector EndLocation, //need FVector EndLocation
    float TossSpeed,
    bool bHighArc,
    float CollisionRadius,
    float OverrideGravityZ,
    ESuggestProjVelocityTraceOption::Type TraceOption,
    const FCollisionResponseParams & ResponseParam,
    const TArray < AActor * > & ActorsToIgnore,
    bool bDrawDebug
)
	*/

	//now about to implement suggestprojectilevelocity

	//invoke suggestprojectilevelocity for OUT parameter OutLaunchVelocity
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Muzzle"));

	bool UseTheHighArc = false; 
	float ShellImpactRadius = 0.0f; 
	float OverrideGravityFactor = 0.0f;

	if (UGameplayStatics::SuggestProjectileVelocity
		(
		    this, 
			OutLaunchVelocity, 
			StartLocation, 
			HitLocation,
			LaunchSpeed,
			UseTheHighArc,
			ShellImpactRadius,
			OverrideGravityFactor,
		    ESuggestProjVelocityTraceOption::TraceFullPath
		)
	)
	{

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Log, TEXT("TankAimingComponent.cpp - Aiming at: %s"), *(AimDirection.ToString()));

	} 
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TankAimingComponent.cpp - NO VALID aiming point!!"));
	}




}

