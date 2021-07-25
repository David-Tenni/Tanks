// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Tanks/Pawns/Tank.h"
#include "Tanks/Pawns/Turret.h"
#include "TanksGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class TANKS_API ATanksGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:

	
	ATank* Player;
	int32 TargetTurrets = 0;

	void HandleGameStart();
	void HandleGameOver(bool Victory);


public:

	void ActorDied(AActor* DeadActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 9;

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool Victory);
};
