#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

enum Kinds
{
	player,
	computer
};

class Skill
{
	int _min;
	int _max;
	int _consumMp;
	char* _skillName;
public:
	Skill(int min, int max, int consumMp, char* skName);
	~Skill();

	int SkillDamage(void);
	char* getSkillname(void);
	int getSkillmin(void);
	int getSkillmax(void);
};
