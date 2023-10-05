// Fill out your copyright notice in the Description page of Project Settings.


#include "AIShooting.h"

UAIShooting::UAIShooting()
{
    NodeName = TEXT("Shooting");
}

EBTNodeResult::Type UAIShooting::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AShooter* AIPawn = Cast<AShooter>(OwnerComp.GetAIOwner()->GetPawn());

    if(AIPawn == nullptr) return EBTNodeResult::Failed;

    AIPawn->Shoot();

    return EBTNodeResult::Succeeded;
}
