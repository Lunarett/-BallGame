// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Multithreader.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMultithreader : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BALLGAME_API IMultithreader
{
	GENERATED_BODY()
		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Multithreaded")
		void MultithreadedFunction();
};
