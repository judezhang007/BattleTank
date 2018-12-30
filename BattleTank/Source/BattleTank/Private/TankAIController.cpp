// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PLayerTank = GetPlayerTank();
	if (!PLayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Tank can't find the player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank found player: %s"), *PLayerTank->GetName());
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//Move towards the player

		//Aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()); 

		//Fire when ready
	}

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);

}