// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI_Shooter_Controller.h"
#include "EngineUtils.h"
#include "TPSPlayerController.h"
#include "CoreMinimal.h"
#include "TPSGameModeBase.h"
#include "KillEmAll.generated.h"

/**
 * 
 */
UCLASS()
class TPS_API AKillEmAll : public ATPSGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled) override;

private:
	void GameEnd(bool bIsPlayerWinner);
};
