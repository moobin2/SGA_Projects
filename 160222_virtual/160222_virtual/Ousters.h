#pragma once
#include "race.h"
class Ousters : public race
{
protected:
	int _Ep;
	int _BaseDam;
	Skill* _baseSkill;
public:
	Ousters(char* raceInfo, int hp, int ep, int baseDam);
	virtual ~Ousters();

	virtual void attack();
	virtual void showInfo();
};

