// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<typename T>
class SkillBase
{
public:
	SkillBase() {};
	~SkillBase() {};

public:
	void AddRandom(int32 Prob, const T& Data)
	{
		SkillContainer.Emplace(Data, Prob);
	}

	bool GetRandom(T& Data) const
	{
		int32 TotalProb = 0, CurrentProb = 0, TempProb = 0;
		for (auto Skill : SkillContainer)
		{
			TempProb = Skill.Value;
			TotalProb += TempProb;
			if (Data == Skill.Key)
				CurrentProb = TempProb;
		}
		auto Pick = FMath::RandRange(0, TotalProb);

		UE_LOG(LogTemp, Log, TEXT("Pick Proba : %d, CutLine Num : %d, Total Proba : %d"), Pick, CurrentProb, TotalProb);
		if (Pick < TempProb)
		{
			UE_LOG(LogTemp, Log, TEXT("Skill Successes"));
			return true;
		}

		UE_LOG(LogTemp, Log, TEXT("Skill Failed"));
		return false;
	}

private:
	TMap<T, int32> SkillContainer;
};
