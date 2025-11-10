// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenuWidget.h"

#include "Kandahar/Managers/GameMenuManager.h"

void UBaseMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UBaseMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UBaseMenuWidget::Show()
{
	AddToViewport();
	SetKeyboardFocus();
}

void UBaseMenuWidget::Hide()
{
	RemoveFromParent();
}

void UBaseMenuWidget::OnBackPressed()
{
	if (CanAutoHandleBack && PreviousMenuClass)
	{
		if (UGameMenuManager* GameMenuManager = GetGameInstance()->GetSubsystem<UGameMenuManager>())
		{
			GameMenuManager->OpenMenu(PreviousMenuClass);
		}
	}
	else
	{
		this->Hide();
	}
}

