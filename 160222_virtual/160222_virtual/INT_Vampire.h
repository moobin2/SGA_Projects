#pragma once
#include "Vampire.h"
class INT_Vampire : public Vampire
{
	int _IntDam;
	int _IntHp;
	char* _JobInfo;
	Skill* _IntSkill[2];
public:
	INT_Vampire(int intDam, int intHp, char* job);
	virtual ~INT_Vampire();

	virtual void attack();
	virtual void showInfo();
};

