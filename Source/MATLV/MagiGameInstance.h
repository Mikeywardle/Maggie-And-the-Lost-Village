// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CombatantData.h"
#include "MagiGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MATLV_API UMagiGameInstance : public UGameInstance
{
	GENERATED_BODY()

	TArray<FCombatantData> PartyMemebers = TArray<FCombatantData>();
	
};
