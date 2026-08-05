// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "CropData.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInventoryComponent::AddCrop(UCropData* Crop)
{
	if (!Crop) return false;
	if (OwnedCrops.Num() >= MaxCrops) return false;
	
	OwnedCrops.Add(Crop);
	OnInventoryChanged.Broadcast();
	return true;
}

bool UInventoryComponent::RemoveCrop(UCropData* Crop)
{
	if (!Crop) return false;
	
	const int32 Removed = OwnedCrops.RemoveSingle(Crop);
	if  (Removed > 0)
	{
		OnInventoryChanged.Broadcast();
		return true;
	}
	return false;
}

bool UInventoryComponent::HasCrop(UCropData* Crop) const
{
	return Crop != nullptr && OwnedCrops.Contains(Crop);
}
