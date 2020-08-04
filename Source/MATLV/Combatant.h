// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combatant.generated.h"

UCLASS()
class MATLV_API ACombatant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombatant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	virtual void OnBattleTick(float deltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float idleTimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float totalIdleTime = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool initialPlayerAllegiance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool playerAllegiance;


};
