// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

#include "Kandahar/Subsystems/GameMenuSubsystem.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Main Menu when game begins
	if (UGameMenuSubsystem* GameMenuSubsystem = GetGameInstance()->GetSubsystem<UGameMenuSubsystem>())
	{
		GameMenuSubsystem->OpenMenu("MainMenu");
	}
	
	if (MenuMappingContext && BackAction)
	{
		if (const ULocalPlayer* LocalPlayer = GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				EnhancedInputLocalPlayerSubsystem->AddMappingContext(MenuMappingContext, 0);
			}	
		}
	}

	// Input Events
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(BackAction, ETriggerEvent::Triggered, this, &ABasePlayerController::OnBackTriggered);
	}
}

void ABasePlayerController::OnBackTriggered()
{
	if (UGameMenuSubsystem* GameMenuSubsystem = GetGameInstance()->GetSubsystem<UGameMenuSubsystem>())
	{
		if (GameMenuSubsystem->GetCurrentMenu())
		{
			GameMenuSubsystem->GoBack();
		}
		else
		{
			GameMenuSubsystem->OpenMenu("PauseMenu");
		}
	}
}