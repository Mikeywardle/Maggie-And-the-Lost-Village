// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UI/DialogueWidget.h"
#include "Components/InputComponent.h"
#include "DialogueManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MATLV_API UDialogueManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDialogueManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDialogueWidget> WidgetClass;

	UFUNCTION(BlueprintCallable)
	void DisplayDialogue(FString text);

private:

	APawn* currentPlayer;

	void NextLine();
	UDialogueWidget* dialogueWidget;

	FInputActionBinding nextLineBinding;
};
