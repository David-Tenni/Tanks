// Fill out your copyright notice in the Description page of Project Settings.
#include "Tanks/Pawns/VehicleBase.h"


// Sets default values
AVehicleBase::AVehicleBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void AVehicleBase::RotateTurretFunction(FVector LookAtTarget)
{
	//turn towards actor
}

void AVehicleBase::Fire()
{
	//instantiate bullet at projectile spawn point
}

void AVehicleBase::HandleDestruction()
{
	//spawn particles, play sound, shake camera
	//destroy self
	//pawn turret spawn debris maybe
	//set player to dead, kill functionality, make invicible, move to spawn point, and respawn if lives > 0
}


