// Fill out your copyright notice in the Description page of Project Settings.


#include "MapEnemy.h"


// Sets default values
AMapEnemy::AMapEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMapEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMapEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

