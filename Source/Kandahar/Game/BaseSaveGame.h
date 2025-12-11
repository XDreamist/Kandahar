// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "BaseSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class KANDAHAR_API UBaseSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	// These types of data have to be wrapped up to store individual actor's data.
	UPROPERTY(VisibleAnywhere, Category="SaveGame")
	FTransform CharacterTransform;
	
	//UPROPERTY(VisibleAnywhere, Category="SaveGame")
	//int32 PlayerHealth;
	
	UPROPERTY(VisibleAnywhere, Category = "SaveGame")
	FDateTime SaveTime;

	UPROPERTY(VisibleAnywhere, Category = "SaveGame")
	FString SlotName;
};
