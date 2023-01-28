// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void HandleDestruction();
	APlayerController* GetPlayerController() {return PlayerController;};

	bool bAlive = true;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere,Category="Component Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere,Category="Component Camera")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere,Category="Movement")
	float Speed= 400.f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.f;
	float GettingDeltaTime();
	void Move(float Value);
	void Turn(float Value);
	
	APlayerController* PlayerController;
	public:
	virtual void Tick(float DeltaTime) override;
};
