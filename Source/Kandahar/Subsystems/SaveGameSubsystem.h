// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Kandahar/Game/BaseSaveGame.h"
#include "Kandahar/Interfaces/SavableInterface.h"
#include "SaveGameSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSaveCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadCompleted);

/**
 * 
 */
UCLASS()
class KANDAHAR_API USaveGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FOnSaveCompleted OnSaveCompleted;
	
	UPROPERTY(BlueprintAssignable)
	FOnLoadCompleted OnLoadCompleted;
	
	UFUNCTION(BlueprintCallable)
	void SaveGame(FString SlotName = TEXT("Default"));
	
	UFUNCTION(BlueprintCallable)
	void LoadGame(FString SlotName = TEXT("Default"));
	
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllSaveSlotNames() const;
	
private:
	void InternalSave(FString SlotName);
	void InternalLoad(FString SlotName);
};
