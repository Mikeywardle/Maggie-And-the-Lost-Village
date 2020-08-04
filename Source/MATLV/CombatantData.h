// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CombatantData.generated.h"

USTRUCT(BlueprintType)
struct FCombatantData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FCombatantData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int maxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int health;

};
