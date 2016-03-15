#include "Ousters.h"





Ousters::Ousters(char * raceInfo, int hp, int ep, int baseDam) : race(raceInfo, hp), _Ep(ep), _BaseDam(baseDam)
{
	_baseSkill = new Skill(baseDam, baseDam, -20, "����");
}

Ousters::~Ousters()
{
	delete _baseSkill;
}

void Ousters::attack()
{
	cout << "������ ������ ";
}

void Ousters::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Ep << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
}
