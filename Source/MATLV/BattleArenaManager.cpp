// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleArenaManager.h"
#include "BattleManager.h"
#include "MagiGameMode.h"

// Sets default values
ABattleArenaManager::ABattleArenaManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABattleArenaManager::BeginPlay()
{
	Super::BeginPlay();

	AMagiGameMode* gameMode = GetWorld()->GetAuthGameMode<AMagiGameMode>();
	gameMode->battleManager->SetCurrentBattleArena(this);
	
}

// Called every frame
void ABattleArenaManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

