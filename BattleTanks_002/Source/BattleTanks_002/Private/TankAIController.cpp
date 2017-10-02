// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("---------WARNING--------- AI Controller NOT POSSESSING a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller possessing: %s"), *(AIControlledTank->GetName()));
	}



}

ATank* ATankAIController::GetAIControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

