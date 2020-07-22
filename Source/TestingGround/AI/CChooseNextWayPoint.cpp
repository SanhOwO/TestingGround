// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoute.h"
#include "AIController.h"
#include "CChooseNextWayPoint.h"

EBTNodeResult::Type UCChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto  BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	

	auto AIController = OwnerComp.GetAIOwner();
	auto ControllerPawn = AIController->GetPawn();
	auto PatrollingAI = Cast<UPatrolRoute>(ControllerPawn);
	TArray<AActor*> PatrolPoints = PatrollingAI->GetPatrolPoints();

	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	return EBTNodeResult::Succeeded;
}
