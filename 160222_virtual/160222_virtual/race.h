#pragma once
#include "Skill.h"
#include <iostream>

using namespace std;

class race
{
protected:
	int _Hp;
	char* _raceInfo;
public:
	race(char* raceInfo, int hp);
	virtual ~race();

	virtual void attack() = 0;
	virtual void showInfo() = 0;
};

