// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CChooseNextWayPoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API UCChooseNextWayPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnyWhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey; //在细节面板添加接口

	UPROPERTY(EditAnyWhere, Category = "Blackboard")
	struct FBlackboardKeySelector WayPointKey; //在细节面板添加接口
};
