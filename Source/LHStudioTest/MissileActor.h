// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissileActor.generated.h"

UCLASS()
class LHSTUDIOTEST_API AMissileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward();
	void RotateToTarget(FVector TargetPos);
	void RotateYaw(FVector TargetPos);
	void RotatePitch(FVector TargetPos);

	void SetTarget(AActor* Target);
	UFUNCTION()
	void StartSuicide();
private:
	void Suicide();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float m_Velocity = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float SuicideDelay = 0.f;

private:
	AActor* TargetActor = nullptr;
	bool bAlreadyStartSuicide = false;
};
