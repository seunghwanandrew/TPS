// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearBlackboardValue.h"

UClearBlackboardValue::UClearBlackboardValue()
{
    NodeName = TEXT("Clear Black Board Value");
}

EBTNodeResult::Type UClearBlackboardValue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    return EBTNodeResult::Succeeded;
}
