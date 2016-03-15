#pragma once
#include "race.h"
class Slayer : public race
{
protected:
	int _Mp;
	int _BaseDam;
	Skill* _baseSkill;
public:
	Slayer(char* raceInfo, int hp, int mp, int baseDam);
	virtual ~Slayer();

	virtual void attack();
	virtual void showInfo();
};

