// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "MonsterPawn.h"
#include "Runtime/Engine/Public/EngineUtils.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MouseRightButton", EInputEvent::IE_Pressed, this, &APlayerPawn::MouseRightButtonPressed);
	PlayerInputComponent->BindAction("MouseRightButton", EInputEvent::IE_Released, this, &APlayerPawn::MouseRightButtonReleased);
	PlayerInputComponent->BindAction("Shot", EInputEvent::IE_Released, this, &APlayerPawn::Shot);
	PlayerInputComponent->BindAxis("LeftRight", this, &APlayerPawn::LeftRight);
	PlayerInputComponent->BindAxis("UpDown", this, &APlayerPawn::UpDown);
	PlayerInputComponent->BindAxis("ForwardBackward", this, &APlayerPawn::ForwardBackward);
	PlayerInputComponent->BindAxis("RotateYaw", this, &APlayerPawn::RotateYaw);
	PlayerInputComponent->BindAxis("RotatePitch", this, &APlayerPawn::RotatePitch);
}

void APlayerPawn::LeftRight(float AxisValue)
{
	SetActorLocation(GetActorLocation() + GetActorRightVector() * AxisValue * Speed);
}

void APlayerPawn::UpDown(float AxisValue)
{
	SetActorLocation(GetActorLocation() + GetActorUpVector() * AxisValue * Speed);
}

void APlayerPawn::ForwardBackward(float AxisValue)
{
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * AxisValue * Speed);
}

void APlayerPawn::RotateYaw(float AxisValue)
{
	if(MouseRightIsPressed)
		SetActorRotation(GetActorRotation() + FRotator(0.f, AxisValue, 0.f));
}

void APlayerPawn::RotatePitch(float AxisValue)
{
	if (MouseRightIsPressed)
		SetActorRotation(GetActorRotation() + FRotator(AxisValue, 0.f, 0.f));
}

void APlayerPawn::MouseRightButtonPressed()
{
	MouseRightIsPressed = true;
}

void APlayerPawn::MouseRightButtonReleased()
{
	MouseRightIsPressed = false;
}

void APlayerPawn::Shot()
{
	AMonsterPawn* TargetMonster = nullptr;
	for (const auto& entity : TActorRange<AMonsterPawn>(GetWorld()))
	{
		TargetMonster = entity;
	}
	if (TargetMonster)
	{
		auto Missile = GetWorld()->SpawnActor<AMissileActor>(MissileActor, GetActorLocation(), GetActorRotation());
		Missile->SetTarget(TargetMonster);
	}
}

