// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerLocation.h"

UPlayerLocation::UPlayerLocation()
{
    NodeName = TEXT("Update Player Location");
}

void UPlayerLocation::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp,NodeMemory, DeltaSeconds);

    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    
    if (Player == nullptr) return;
    
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),Player->GetActorLocation());
}
