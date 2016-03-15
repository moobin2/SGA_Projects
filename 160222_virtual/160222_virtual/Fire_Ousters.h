#pragma once
#include "Ousters.h"
class Fire_Ousters : public Ousters
{
	int _FireDam;
	int _FireHp;
	int _FireEp;
	char* _JobInfo;
	Skill* _FireSkill[2];
public:
	Fire_Ousters(int fireDam, int fireHp, int fireEp, char * job);
	virtual ~Fire_Ousters();

	virtual void attack();
	virtual void showInfo();
};

