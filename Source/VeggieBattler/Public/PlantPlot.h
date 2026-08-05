// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantPlot.generated.h"

class UCropData;

UENUM(BlueprintType)
enum class EPlotState : uint8
{
	Empty		UMETA(DisplayName = "Empty"),
	Growing		UMETA(DisplayName = "Growing"),
	Ready		UMETA(DisplayName = "Ready"),
};

UCLASS(Blueprintable)
class VEGGIEBATTLER_API APlantPlot : public AActor
{
	GENERATED_BODY()

public:
	APlantPlot();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "PlantPlot")
	TObjectPtr<UCropData> CropToGrow;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant Plot")
	float GrowTimeSeconds = 5.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plant Plot")
	EPlotState CurrentState = EPlotState::Empty;

	UFUNCTION(BlueprintCallable, Category = "Plant Plot")
	void Interact();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Plant Plot")
	void OnStateChanged(EPlotState NewState);

private:
	void SetState(EPlotState NewState);
	void FinishGrowing();

	FTimerHandle GrowTimerHandle;
};