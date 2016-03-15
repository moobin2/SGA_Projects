#pragma once
#include "Slayer.h"
class Blade_Slayer : public Slayer
{
	int _BladeDam;
	int _BladeHp;
	int _BladeMp;
	char* _JobInfo;
	Skill* _BladeSkill[2];
public:
	Blade_Slayer(int bladeDam, int bladeHp, int bladeMp, char* job);
	virtual ~Blade_Slayer();

	virtual void attack();
	virtual void showInfo();
};

