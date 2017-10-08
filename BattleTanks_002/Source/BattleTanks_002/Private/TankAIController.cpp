// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();

	auto PlayerTargetTank = GetPlayerTank(); 

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) 
	{
		// TODO move towards player 

		// aim towards the player 
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()); 

		// fire if ready 

	} 
	else
	{

	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	ATank* tmpTank = Cast<ATank>(GetPawn());

	//using comments syntax to experiment with readability 

	if (!tmpTank) /*-*/ { UE_LOG(LogTemp, Warning, TEXT("---------WARNING--------- AI Controller NOT POSSESSING a Tank")); } 
	else /*----------*/ { UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller possessing: %s"), *(tmpTank->GetName())); }

	return tmpTank;

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn(); 

	if (!PlayerPawn) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("---------WARNING--------- AI Controller CANNOT find Player Tank"));
		return nullptr; 
	}
	else 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller has found Player Tank: %s"), *(PlayerPawn->GetName()));
		return Cast<ATank>(PlayerPawn); 
	}

}