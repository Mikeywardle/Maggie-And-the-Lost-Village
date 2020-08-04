// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatantData.h"
#include "BattleManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MATLV_API UBattleManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBattleManager();

protected:

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void InitializeBattle(TArray<FCombatantData> enemies);

	UFUNCTION(BlueprintCallable)
	void SetCurrentBattleArena(class ABattleArenaManager* currentArena);

	UFUNCTION(BlueprintCallable)
	void EndBattle();

	UFUNCTION(BlueprintCallable)
	void PlayBattle();

	UFUNCTION(BlueprintCallable)
	void PauseBattle();


private:

	class ABattleArenaManager* currentArena;

	TArray<class ACombatant*> pendingCombatants;
	TArray<class ACombatant*> playerCombatants;

	void LoadPendingCombatants();
	void ClearCombatants();


	class ABattleArenaPawn* playerPawn;


		
};
