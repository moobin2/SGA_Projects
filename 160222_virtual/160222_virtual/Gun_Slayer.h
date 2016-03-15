#pragma once
#include "Slayer.h"
class Gun_Slayer : public Slayer
{
	int _GunDam;
	int _GunHp;
	int _GunMp;
	char* _JobInfo;
	Skill* _GunSkill[2];
public:
	Gun_Slayer(int gunDam, int gunHp, int gunMp, char* job);
	virtual ~Gun_Slayer();

	virtual void attack();
	virtual void showInfo();
};

