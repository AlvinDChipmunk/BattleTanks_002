// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); 

	ControlledTank = GetControlledTank();

} 

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair(); 
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* tmpTank = Cast<ATank>(GetPawn()); 

		if (!tmpTank) /*-*/ { UE_LOG(LogTemp, Warning, TEXT("---------WARNING--------- Player Controller NOT POSSESSING a Tank")); }
		else /*----------*/ { UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing: %s"), *(tmpTank->GetName())); }

		return tmpTank;

}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //to be discarded 
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const 
{
	FHitResult HitResult; 
	auto StartLocation = PlayerCameraManager->GetCameraLocation(); 
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange); 

	if ( GetWorld()->LineTraceSingleByChannel ( HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility ) )
	{ 
		HitLocation = HitResult.Location; 
		UE_LOG(LogTemp, Log, TEXT("TankPlayerController - HitLocation: %s"), *(HitLocation.ToString())); 
		return true; 
	} 
	else
	{
		HitLocation = FVector::ZeroVector; 
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController - Could NOT get HitLocation.  Possible out of range target status."));
		return false; 
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const // returns true if this hits landscape 
{

	//find the crosshair position in pixel co ordinates 
	int32 ViewportSizeX, ViewportSizeY; // current dimensions of the viewport being used by game 
	GetViewportSize(ViewportSizeX, ViewportSizeY); 

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation); 

	//de project the screen position of the crosshair to a world direction
	FVector LookDirection; 
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{ 
		//line trace along that direction and see what we hit up to a maximum range 

		if (GetLookVectorHitLocation(LookDirection, OutHitLocation)) { UE_LOG(LogTemp, Log, TEXT("TankPlayerController.cpp - Valid Hit Location.")); } 
		else { UE_LOG(LogTemp, Error, TEXT("TankPlayerController.cpp - Bad Hit Location.")); }
	} 

	//OutHitLocation = FVector(1); // basic unit vector in Unreal 
	return true; 
}

void ATankPlayerController::AimTowardsCrosshair()
{
	//Start moving the cannon barrel, so that it lines up with the trajectory of the shot that lands where the crosshairs are aiming.  

	if (!ControlledTank) { return; } // our bad tank pointer exit catch 
	else
	{
		// first get the world location through crosshairs, done by a linetrace 

		FVector HitLocation; // OUT Parameter 

		if (GetSightRayHitLocation(HitLocation)) // has side effect; is going to ray trace 
		{ 
			GetControlledTank()->AimAt(HitLocation, ControlledTank->GetLaunchSpeed());
		}

	}

} 


