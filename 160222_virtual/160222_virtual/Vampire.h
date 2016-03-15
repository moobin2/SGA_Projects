#pragma once
#include "race.h"
class Vampire : public race
{
protected:
	int _BaseDam;
	Skill* _baseSkill;
public:
	Vampire(char* raceInfo, int hp, int baseDam);
	virtual ~Vampire();

	virtual void attack();
	virtual void showInfo();
};

