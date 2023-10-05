// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DamageEvents.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TPS_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

	void ReloadBulletOnWeapon();

	bool GunTracer(FHitResult &OutHit, FVector &OutShotDirection);

	AController* GetOwnerController() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AmmoInGun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAmmoInGun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReloadTime;

private:
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ShotEmitter;

	UPROPERTY(EditAnywhere)
	USoundBase* ShotSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEmitter;

	UPROPERTY(EditAnywhere)
	USoundBase* ShotImpactSound;

	UPROPERTY(EditAnywhere)
	float MaxRange {2000};

	UPROPERTY(EditAnywhere)
	float DamageAmount {10};

};
