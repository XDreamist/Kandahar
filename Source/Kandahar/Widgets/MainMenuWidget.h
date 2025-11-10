// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMenuWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class KANDAHAR_API UMainMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UButton* ContinueButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* NewGameButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* NewGamePlusButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* LoadButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* SettingsButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* ExtrasButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* ExitButton;

	UPROPERTY(EditAnywhere, Category = "Menu")
	TSubclassOf<UUserWidget> SettingsMenuClass;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void OnContinueClicked();
	
	UFUNCTION()
	void OnNewGameClicked();

	UFUNCTION()
	void OnNewGamePlusClicked();

	UFUNCTION()
	void OnLoadClicked();
	
	UFUNCTION()
	void OnSettingsClicked();

	UFUNCTION()
	void OnExtrasClicked();

	UFUNCTION()
	void OnExitClicked();
};
