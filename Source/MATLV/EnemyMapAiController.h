// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyMapAiController.generated.h"

/**
 * 
 */
UCLASS()
class MATLV_API AEnemyMapAiController : public AAIController
{
	GENERATED_BODY()

public:

	void BeginPlay() override;
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:

	void MoveToTarget();

	class UNavigationWaypoints* waypointComponent;
	int currentTargetIndex;
	FVector currentTarget;
	
};
