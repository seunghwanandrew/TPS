// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Shooter.h"
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIShooting.generated.h"

/**
 * 
 */
UCLASS()
class TPS_API UAIShooting : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UAIShooting();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
