#pragma once
#include "Slayer.h"
class Heal_Slayer : public Slayer
{
	int _HealDam;
	int _HealHp;
	int _HealMp;
	char* _JobInfo;
	Skill* _HealSkill[2];
public:
	Heal_Slayer(int healDam, int healHp, int healMp, char* job);
	virtual ~Heal_Slayer();

	virtual void attack();
	virtual void showInfo();
};

