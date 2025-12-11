// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "MenuDataStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FMenuDataStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu")
	TSubclassOf<class UUserWidget> MenuClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu")
	int32 ZOrder = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu")
	bool bPauseGame = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Menu")
	bool bIsExclusive = false;
};
