// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LHStudioTestGameModeBase.generated.h"

/**
 * 
 */
USTRUCT()
struct FSkill
{
	GENERATED_USTRUCT_BODY();
public:
	uint32 ID;
	int32* Hash;
	FSkill() 
	{ 
		Hash = new int32;
		ID = PointerHash(Hash);
	}
	~FSkill() 
	{
		//delete Hash;
	}
	friend bool operator == (const FSkill& first, const FSkill& second)
	{
		return (first.ID == second.ID);
	}
	friend uint32 GetTypeHash(const FSkill& Other)
	{
		return GetTypeHash(Other.ID);
	}
};

UCLASS()
class LHSTUDIOTEST_API ALHStudioTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type reason) override;
	
};
