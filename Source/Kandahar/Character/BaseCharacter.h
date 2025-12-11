// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class KANDAHAR_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	
	// Input
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpAction;
	
	// Input Functions
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
