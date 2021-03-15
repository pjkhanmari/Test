// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterPawn.h"
#include "Math/UnrealMathUtility.h"

#define LITTLEGAP FVector(0.f, 0.f, 100.f)

// Sets default values
AMonsterPawn::AMonsterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMonsterPawn::MoveForward()
{
	auto Forward = GetActorForwardVector();
	SetActorLocation(GetActorLocation() + Forward * m_Velocity);
}

void AMonsterPawn::RotateRandom()
{
	TArray<FHitResult> Results;
	float RandomYaw = FMath::RandRange(-1.f, 1.f);
	auto World = GetWorld();
	auto Rotation = GetActorRotation();
	auto Location = GetActorLocation();
	if (DoSweep(World, Location, Location - LITTLEGAP, Rotation, Results))
	{
	}
}

void AMonsterPawn::CheckDestroy()
{

}

bool AMonsterPawn::DoSweep(const UWorld* World, FVector StartLocation, FVector EndLocation, FRotator Rot, TArray<struct FHitResult> &OutHits)
{
// 	if (!IsValid(UpdateedPrimitive)) return false;
// 
// 	FComponentQueryParams CQP = FComponentQueryParams();
// 	CQP.AddIgnoredComponent(UpdatedPrimitive);
// 	CQP.bFindInitialOverlaps = true;
// 	CQP.bTraceComplex = false;
// 
// 	World->ComponentSweepMulti(
// 		OutHits,			//results
// 		UpdatedPrimitive,	//Component to sweep
// 		StartLocation,			//start location
// 		EndLocation,			//end location
// 		Rot,
// 		CQP					//Parameters
// 	);
	return false;
}

