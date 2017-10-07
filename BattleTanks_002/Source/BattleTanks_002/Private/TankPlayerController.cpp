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

	//UE_LOG(LogTemp, Warning, TEXT("Player Controller now ticking...: %f"), DeltaTime);
	AimTowardsCrosshair(); 
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* tmpTank = Cast<ATank>(GetPawn()); 

		if (!tmpTank) /*-*/ { UE_LOG(LogTemp, Warning, TEXT("---------WARNING--------- Player Controller NOT POSSESSING a Tank")); }
		else /*----------*/ { UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing: %s"), *(tmpTank->GetName())); }

		return tmpTank;

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const // returns true if this hits landscape 
{
	//outline of process

	//find the crosshair position in pixel co ordinates 
	//de project the screen position of the crosshair to a world direction
	//line trace along that direction and see what we hit up to a maximum range 

	int32 ViewportSizeX, ViewportSizeY; // current dimensions of the viewport being used by game 
	GetViewportSize(ViewportSizeX, ViewportSizeY); 

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation); 
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *(ScreenLocation.ToString())); //this takes care of - find the crosshair position in pixel co ordinates 

	FVector LookDirection; 

	if (GetLookDirection(ScreenLocation, LookDirection)) { UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *(LookDirection.ToString())); } 

	OutHitLocation = FVector(1); // basic unit vector in Unreal 
	return false; 
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //to be discarded 
	return DeprojectScreenPositionToWorld ( ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection ); 
}

void ATankPlayerController::AimTowardsCrosshair()
{
	//Start moving the cannon barrel, so that it lines up with the trajectory of the shot that lands where the crosshairs are aiming.  

	//safety exit, in case we DO NOT have a player controlled tank 

	if (!ControlledTank) { return; } // our bad tank pointer exit catch 
	else
	{
		// first get the world location through crosshairs, done by a linetrace 

		/*
		If the trace hits the landscape,
		then tell the controlled tank to aim at this point
		*/

		//UE_LOG(LogTemp, Warning, TEXT("AimTowardsCrosshair method of TankPlayerController.cpp is active."));

		FVector HitLocation; // OUT Parameter 

		if (GetSightRayHitLocation(HitLocation)) // has side effect; is going to ray trace 
		{ 
			//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *(HitLocation.ToString()));

		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("No valid aim point.")); 
		}

	}

} 


