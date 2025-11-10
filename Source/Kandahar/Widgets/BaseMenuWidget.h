// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class KANDAHAR_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION(BlueprintCallable, Category = "Menu")
	virtual void Show();
	
	UFUNCTION(BlueprintCallable, Category = "Menu")
	virtual void Hide();
	
	UFUNCTION(BlueprintCallable, Category = "Menu")
	virtual void OnBackPressed();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	bool CanAutoHandleBack = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UBaseMenuWidget> PreviousMenuClass;
};
