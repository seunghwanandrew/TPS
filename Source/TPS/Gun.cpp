// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AGun::PullTrigger()
{
	if (AmmoInGun > 0)
	{
		UGameplayStatics::SpawnEmitterAttached(ShotEmitter, Mesh, "MuzzleFlashSocket");
		UGameplayStatics::SpawnSoundAttached(ShotSound, Mesh, "MuzzleFlashSocket");
	
		FHitResult Hit;
		FVector ShotDirection;

		bool bSuccess = GunTracer(Hit, ShotDirection);

		if (bSuccess)
		{	
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEmitter, Hit.Location, ShotDirection.Rotation());
			UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ShotImpactSound, Hit.Location);

			AActor* Target = Hit.GetActor();
			if (Target != nullptr)
			{
				AController* OwnerController = GetOwnerController();
				if (OwnerController == nullptr) return;
				FDamageEvent DamageEvent = FPointDamageEvent(DamageAmount, Hit, ShotDirection, nullptr);
				Target->TakeDamage(DamageAmount, DamageEvent, OwnerController, this);
			}
			AmmoInGun -= 1;
			UE_LOG(LogTemp, Warning, TEXT("Ammo is %i"), AmmoInGun);
		}
	}
	else if (AmmoInGun == 0)
	{
		ReloadBulletOnWeapon();
	}
	
	
}

void AGun::ReloadBulletOnWeapon()

{
	if (AmmoInGun != MaxAmmoInGun)
	{
		if(MaxAmmo - (MaxAmmoInGun - AmmoInGun) >= 0)
		{
			MaxAmmo -= (MaxAmmoInGun - AmmoInGun);
			AmmoInGun = MaxAmmoInGun;
			UE_LOG(LogTemp, Warning, TEXT("Ammo reloaded is %i"), AmmoInGun);
		}
		else
		{
			AmmoInGun += MaxAmmo;
			MaxAmmo = 0;
			UE_LOG(LogTemp, Warning, TEXT("MaxAmmo is %i"), MaxAmmo);
		}
	}
}


bool AGun::GunTracer(FHitResult &Hit, FVector &ShotDirection)
{
	FVector Location;
	FRotator Rotation;
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr) return false;
	OwnerController->GetPlayerViewPoint(Location, Rotation);

	FVector End = Location + Rotation.Vector() * MaxRange;
	ShotDirection = -Rotation.Vector();
	FCollisionQueryParams Param;
	Param.AddIgnoredActor(this);
	Param.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECC_GameTraceChannel1, Param);

}

AController *AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return nullptr;
	return OwnerPawn->GetController();    
}
