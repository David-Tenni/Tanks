// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameModeBase.h"

void ATanksGameModeBase::BeginPlay()
{
	//get referennces
	//callstart game
}


void ATanksGameModeBase::ActorDied(AActor* DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("A Pawn is dead"));

	//turret death add to score player death call game over
}

void ATanksGameModeBase::HandleGameStart()
{
	//initialise the countdown activate turrets check pawn
	//caal gamestart in bp
}

void ATanksGameModeBase::HandleGameOver()
{
	//show win if all turrets ded
	//if player dead show lose
	//call bp gameover
}


