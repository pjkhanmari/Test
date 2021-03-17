// Copyright Epic Games, Inc. All Rights Reserved.


#include "LHStudioTestGameModeBase.h"
#include "SkillBase.h"
#include "LinkedList.h"

void ALHStudioTestGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SkillBase<FSkill> SB;
	LinkedList<FName> List;
	List.Add(TEXT("I"));
	List.Add(TEXT("Am"));
	List.Add(TEXT("Data!!"));
	List.Delete(1);
	UE_LOG(LogTemp, Log, TEXT("List Size : %d"), List.Num());
	List.Print();
	List.Replace(0, TEXT("Other"));
	UE_LOG(LogTemp, Log, TEXT("FInd Index : %d"), List.FindIndex(TEXT("Other")));
	FSkill skill1, skill2, skill3, skill4;
 	SB.AddRandom(15, skill1);
 	SB.AddRandom(25, skill2);
 	SB.AddRandom(10, skill3);
 	SB.AddRandom(50, skill4);

	SB.GetRandom(skill4);
}

void ALHStudioTestGameModeBase::EndPlay(EEndPlayReason::Type reason)
{
	Super::EndPlay(reason);
}
