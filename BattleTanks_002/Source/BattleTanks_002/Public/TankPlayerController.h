// Copyright notice may not be needed for a demo portfolio game?

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // this *.generated.h file has to be the last include line in these header files 

/**
 * 
 */
UCLASS()
class BATTLETANKS_002_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 
	ATank* GetControlledTank() const; 

private: 


};
