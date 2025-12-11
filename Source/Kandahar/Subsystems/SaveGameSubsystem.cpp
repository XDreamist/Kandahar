// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameSubsystem.h"

void USaveGameSubsystem::SaveGame(const FString SlotName)
{
	UE_LOG(LogTemp, Log, TEXT("Starting Save for Slot: %s"), *SlotName);
	InternalLoad(SlotName);
}

void USaveGameSubsystem::LoadGame(const FString SlotName)
{
	UE_LOG(LogTemp, Log, TEXT("Loading Save from Slot: %s"), *SlotName);
	InternalLoad(SlotName);
}

TArray<FString> USaveGameSubsystem::GetAllSaveSlotNames() const
{
	TArray<FString> SlotNames;
	
	// (You can store known slot names in config or disk scan, but Unreal doesn’t have a built-in slot list)
	// Example: You can maintain a SaveSlots.txt file or cache them yourself in game logic
	
	return SlotNames;
}

void USaveGameSubsystem::InternalSave(FString SlotName)
{
	
}

void USaveGameSubsystem::InternalLoad(FString SlotName)
{
}
