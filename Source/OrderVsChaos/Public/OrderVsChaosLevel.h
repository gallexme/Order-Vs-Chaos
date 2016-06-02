// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include "Chip.h"
#include "OrderVsChaosLevel.generated.h"

/**
 *
 */
UCLASS()
class ORDERVSCHAOS_API AOrderVsChaosLevel : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	template <class T>
	UFUNCTION(BlueprintCallable, Category = "Helpers")		
	static FORCEINLINE T get2D(const TArray<T>& elements, int yMax, int x, int y) {
		return elements[(y * yMax) + x];
	}
	UFUNCTION(BlueprintCallable, Category = "OrderVsChaos")
		bool CalculateOrderWin(TArray<AChip*> chips);
};
