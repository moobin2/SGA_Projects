#include "Hero.h"


Hero::Hero(int hp, int mp, char* name, int kinds) : _HP(hp) , _MP(mp)
{
	_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);
	if (kinds == player)
	{
		_skill[0] = new Skill(100, 200, "평타 (100, 200)");
		_skill[1] = new Skill(150, 200, "염화 (150, 200)");
		_skill[2] = new Skill(200, 400, "불새 (200, 400)");
	}
	else
	{
		_skill[0] = new Skill(100, 200, "평타 (100, 200)");
		_skill[1] = new Skill(150, 200, "돌격 (150, 200)");
		_skill[2] = new Skill(200, 400, "강타 (200, 400)");
	}
}

Hero::~Hero()
{
	delete []_name;
	for (int i = 0; i < 3; i++)
	{
		delete _skill[i];
	}
}

int Hero::skilldamage(int skillnum)
{
	int damage = _skill[skillnum]->SkillDamage();

	return damage;
}

int Hero::getHP(void)
{
	return _HP;
}

int Hero::getMP(void)
{
	return _MP;
}

char* Hero::getSkillname(int skillnum)
{
	return _skill[skillnum]->getSkillname();
}

char * Hero::getname(void)
{
	return _name;
}

void Hero::decreaseHP(int dem)
{
	if (_HP > dem) _HP -= dem;
	else _HP = 0;
}