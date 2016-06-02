// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Chip.generated.h"
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class  EChipStateEnum : uint8
{
	GHOST 	UMETA(DisplayName = "Ghost"),
	RED 	UMETA(DisplayName = "Red"),
	BLUE	UMETA(DisplayName = "Blue")
};

UCLASS()
class ORDERVSCHAOS_API AChip : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EChipStateEnum State;
	// Sets default values for this actor's properties
	AChip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "OrderVsChaos")
	FORCEINLINE bool IsRed() {
		return this->State == EChipStateEnum::RED;

	}
	UFUNCTION(BlueprintCallable, Category = "OrderVsChaos")
		FORCEINLINE bool IsBlue() {
		return this->State == EChipStateEnum::BLUE;

	}
	UFUNCTION(BlueprintCallable, Category = "OrderVsChaos")
		FORCEINLINE bool IsGhost() {
		return this->State == EChipStateEnum::GHOST;

	}
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Ghostify"))
		void Ghostify();

};
