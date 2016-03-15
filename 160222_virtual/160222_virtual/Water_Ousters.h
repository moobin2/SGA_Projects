#pragma once
#include "Ousters.h"
class Water_Ousters : public Ousters
{
	int _WaterDam;
	int _WaterHp;
	int _WaterEp;
	char* _JobInfo;
	Skill* _WaterSkill[2];
public:
	Water_Ousters(int waterDam, int waterHp, int waterEp, char * job);
	virtual ~Water_Ousters();

	virtual void attack();
	virtual void showInfo();
};

