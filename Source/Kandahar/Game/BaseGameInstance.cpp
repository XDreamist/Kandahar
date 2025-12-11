// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameInstance.h"

#include "Kandahar/Subsystems/GameMenuSubsystem.h"

#include "../Structs/MenuDataRegistry.h"

void UBaseGameInstance::Init()
{
	Super::Init();
	
	if (UGameMenuSubsystem* GameMenuSubsystem = GetSubsystem<UGameMenuSubsystem>())
	{
		GameMenuSubsystem->SetMenuRegistry(MenuRegistry->MenuData);
	}
}

void UBaseGameInstance::Shutdown()
{
	Super::Shutdown();
}
