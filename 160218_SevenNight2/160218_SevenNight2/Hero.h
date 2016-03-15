#pragma once
#include "Skill.h"


class Hero
{
	char* _name;
	int _HP;
	int _MP;
	Skill* _skill[3];
public:
	Hero(int hp, int mp, char* name, int kinds);
	~Hero();
	int skilldamage(int skillnum);
	int getHP(void);
	int getMP(void);
	char* getname(void);
	char* getSkillname(int skillnum);
	void decreaseHP(int dem);
};