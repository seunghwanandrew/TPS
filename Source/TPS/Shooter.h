// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TPSGameModeBase.h"
#include "Components/Capsulecomponent.h"
#include "Gun.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Shooter.generated.h"

UCLASS()
class TPS_API AShooter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Shoot();
	void ReloadWeapon();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;


	UPROPERTY(EditDefaultsOnly)
	float Health;

	UPROPERTY(EditAnywhere)
	float MaxHealth {100};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	AGun* Gun;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UFUNCTION(BlueprintPure)
	float GetPlayerHealth() const;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;
};
