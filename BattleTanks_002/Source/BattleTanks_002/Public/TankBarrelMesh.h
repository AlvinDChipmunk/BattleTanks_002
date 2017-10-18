// Copyright notice may not be needed for a demo portfolio game?

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrelMesh.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent), hidecategories = ("Collision") )
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_002_API UTankBarrelMesh : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	void Elevate(float DegreesPerSecond); 

protected: 


private: 
	UPROPERTY(EditAnywhere, Category = Setup)
		float AbsoluteElevationSpeed = 4.0f;
	
	//How far does the barrel elevate up? 
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationAngle = 60.0f;

	//How fast does the barrel elevate up? 
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxPosElevationSpeed = +1.0 * AbsoluteElevationSpeed;

	//How far does the barrel elevate down?
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationAngle = 0.0f;

	//How fast does the barrel elevate down?
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxNegElevationSpeed = -1.0 * AbsoluteElevationSpeed;

};
