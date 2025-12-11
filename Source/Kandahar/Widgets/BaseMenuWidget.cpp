// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenuWidget.h"

#include "Kandahar/Subsystems/GameMenuSubsystem.h"

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
		if (UGameMenuSubsystem* GameMenuSubsystem = GetGameInstance()->GetSubsystem<UGameMenuSubsystem>())
		{
			GameMenuSubsystem->OpenMenu(PreviousMenuClass);
		}
	}
	else
	{
		this->Hide();
	}
}

