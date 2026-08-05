// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CropData.generated.h"

class UPaperSprite; 

UCLASS(BlueprintType)
class VEGGIEBATTLER_API UCropData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category= "Identity")
	FText DisplayName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Growth")
	float GrowTimeSeconds = 5.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Growth")
	TArray<TObjectPtr<UPaperSprite>> GrowthStages;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Battle", meta = (ClampMin = "1" ))
	int32 MaxHP = 20;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Battle", meta = (ClampMin = "0" ))
	int32 Attack = 5; 
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Battle", meta = (ClampMin = "0" ))
	int32 Defense = 3;
};
