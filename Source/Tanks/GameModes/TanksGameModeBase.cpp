// Fill out your copyright notice in the Description page of Project Settings.


#include "TanksGameModeBase.h"
#include "Tanks/Pawns/Tank.h"
#include "Tanks/Pawns/Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Tanks/Controllers/PlayerControllerBase.h"

void ATanksGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//get referennces
	

	HandleGameStart();
}



void ATanksGameModeBase::ActorDied(AActor* DeadActor)
{
	if(DeadActor == Player)
	{
		Player->HandleDestruction();
		HandleGameOver(false);

		if (PlayerControllerReference) 
		{
			PlayerControllerReference->SetPlayerEnabledState(false);
		}
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
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATurret::StaticClass(), TurretActors);

	PlayerControllerReference = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	TargetTurrets = TurretActors.Num();
	Player = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GameStart();
	if (PlayerControllerReference)
	{
		PlayerControllerReference->SetPlayerEnabledState(false);
		
		FTimerHandle PlayerEnableHandle;
		FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerControllerReference, 
			&APlayerControllerBase::SetPlayerEnabledState, true);

		GetWorld()->GetTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
	}
}

void ATanksGameModeBase::HandleGameOver(bool Victory)
{
	GameOver(Victory);
}


