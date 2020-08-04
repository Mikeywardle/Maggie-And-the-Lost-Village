// Fill out your copyright notice in the Description page of Project Settings.


#include "Combatant.h"
#include "Components/SkeletalMeshComponent.h"
// Sets default values
ACombatant::ACombatant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("mesh"));
	SetRootComponent(mesh);
}

// Called when the game starts or when spawned
void ACombatant::BeginPlay()
{
	Super::BeginPlay();	

	idleTimeRemaining = totalIdleTime;
}

void ACombatant::OnBattleTick(float deltaTime)
{
	idleTimeRemaining -= deltaTime;
}

