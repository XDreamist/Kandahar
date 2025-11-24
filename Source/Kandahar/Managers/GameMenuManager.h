// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameMenuManager.generated.h"

class UUserWidget;
class APlayerController;

enum EMenuType
{
	MainMenu,
	PauseMenu,
	SettingsMenu
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class KANDAHAR_API UGameMenuSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void OpenMenu(TSubclassOf<UUserWidget> MenuClass);
	
	void OpenMenu(EMenuType MenuType);
	
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void CloseCurrentMenu();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void GoBack();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	UUserWidget* GetCurrentMenu() const { return CurrentMenu; }
	
private:
	UPROPERTY()
	UUserWidget* CurrentMenu = nullptr;

	UPROPERTY()
	TArray<TSubclassOf<UUserWidget>> MenuHistory;

	UPROPERTY(EditDefaultsOnly, Category = "Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Menu")
	TSubclassOf<UUserWidget> PauseMenuWidgetClass;
};