#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class ATanksGameModeBase;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
		float DefaultHealth = 100.0f;
	float Health = 0.0f;

	ATanksGameModeBase* GameModeReference;

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
		void TakeDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

};
