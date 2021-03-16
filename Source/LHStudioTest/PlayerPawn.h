// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MissileActor.h"
#include "PlayerPawn.generated.h"

UCLASS()
class LHSTUDIOTEST_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION()
	void LeftRight(float AxisValue);
	UFUNCTION()
	void UpDown(float AxisValue);
	UFUNCTION()
	void ForwardBackward(float AxisValue);
	UFUNCTION()
	void RotateYaw(float AxisValue);
	UFUNCTION()
	void RotatePitch(float AxisValue);
	UFUNCTION()
	void MouseRightButtonPressed();
	UFUNCTION()
	void MouseRightButtonReleased();
	UFUNCTION()
	void Shot();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	TSubclassOf<AMissileActor> MissileActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float Speed = 0.f;
	bool MouseRightIsPressed = false;
};
