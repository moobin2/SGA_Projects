#pragma once
#include "Ousters.h"
class Earth_Ousters : public Ousters
{
	int _EarthDam;
	int _EarthHp;
	int _EarthEp;
	char* _JobInfo;
	Skill* _EarthSkill[2];
public:
	Earth_Ousters(int earthDam, int earthHp, int earthEp, char * job);
	virtual ~Earth_Ousters();

	virtual void attack();
	virtual void showInfo();
};

