#include "Ousters.h"





Ousters::Ousters(char * raceInfo, int hp, int ep, int baseDam) : race(raceInfo, hp), _Ep(ep), _BaseDam(baseDam)
{
	_baseSkill = new Skill(baseDam, baseDam, -20, "영흡");
}

Ousters::~Ousters()
{
	delete _baseSkill;
}

void Ousters::attack()
{
	cout << "정령의 힘으로 ";
}

void Ousters::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "염력 : " << _Ep << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
}
