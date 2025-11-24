// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KANDAHAR_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Input")
	const UInputMappingContext* MenuMappingContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* BackAction;

	virtual void BeginPlay() override;
	void OnBackTriggered();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
};
