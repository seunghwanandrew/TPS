// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAll.h"

void AKillEmAll::PawnKilled(APawn *PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    ATPSPlayerController* Player = Cast<ATPSPlayerController>(PawnKilled->GetController());

    if (Player != nullptr)
    {
        GameEnd(false);
    }

    for (AAI_Shooter_Controller* AIController : TActorRange<AAI_Shooter_Controller>(GetWorld()))
    {
        if (!AIController->IsAllDead())
        {
            return;
        }
    }

    GameEnd(true);
}

void AKillEmAll::GameEnd(bool bIsPlayerWinner)
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
            Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}
