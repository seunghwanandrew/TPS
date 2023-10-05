// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Shooter_Controller.h"

void AAI_Shooter_Controller::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

bool AAI_Shooter_Controller::IsAllDead() const
{
    AShooter* ControlledCharacter = Cast<AShooter>(GetPawn());
    if (ControlledCharacter != nullptr) {
        return ControlledCharacter->IsDead();
    }
    return true;
}

void AAI_Shooter_Controller::BeginPlay()
{
    Super::BeginPlay();

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    APawn* AIPawn = GetPawn();
    if (AIBehavior != nullptr)
    {
        AAIController::RunBehaviorTree(AIBehavior);
        FVector PlayerLocation = PlayerPawn->GetActorLocation();
        GetBlackboardComponent()->SetValueAsVector("PlayerLocation", PlayerLocation);
        GetBlackboardComponent()->SetValueAsVector("StartLocation", AIPawn->GetActorLocation());
    }

}
    
