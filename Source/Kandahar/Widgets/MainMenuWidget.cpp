// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "Components/Button.h"
#include "Kandahar/Managers/GameMenuManager.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ContinueButton)    ContinueButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnContinueClicked);
	if (NewGameButton)     NewGameButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnNewGameClicked);
	if (NewGamePlusButton) NewGamePlusButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnNewGameClicked);
	if (LoadButton)        LoadButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnLoadClicked);
	if (SettingsButton)    SettingsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnSettingsClicked);
	if (ExtrasButton)      ExtrasButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnExtrasClicked);
	if (ExitButton)        ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnExitClicked);
}

void UMainMenuWidget::OnContinueClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("GameLevel"));
}

void UMainMenuWidget::OnNewGameClicked()
{
}

void UMainMenuWidget::OnNewGamePlusClicked()
{
}

void UMainMenuWidget::OnLoadClicked()
{
}

void UMainMenuWidget::OnSettingsClicked()
{
	if (UGameMenuManager* GameMenuManager = GetGameInstance()->GetSubsystem<UGameMenuManager>())
	{
		if (SettingsMenuClass)
		{
			GameMenuManager->OpenMenu(SettingsMenuClass);
		}
	}
}

void UMainMenuWidget::OnExtrasClicked()
{
	
}

void UMainMenuWidget::OnExitClicked()
{
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		GetWorld()->GetFirstPlayerController(),
		EQuitPreference::Quit,
		false
		);
}