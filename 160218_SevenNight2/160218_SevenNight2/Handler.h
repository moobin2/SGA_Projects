#pragma once
#include "Hero.h"
#include "Skill.h"
#include <iomanip>

class Handler
{
	Hero* _player[2];
public:
	void MakePlayer(void);
	void MakeAttack(int character);
	void showPlayerInfo(void);
	void showSkillname(int character);
	bool HPcheck(void);

	Handler();
	~Handler();
};

