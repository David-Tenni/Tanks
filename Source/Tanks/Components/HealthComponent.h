// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tanks/GameModes/TanksGameModeBase.h"
#include "HealthComponent.generated.h"

UCLASS()
class TANKS_API AHealthComponent : public AActor
{
	GENERATED_BODY()
private:
	
	UPROPERTY(EditAnywhere)
	float DefaultHealth = 100.f;
	float Health = 0.f;

	ATanksGameModeBase* GameModeReference;

public:	
	// Sets default values for this actor's properties
	AHealthComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

};
