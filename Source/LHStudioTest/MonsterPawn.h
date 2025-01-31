// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UObject/NoExportTypes.h"
#include "MonsterPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegate_NoParam);

UCLASS()
class LHSTUDIOTEST_API AMonsterPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMonsterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
// 	UFUNCTION()
// 	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	void MoveForward();
	void RotateRandom();
	void CheckDestroy();
	
private:
	bool DoSweep(const UWorld* World, FVector StartLocation, FVector EndLocation, FRotator Rot, TArray<struct FHitResult> &OutHits);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
 	float m_Velocity = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	UStaticMeshComponent* StaticMesh;

	FDelegate_NoParam DieEvent;
private:
	float InternalTickTime = 0.f;
};
