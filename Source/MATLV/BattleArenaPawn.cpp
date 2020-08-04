// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleArenaPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "CommonUtils.h"
#include "MagiGameMode.h"
#include "BattleManager.h"
#include "Engine/Engine.h"
#include "UObject/ObjectMacros.h"

// Sets default values
ABattleArenaPawn::ABattleArenaPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("camera"));
	SetRootComponent(camera);

}

void ABattleArenaPawn::OnBattleStart()
{
	AddMainMenuSubscriptions();
}

void ABattleArenaPawn::ClearAllSubscriptions()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("ClearingBindings"));

	for (FInputActionBinding binding : currentButtonBindings)
	{
		CommonUtils::RemoveInputBinding(InputComponent, binding);
	}

	currentButtonBindings.Empty();

}

void ABattleArenaPawn::AddCombatant(ACombatant* toAdd)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Adding"));
	playableCombatants.Add(toAdd);
}

//Debug Method TOD: Remove once full flow implemented
void ABattleArenaPawn::EndBattle()
{
	AMagiGameMode* gm = Cast<AMagiGameMode>(GetWorld()->GetAuthGameMode());
	gm->battleManager->EndBattle();
}

//Bind button Action for this Pawn
void ABattleArenaPawn::BindAction(const FName ActionName, typename FInputActionHandlerSignature::TUObjectMethodDelegate<ABattleArenaPawn>::FMethodPtr Func)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Purple, ActionName.ToString());
	currentButtonBindings.Add(InputComponent->BindAction(ActionName, EInputEvent::IE_Released, this, Func));
}

void ABattleArenaPawn::DisplayNewWidget(TSubclassOf<UUserWidget> Widget)
{
	UGameInstance* gameInstance = GetGameInstance();

	if (!ensure(gameInstance != nullptr))
		return;

	if(currentWidget != nullptr)
		currentWidget->RemoveFromParent();

	currentWidget = CreateWidget<UUserWidget>(gameInstance, Widget);
	currentWidget->AddToViewport(999);
}

#pragma region MainMenuActions
void ABattleArenaPawn::AddMainMenuSubscriptions()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Adding Main subscriptions"));

	DisplayNewWidget(MainMenuWidget);

	ClearAllSubscriptions();

	//Debug Exit Battle
	BindAction("Select", &ABattleArenaPawn::EndBattle);
	BindAction("Button3", &ABattleArenaPawn::EnableTargetSelection);
	BindAction("Button4", &ABattleArenaPawn::Run);

}

void ABattleArenaPawn::Run()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Running..."));
	currentWidget->RemoveFromParent();
	EndBattle();
}

void ABattleArenaPawn::EnableTargetSelection()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Enabling Target Selection"));
	ClearAllSubscriptions();

	DisplayNewWidget(AttackWidget);

	//Debug Exit Battle
	BindAction("Select", &ABattleArenaPawn::EndBattle);

	BindAction("Button3", &ABattleArenaPawn::Attack);
	BindAction("Button1", &ABattleArenaPawn::AddMainMenuSubscriptions);
}


#pragma endregion

#pragma region TargetSelectionActions
void ABattleArenaPawn::ExitTargeting()
{

}

void ABattleArenaPawn::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("POW"));
}
#pragma endregion

