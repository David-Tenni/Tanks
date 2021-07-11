// Fill out your copyright notice in the Description page of Project Settings.


#include "Tanks/Pawns/Turret.h"
#include "Kismet/GameplayStatics.h"


void ATurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &ATurret::CheckFireCondition, FireRate, true);
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATurret::CheckFireCondition()
{
    // dont fire when no player

    // fire when inrange

    UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}
