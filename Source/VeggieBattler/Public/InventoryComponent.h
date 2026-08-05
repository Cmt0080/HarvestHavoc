// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UCropData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VEGGIEBATTLER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	bool AddCrop(UCropData* Crop);
	
	UFUNCTION(BlueprintCallable, Category= "Inventory")
	bool RemoveCrop(UCropData* Crop);
	
	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool HasCrop(UCropData* Crop) const;
	
	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetCropCount() const { return OwnedCrops.Num(); }
	
	UFUNCTION (BlueprintPure, Category = "Inventory")
	const TArray<UCropData*>& GetOwnedCrops() const { return OwnedCrops; }
	
	UFUNCTION (BlueprintPure, Category = "Inventory")
	bool CanSwap() const { return OwnedCrops.Num() > 1;}
	
	UPROPERTY(BlueprintAssignable,Category= "Inventory")
	FOnInventoryChanged OnInventoryChanged;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Inventory")
	int32 MaxCrops = 6; 
	

protected:
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Inventory")
	TArray<TObjectPtr<UCropData>> OwnedCrops;

		
};
