// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMenuManager.h"

#include <stdexcept>

#include "Blueprint/UserWidget.h"

void UGameMenuSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UGameMenuSubsystem::Deinitialize()
{
	this->CloseCurrentMenu();
	Super::Deinitialize();
}

void UGameMenuSubsystem::OpenMenu(const TSubclassOf<UUserWidget> MenuClass)
{
	if (!MenuClass || !GetWorld()) return;

	if (CurrentMenu && CurrentMenu->GetClass() != MenuClass)
	{
		MenuHistory.Add(CurrentMenu->GetClass());
	}
	
	this->CloseCurrentMenu();

	if (UUserWidget* NewMenu = CreateWidget<UUserWidget>(GetWorld(), MenuClass)) {
		NewMenu->AddToViewport(100);
		CurrentMenu = NewMenu;

		if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController()) {
			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(NewMenu->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputMode);
			PlayerController->SetShowMouseCursor(true);
			PlayerController->SetPause(true);
		}
	}
}

void UGameMenuSubsystem::OpenMenu(const EMenuType MenuType) {
	switch (MenuType)
	{
		case EMenuType::MainMenu:
			{
				this->OpenMenu(MainMenuWidgetClass);
				break;
			}
		case EMenuType::PauseMenu:
			{
				this->OpenMenu(PauseMenuWidgetClass);
				break;
			}
		default:
			{
				throw std::runtime_error("Unknown Menu Type or unimplemented menu type for this functionality");
			}
	}
}

void UGameMenuSubsystem::CloseCurrentMenu()
{
	if (CurrentMenu) {
		CurrentMenu->RemoveFromParent();
		CurrentMenu = nullptr;

		if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController()) {
			PlayerController->SetInputMode(FInputModeGameOnly());
			PlayerController->SetShowMouseCursor(false);
			PlayerController->SetPause(false);
		}
	}
}

void UGameMenuSubsystem::GoBack()
{
	if (MenuHistory.Num() > 0)
	{
		const TSubclassOf<UUserWidget> PreviousWidget = MenuHistory.Pop();
		OpenMenu(PreviousWidget);
	}
	else
	{
		this->CloseCurrentMenu();
	}
}
