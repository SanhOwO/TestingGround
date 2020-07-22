// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGround/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingAI.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API APatrollingAI : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly,Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;
};
