// Fill out your copyright notice in the Description page of Project Settings.

#include "CChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolRoute.h"
#include "AIController.h"


EBTNodeResult::Type UCChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto AIController = OwnerComp.GetAIOwner();
	auto ControllerPawn = AIController->GetPawn();
	auto PatrolRoute = ControllerPawn->FindComponentByClass<UPatrolRoute>();

	if (!PatrolRoute) { return EBTNodeResult::Failed; }
	
	TArray<AActor*> PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp,Warning,TEXT("No PatrolPoints"));
		return EBTNodeResult::Failed;
	}
		

	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]);

	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	return EBTNodeResult::Succeeded;
}
