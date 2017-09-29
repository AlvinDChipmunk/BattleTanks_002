// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn()); 

}
