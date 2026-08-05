// Fill out your copyright notice in the Description page of Project Settings.


#include "VeggieGameInstance.h"
#include "CropData.h"
#include "Kismet/GameplayStatics.h"

void UVeggieGameInstance::StartBattleWith(UCropData* Crop)
{
	if (!Crop) return;
	
	PendingBattleCrop = Crop;
	UGameplayStatics::OpenLevel(this, FName("L_Battle"));
}

