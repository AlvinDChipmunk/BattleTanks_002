// Copyright notice may not be needed for a demo portfolio game?

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_002_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent(); 

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet); 

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	
	void AimAt(FVector HitLocation); 

protected: 

private: 
	UStaticMeshComponent* Barrel = nullptr; 
	
};
