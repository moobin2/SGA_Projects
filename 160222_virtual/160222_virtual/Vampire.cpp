#include "Vampire.h"



Vampire::Vampire(char* raceInfo, int hp, int baseDam) : race(raceInfo, hp), _BaseDam(baseDam)
{
	_baseSkill = new Skill(baseDam, baseDam, -20, "����");
}


Vampire::~Vampire()
{
	delete _baseSkill;
}

void Vampire::attack()
{
	cout << "�⺻���� : ������" << endl;
}

void Vampire::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
}
