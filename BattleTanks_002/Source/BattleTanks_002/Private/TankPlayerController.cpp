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

void ATankPlayerController::AimTowardsCrosshair()
{
	/*
	Start moving the cannon barrel, so that it lines up with the trajectory of 
	the shot that lands where the crosshairs are aiming.  
	*/ 

	//safety exit, in case we DO NOT have a player controlled tank 

	if (!ControlledTank) { return; } // our bad tank pointer exit catch 
	else
	{
		// first get the world location through crosshairs, done by a linetrace 

		/*
		If the trace hits the landscape,
		then tell the controlled tank to aim at this point
		*/

		UE_LOG(LogTemp, Warning, TEXT("AimTowardsCrosshair method of TankPlayerController.cpp is active."));
	}



} 