// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Tanks/GameModes/TanksGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHealthComponent::AHealthComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	GameModeReference = Cast<ATanksGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage); //check AddDynamic for errors
}

void AHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage == 0) { return; }


	Health = FMath::Clamp(Health - Damage, 0.f, DefaultHealth);

	if(Health <= 0)
	{
		if (GameModeReference)
		{
			GameModeReference->ActorDied(GetOwner());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Game Mode Set"));
		}
	}
}



