// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

#include "Kandahar/Managers/GameMenuManager.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UGameMenuManager* GameMenuManager = GetGameInstance()->GetSubsystem<UGameMenuManager>())
	{
		GameMenuManager->OpenMenu(MainMenuWidgetClass);
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

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(BackAction, ETriggerEvent::Triggered, this, &ABasePlayerController::OnBackTriggered);
	}
}

void ABasePlayerController::OnBackTriggered()
{
	if (UGameMenuManager* GameMenuManager = GetGameInstance()->GetSubsystem<UGameMenuManager>())
	{
		if (GameMenuManager->GetCurrentMenu())
		{
			GameMenuManager->GoBack();
		}
		else
		{
			GameMenuManager->OpenMenu(EMenuType::PauseMenu);
		}
	}
}