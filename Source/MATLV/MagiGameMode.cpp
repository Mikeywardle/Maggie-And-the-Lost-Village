// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiGameMode.h"
#include "MapEnemy.h"
#include "DialogueManager.h"
#include "BattleManager.h"
#include "Engine/Engine.h"

AMagiGameMode::AMagiGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	dialogueManager = CreateDefaultSubobject<UDialogueManager>(TEXT("dialogueManager"));
	battleManager = CreateDefaultSubobject<UBattleManager>(TEXT("battleManager"));
}

void AMagiGameMode::StartBattle(APawn* player, AMapEnemy* enemy)
{
	preBattleTransform = player->GetActorTransform();

	player->Destroy();
	enemy->Destroy();

	GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Red, TEXT("Initializing"));

	battleManager->InitializeBattle(enemy->enemiesPayload);
}

void AMagiGameMode::ReturnToOverworld()
{
	GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Blue, TEXT("Returning to overworld..."));

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	APawn* newOverworldPawn = SpawnDefaultPawnAtTransform(controller, preBattleTransform);
	controller->Possess(newOverworldPawn);
}
