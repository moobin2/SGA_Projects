#include "Skill.h"

Skill::Skill(int min, int max, int consumMp, char* skName) : _min(min), _max(max) , _consumMp(_consumMp)
{
	_skillName = new char[strlen(skName) + 1];
	strcpy_s(_skillName, strlen(skName) + 1, skName);
}

Skill::~Skill()
{
	delete[]_skillName;
}

int Skill::SkillDamage(void)
{
	srand((size_t)time(NULL));
	int damage = _min + rand() % (_max - _min);
	return damage;
}

char* Skill::getSkillname(void)
{
	return _skillName;
}

int Skill::getSkillmin(void)
{
	return _min;
}

int Skill::getSkillmax(void)
{
	return _max;
}
