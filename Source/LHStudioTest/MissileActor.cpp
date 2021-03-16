// Fill out your copyright notice in the Description page of Project Settings.


#include "MissileActor.h"
#include "MonsterPawn.h"

// Sets default values
AMissileActor::AMissileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMissileActor::BeginPlay()
{
	Super::BeginPlay();
	bAlreadyStartSuicide = false;
}

// Called every frame
void AMissileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveForward();

	if (bAlreadyStartSuicide)
		return;
	if (TargetActor)
		RotateToTarget(TargetActor->GetActorLocation());
	else
 		StartSuicide();
}

void AMissileActor::MoveForward()
{
	auto Forward = GetActorForwardVector();
	SetActorLocation(GetActorLocation() + Forward * m_Velocity);
}

void AMissileActor::RotateToTarget(FVector TargetPos)
{
	RotatePitch(TargetPos);
	RotateYaw(TargetPos);
}

void AMissileActor::RotateYaw(FVector TargetPos)
{
	auto Location = GetActorLocation();
	auto Rotation = GetActorRotation();
	auto TargetVector = TargetPos - Location;
	float Degree = FMath::RadiansToDegrees(FMath::Atan2(TargetVector.Y, TargetVector.X));
	SetActorRotation(FRotator(Rotation.Pitch, Degree, Rotation.Roll));
}

void AMissileActor::RotatePitch(FVector TargetPos)
{
	auto Location = GetActorLocation();
	auto Rotation = GetActorRotation();
	auto HeightDis = TargetPos.Z - Location.Z;
	auto WidthDis = (TargetPos - Location).Size2D();
	float Degree = FMath::RadiansToDegrees(FMath::Atan2(HeightDis, WidthDis));
	SetActorRotation(FRotator(Degree, Rotation.Yaw, Rotation.Roll));
}

void AMissileActor::StartSuicide()
{
	FTimerHandle Handler;
	GetWorld()->GetTimerManager().SetTimer(Handler, this, &AMissileActor::Suicide, 0.f, false, SuicideDelay);
	bAlreadyStartSuicide = true;
}

void AMissileActor::Suicide()
{
	Destroy();
}

