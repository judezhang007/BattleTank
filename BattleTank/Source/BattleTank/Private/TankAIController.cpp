// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
//Depends on movement component via path finding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	
	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim at the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//Fire when ready
	AimingComponent->Fire(); // todo fix me
	
}