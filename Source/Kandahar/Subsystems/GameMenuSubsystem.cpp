// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMenuSubsystem.h"

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

void UGameMenuSubsystem::SetMenuRegistry(const TMap<FString, FMenuDataStruct>& MenuData)
{
	MenuDataMap = MenuData;
}

void UGameMenuSubsystem::OpenMenu(const FString MenuName)
{
	if (MenuDataMap.Contains(MenuName))
	{
		const FMenuDataStruct MainMenuData = MenuDataMap[MenuName];
		this->OpenMenu(MainMenuData.MenuClass);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to open Menu: %s, Menu doesn't exist or there's a typo."), *MenuName);
	}
}

// If not used for a while. Can be removed.
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
