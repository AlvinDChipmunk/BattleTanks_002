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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair(); 

private:

	ATank* ControlledTank; 
};
