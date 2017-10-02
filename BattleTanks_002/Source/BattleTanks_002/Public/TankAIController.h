// Copyright notice may not be needed for a demo portfolio game?

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_002_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank* GetAIControlledTank() const;

	void BeginPlay() override; 


private:


};
