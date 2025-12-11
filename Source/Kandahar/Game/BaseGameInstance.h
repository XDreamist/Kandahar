// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class KANDAHAR_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Shutdown() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Menu")
	TObjectPtr<class UMenuDataRegistry> MenuRegistry;
};
