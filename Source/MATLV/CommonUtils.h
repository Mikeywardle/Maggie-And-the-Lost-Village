// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MATLV_API CommonUtils
{
public:

	static void RemoveInputBinding(class UInputComponent*, struct FInputActionBinding binding);

private:
	static bool CompareInputBindings(struct FInputActionBinding a, struct FInputActionBinding b);
};
