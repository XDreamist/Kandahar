// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SavableInterface.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class KANDAHAR_API USavableInterface : public UInterface
{
	GENERATED_BODY()
};

class KANDAHAR_API ISavableInterface : public UInterface
{
	GENERATED_BODY()
	
public:
	virtual void OnSaveGame(FString& OutData) = 0;
	
	virtual void OnLoadGame(const FString& InData) = 0;
	
	virtual FString GetSaveID() const = 0;
};