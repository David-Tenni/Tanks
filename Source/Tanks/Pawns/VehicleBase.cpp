// Fill out your copyright notice in the Description page of Project Settings.
#include "Tanks/Pawns/VehicleBase.h"
#include "Kismet/GameplayStatics.h"
#include "Tanks/Actors/ProjectileBase.h"



// Sets default values
AVehicleBase::AVehicleBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

}

void AVehicleBase::RotateTurret(FVector LookAtTarget)
{
	//turn towards actor
	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = FVector(LookAtTargetClean - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
}

void AVehicleBase::Fire()
{
	//instantiate bullet at projectile spawn point
	if(ProjectileClass)
	{
		FRotator TempRotation = ProjectileSpawnPoint->GetComponentRotation();
		FVector TempLocation = ProjectileSpawnPoint->GetComponentLocation();
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, TempLocation, TempRotation);

		TempProjectile->SetOwner(this);
	}
}

void AVehicleBase::HandleDestruction()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());
	//pawn turret spawn debris maybe
	//set player to dead, kill functionality, make invicible, move to spawn point, and respawn if lives > 0
}


void AVehicleBase::BeginPlay()
{
	Super::BeginPlay();
	
	BaseMesh->SetRelativeLocation(FVector(0.f, 0.f, -70.f));
}
