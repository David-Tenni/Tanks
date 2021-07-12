// Fill out your copyright notice in the Description page of Project Settings.


#include "Tanks/Pawns/Turret.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

void ATurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &ATurret::CheckFireCondition, FireRate, true);

    Player = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATurret::CheckFireCondition()
{
    // dont fire when no player

    if (!Player) { return; }
    // fire when inrange
    if (ReturnDistanceToPlayer() < Range )
    {
        UE_LOG(LogTemp, Warning, TEXT("Fire"));

    }
}

float ATurret::ReturnDistanceToPlayer()
{
    if (!Player) 
    { 
        return 0.0f; 
    }
    return FVector::Distance(Player->GetActorLocation(), GetActorLocation());
}
