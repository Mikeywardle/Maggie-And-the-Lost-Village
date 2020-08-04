// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/UserWidget.h"
#include "BattleArenaPawn.generated.h"

UCLASS()
class MATLV_API ABattleArenaPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABattleArenaPawn();

public:	

	UFUNCTION(BlueprintCallable)
	void OnBattleStart();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* camera;

	UFUNCTION(BlueprintCallable)
	void ClearAllSubscriptions();

	UFUNCTION(BlueprintCallable)
	void AddCombatant(class ACombatant* toAdd);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> MainMenuWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> AttackWidget;


private:
	UUserWidget* currentWidget;

	void DisplayNewWidget(TSubclassOf<UUserWidget> Widget);

	// Main Menu Methods
	void AddMainMenuSubscriptions();
	void Run();
	void EnableTargetSelection();

	//Target Selection Methods
	void ExitTargeting();
	void Attack();

	//TODO: Remove once full flow implemented
	void EndBattle();

	void BindAction(const FName ActionName, typename FInputActionHandlerSignature::TUObjectMethodDelegate<ABattleArenaPawn>::FMethodPtr Func);

	TArray<struct FInputActionBinding> currentButtonBindings;
	TArray<class ACombatant*> playableCombatants;

};
