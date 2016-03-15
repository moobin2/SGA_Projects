#pragma once
#include "Vampire.h"
class DEX_Vampire : public Vampire
{
	int _DexDam;
	int _DexHp;
	char* _JobInfo;
	Skill* _DexSkill[2];
public:
	DEX_Vampire(int dexDam, int dexHp, char* job);
	virtual ~DEX_Vampire();

	virtual void attack();
	virtual void showInfo();
};

