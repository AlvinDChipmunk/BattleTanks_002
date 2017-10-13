// Copyright notice may not be needed for a demo portfolio game?

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrelMesh; 

UCLASS()
class BATTLETANKS_002_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);

	float GetLaunchSpeed();

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrelMesh* BarrelToSet);

protected: 
	UTankAimingComponent* TankAimingComponent; 


private: 
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000.0f; // hope this is a sensible starting value, 1000 meters per second 

	float VisibleLaunchSpeed; 


};
