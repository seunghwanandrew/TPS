// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Shooter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Shooter_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TPS_API AAI_Shooter_Controller : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	bool IsAllDead() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
};
