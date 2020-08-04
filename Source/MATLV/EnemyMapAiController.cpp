// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMapAiController.h"
#include "NavigationWaypoints.h"
#include "Engine/Engine.h"

void AEnemyMapAiController::BeginPlay()
{
	Super::BeginPlay();

	waypointComponent = GetPawn()->FindComponentByClass<UNavigationWaypoints>();

	if (waypointComponent)
	{
		GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Red, TEXT("Setting target"));
		MoveToTarget();
	}

}

void AEnemyMapAiController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	currentTargetIndex++;

	if (currentTargetIndex >= waypointComponent->waypoints.Num())
		currentTargetIndex = 0;

	MoveToTarget();
}

void AEnemyMapAiController::MoveToTarget()
{
	currentTarget = waypointComponent->GetComponentLocation() + waypointComponent->waypoints[currentTargetIndex];
	MoveToLocation(currentTarget);
}

