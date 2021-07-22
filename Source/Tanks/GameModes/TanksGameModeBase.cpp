// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameModeBase.h"
#include "Tanks/Pawns/Tank.h"
#include "Tanks/Pawns/Turret.h"
#include "Kismet/GameplayStatics.h"

void ATanksGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//get referennces
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATurret::StaticClass(), TurretActors);
	
	TargetTurrets = TurretActors.Num();
	Player = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	//callstart game
}


void ATanksGameModeBase::ActorDied(AActor* DeadActor)
{
	if(DeadActor == Player)
	{
		Player->HandleDestruction();
		HandleGameOver(false);
	}
	else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		if (--TargetTurrets == 0)
		{
			HandleGameOver(true);
		}
	}
	//turret death add to score player death call game over
}

void ATanksGameModeBase::HandleGameStart()
{
	//initialise the countdown activate turrets check pawn
	//caal gamestart in bp
}

void ATanksGameModeBase::HandleGameOver(bool Victory)
{
	//show win if all turrets ded
	//if player dead show lose
	//call bp gameover
}


