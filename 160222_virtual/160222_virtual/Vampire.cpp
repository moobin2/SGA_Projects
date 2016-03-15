#include "Vampire.h"



Vampire::Vampire(char* raceInfo, int hp, int baseDam) : race(raceInfo, hp), _BaseDam(baseDam)
{
	_baseSkill = new Skill(baseDam, baseDam, -20, "ÈíÇ÷");
}


Vampire::~Vampire()
{
	delete _baseSkill;
}

void Vampire::attack()
{
	cout << "±âº»°ø°Ý : ÇÓÄû±â" << endl;
}

void Vampire::showInfo()
{
	cout << "Á÷¾÷ : " << _raceInfo << endl;
	cout << "Ã¼·Â : " << _Hp << endl;
	cout << "±âº»µ¥¹ÌÁö : " << _BaseDam << endl;
}
