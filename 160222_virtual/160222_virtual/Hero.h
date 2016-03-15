#pragma once
#include "race.h"
#include "Blade_Slayer.h"
#include "Gun_Slayer.h"
#include "Heal_Slayer.h"
#include "STR_Vampire.h"
#include "DEX_Vampire.h"
#include "INT_Vampire.h"
#include "Fire_Ousters.h"
#include "Water_Ousters.h"
#include "Earth_Ousters.h"
#include "Skill.h"

class Hero
{
	race* _MyHero;
	race* _EnemyHero;
public:
	Hero();
	~Hero();

	void makeMyHero(void);
	void showHeroInfo(void);
};

