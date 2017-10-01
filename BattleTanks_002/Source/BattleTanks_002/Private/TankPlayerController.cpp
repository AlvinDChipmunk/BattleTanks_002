// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); 

	auto ControlledTank = GetControlledTank(); 

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("---------WARNING--------- PlayerController NOT POSSESSING a Tank"));
	} 
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}

	

} 

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

