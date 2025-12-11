// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kandahar/Structs/MenuDataStruct.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameMenuSubsystem.generated.h"

class UUserWidget;
class APlayerController;

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
	
	void SetMenuRegistry(const TMap<FString, FMenuDataStruct>& MenuData);

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void OpenMenu(FString MenuName);
	
	void OpenMenu(TSubclassOf<UUserWidget> MenuClass);
	
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void CloseCurrentMenu();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	void GoBack();

	UFUNCTION(BlueprintCallable, Category = "Menu")
	UUserWidget* GetCurrentMenu() const { return CurrentMenu; }
	
private:
	UPROPERTY()
	TMap<FString, FMenuDataStruct> MenuDataMap;
	
	UPROPERTY()
	UUserWidget* CurrentMenu = nullptr;
	
	UPROPERTY()
	TArray<TSubclassOf<UUserWidget>> MenuHistory;

	UPROPERTY(EditDefaultsOnly, Category = "Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Menu")
	TSubclassOf<UUserWidget> PauseMenuWidgetClass;
};