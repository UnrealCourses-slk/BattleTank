// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/* self
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController BeginPlay, no tank ptr."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessed: %s."), *(ControlledTank->GetName()));
	}
	*/
	/* PlayerPawn */
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found: %s."), *(PlayerTank->GetName()));
	}
}


ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}else
	return Cast<ATank>(PlayerPawn);
}
