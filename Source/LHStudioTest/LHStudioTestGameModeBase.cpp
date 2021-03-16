// Copyright Epic Games, Inc. All Rights Reserved.


#include "LHStudioTestGameModeBase.h"
#include "SkillBase.h"
#include "LinkedList.h"

void ALHStudioTestGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SkillBase<FSkill> SB;
	LinkedList<int32> List;
	FSkill skill1, skill2, skill3;
 	SB.AddRandom(15, skill1);
 	SB.AddRandom(25, skill2);
 	SB.AddRandom(10, skill3);

	SB.GetRandom(skill3);
}
