// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleManager.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "BattleArenaManager.h"
#include "MagiGameMode.h"
#include "BattleArenaPawn.h"
#include "Combatant.h"

// Sets default values for this component's properties
UBattleManager::UBattleManager()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBattleManager::BeginPlay()
{
	Super::BeginPlay();
	SetComponentTickEnabled(false);
}

// Called every frame
void UBattleManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FString output = TEXT("");

	for (int i = 0; i < pendingCombatants.Num(); i++) {

		ACombatant* combatant = pendingCombatants[i];
		combatant->OnBattleTick(DeltaTime);

		if (combatant->idleTimeRemaining<0)
		{
			pendingCombatants.Remove(combatant);
			playerPawn->AddCombatant(combatant);
			i--;
		}

		output.Append(combatant->GetName());
		output.Append("->");
		output.Append(FString::SanitizeFloat(combatant->idleTimeRemaining));
		output.Append(";");
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, output);
}

void UBattleManager::InitializeBattle(TArray<FCombatantData> enemies)
{	

	if (currentArena) {

		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Starting Battle"));

		UWorld* world = GetWorld();
		FVector zero = FVector::ZeroVector;

		for (int i = 0; i < 4; i++)
		{
			playerCombatants.Add(world->SpawnActor<ACombatant>());
		}

		LoadPendingCombatants();

		APlayerController* controller = GetWorld()->GetFirstPlayerController();
		playerPawn = currentArena->playerBattlePawn;

		controller->Possess(playerPawn);
		currentArena->playerBattlePawn->OnBattleStart(); 

		PlayBattle();
	}
}

void UBattleManager::SetCurrentBattleArena(ABattleArenaManager* currentArena)
{
	this->currentArena = currentArena;
}

void UBattleManager::EndBattle()
{
	PauseBattle();
	ClearCombatants();
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Ending Battle"));

	AMagiGameMode* gameMode = Cast<AMagiGameMode>(GetOwner());
	gameMode->ReturnToOverworld();
}

void UBattleManager::PlayBattle()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Playing Battle"));
	SetComponentTickEnabled(true);
}

void UBattleManager::PauseBattle()
{
	SetComponentTickEnabled(false);
}

void UBattleManager::LoadPendingCombatants()
{
	for(ACombatant* combatant : playerCombatants)
	{
		pendingCombatants.Add(combatant);
	}
}

void UBattleManager::ClearCombatants()
{
	for (ACombatant* combatant : playerCombatants)
	{
		combatant->Destroy();
	}

	playerCombatants.Empty();
	pendingCombatants.Empty();
}

