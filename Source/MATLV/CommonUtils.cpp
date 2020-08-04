// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonUtils.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Object.h"

void CommonUtils::RemoveInputBinding(UInputComponent* inputComponent, FInputActionBinding toRemove)
{
    for (int i = 0; i < inputComponent->GetNumActionBindings(); i++)
    {
        FInputActionBinding binding = inputComponent->GetActionBinding(i);
        if (CompareInputBindings(binding, toRemove))
        {
            inputComponent->RemoveActionBinding(i);
            i--;
            continue;
        }
    }}

bool CommonUtils::CompareInputBindings(FInputActionBinding a, FInputActionBinding b)
{
	return a.ActionDelegate.GetDelegateForManualSet().GetHandle() == b.ActionDelegate.GetDelegateForManualSet().GetHandle() &&
		a.GetActionName() == b.GetActionName();
}
