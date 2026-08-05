// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VeggieGameInstance.generated.h"

class UCropData;

UCLASS()
class VEGGIEBATTLER_API UVeggieGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Persistent")
	TArray<TObjectPtr<UCropData>> SavedRoster; 
	
	UPROPERTY(BlueprintReadWrite, Category = "Battle Transit")
	TObjectPtr<UCropData> PendingBattleCrop;
	
	UPROPERTY(BlueprintReadWrite, Category = "Battle Transit")
	bool bLastBattleWon = false;
	
	UFUNCTION(BlueprintCallable, Category = "Battle Transit")
	void StartBattleWith(UCropData* Crop);
	
};
