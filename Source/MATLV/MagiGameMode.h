// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MagiGameMode.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MATLV_API AMagiGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMagiGameMode(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadonly)
	class UDialogueManager* dialogueManager;

	UPROPERTY(EditAnywhere, BlueprintReadonly)
	class UBattleManager* battleManager;


	UFUNCTION(BlueprintCallable)
	void StartBattle(APawn* player, class AMapEnemy* enemy);


	UFUNCTION(BlueprintCallable)
	void ReturnToOverworld();

private:
	FTransform preBattleTransform;

};
