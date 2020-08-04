// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueManager.h"
#include "Kismet/GameplayStatics.h"
#include "CommonUtils.h"

// Sets default values for this component's properties
UDialogueManager::UDialogueManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UDialogueManager::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* gameInstance = GetOwner()->GetGameInstance();

	if (!ensure(gameInstance != nullptr))
		return;

	dialogueWidget = CreateWidget<UDialogueWidget>(gameInstance, WidgetClass);	
}


// Called every frame
void UDialogueManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDialogueManager::DisplayDialogue(FString text)
{

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	currentPlayer = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	currentPlayer->DisableInput(controller);


	nextLineBinding = controller->InputComponent->BindAction("Select",EInputEvent::IE_Released,this, &UDialogueManager::NextLine);
	dialogueWidget->AddToViewport(999);
}

void UDialogueManager::NextLine()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	currentPlayer->EnableInput(controller);

	CommonUtils::RemoveInputBinding(controller->InputComponent, nextLineBinding);

	dialogueWidget->RemoveFromParent();

}

