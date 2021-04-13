// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"
#include "Multithreader.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MultithreaderLibrary.generated.h"

class MultithreadedTask : public FNonAbandonableTask {
public:
	MultithreadedTask(UObject* object) { this->object = object; }
	UObject* object;
	FORCEINLINE TStatId GetStatId() const {
		RETURN_QUICK_DECLARE_CYCLE_STAT(MultithreadedTask, STATGROUP_ThreadPoolAsyncTasks);
	}
	void DoWork()
	{
		IMultithreader::Execute_MultithreadedFunction(object);
	}
};

/**
 * 
 */


UCLASS()
class BALLGAME_API UMultithreaderLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		static void CallMultithreadedFunction(UObject* object) {
		(new FAutoDeleteAsyncTask<MultithreadedTask>(object))->StartBackgroundTask();
	}
};
