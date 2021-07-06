// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"

#include "VehicleBase.generated.h"

UCLASS()
class TANKS_API AVehicleBase : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UCapsuleComponent* CapsuleComponent = nullptr;

	UPROPERTY()
	UStaticMeshComponent* BaseMesh = nullptr;
	
	UPROPERTY()
	UStaticMeshComponent* TurretMesh = nullptr;
	
	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint = nullptr;
public:
	// Sets default values for this pawn's properties
	AVehicleBase();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
