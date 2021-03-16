// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterPawn.h"
#include "Math/UnrealMathUtility.h"

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
	
	StaticMesh = FindComponentByClass<UStaticMeshComponent>();
	StaticMesh->OnComponentHit.AddDynamic(this, &AMonsterPawn::OnHit);
}

// Called every frame
void AMonsterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateRandom();
	MoveForward();
}

// Called to bind functionality to input
void AMonsterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMonsterPawn::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Log, TEXT("Hit Actor Name : %s"), *OtherActor->GetName());
}

void AMonsterPawn::MoveForward()
{
	auto Forward = GetActorForwardVector();
	SetActorLocation(GetActorLocation() + Forward * m_Velocity);
}

void AMonsterPawn::RotateRandom()
{
	TArray<FHitResult> Results;
	auto Rotation = GetActorRotation();
	float RandomYaw = FMath::RandRange(-2.f, 2.f);
	float RandomPitch = FMath::RandRange(-1.f, 1.f);

	SetActorRotation(Rotation + FRotator(RandomPitch, RandomYaw, 0.f));
}

void AMonsterPawn::CheckDestroy()
{
	TArray<FHitResult> Results;
	auto World = GetWorld();
	auto Rotation = GetActorRotation();
	auto Location = GetActorLocation();
}

bool AMonsterPawn::DoSweep(const UWorld* World, FVector StartLocation, FVector EndLocation, FRotator Rot, TArray<struct FHitResult> &OutHits)
{
	if (!IsValid(StaticMesh)) return false;

	FComponentQueryParams CQP = FComponentQueryParams();
	CQP.AddIgnoredComponent(StaticMesh);
	CQP.bFindInitialOverlaps = true;
	CQP.bTraceComplex = false;

	World->ComponentSweepMulti(
		OutHits,			//results
		StaticMesh,	//Component to sweep
		StartLocation,			//start location
		EndLocation,			//end location
		Rot,
		CQP					//Parameters
	);
	return false;
}

