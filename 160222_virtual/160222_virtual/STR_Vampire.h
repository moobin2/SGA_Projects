#pragma once
#include "Vampire.h"
class STR_Vampire :
	public Vampire
{
	int _StrDam;
	int _StrHp;
	char* _JobInfo;
	Skill* _StrSkill[2];
public:
	STR_Vampire(int strDam, int strHp, char* job);
	virtual ~STR_Vampire();

	virtual void attack();
	virtual void showInfo();
};

