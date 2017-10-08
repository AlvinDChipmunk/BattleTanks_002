// Copyright notice may not be needed for a demo portfolio game?

#include "BattleTanks_002.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	auto OurTankName = GetName(); 

	if (!(HitLocation.IsZero()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank.cpp - %s aiming at: %s"), *OurTankName, *(HitLocation.ToString()));
	} 
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank.cpp - %s could NOT get HitLocation.  Possible out of range target status."), *OurTankName);
	}
	
}

