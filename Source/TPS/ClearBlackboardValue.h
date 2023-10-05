// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BlackboardComponent.h"
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "ClearBlackboardValue.generated.h"

/**
 * 
 */
UCLASS()
class TPS_API UClearBlackboardValue : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UClearBlackboardValue();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
