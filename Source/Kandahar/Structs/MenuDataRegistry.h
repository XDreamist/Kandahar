// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuDataStruct.h"
#include "Engine/DataAsset.h"
#include "MenuDataRegistry.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class KANDAHAR_API UMenuDataRegistry : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu")
	TArray<FMenuDataStruct> MenuData;
};
