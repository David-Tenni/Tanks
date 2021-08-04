// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleShip.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

void ABattleShip::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &ABattleShip::CheckFireCondition, FireRate, true);

	Player = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
void ABattleShip::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ABattleShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Player || ReturnDistanceToPlayer() > Range) { return; }
	RotateTurret(Player->GetActorLocation());
}
void ABattleShip::CheckFireCondition()
{
	if (!Player || Player->GetIsPlayerAlive() == false) { return; }
	// fire when inrange
	if (ReturnDistanceToPlayer() < Range)
	{
		Fire();
	}
}

float ABattleShip::ReturnDistanceToPlayer()
{
	if (!Player)
	{
		return 0.0f;
	}
	return FVector::Distance(Player->GetActorLocation(), GetActorLocation());
}




