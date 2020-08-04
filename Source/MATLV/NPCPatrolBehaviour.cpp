// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCPatrolBehaviour.h"
#include "NavigationWaypoints.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

// Sets default values for this component's properties
UNPCPatrolBehaviour::UNPCPatrolBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNPCPatrolBehaviour::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();
	patrolPoints = owner->FindComponentByClass<UNavigationWaypoints>();

	aiController = UAIBlueprintHelperLibrary::GetAIController(owner);
}


// Called every frame
void UNPCPatrolBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNPCPatrolBehaviour::SetPatrolPoints(UNavigationWaypoints* patrolPoints)
{
	this->patrolPoints = patrolPoints;
	currentTargetIndex = 0;
}

