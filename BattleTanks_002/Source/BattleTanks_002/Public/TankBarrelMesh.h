// Copyright notice may not be needed for a demo portfolio game?

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrelMesh.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_002_API UTankBarrelMesh : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	void Elevate(float DegreesPerSecond); 

protected: 


private: 
	UPROPERTY(EditAnywhere)
		float AbsoluteElevationSpeed = 4.0f;
	
	float MaxPosElevationSpeed = +1.0 * AbsoluteElevationSpeed; 

	float MaxNegElevationSpeed = -1.0 * AbsoluteElevationSpeed;

};
