#include "Slayer.h"



Slayer::Slayer(char* raceInfo, int hp, int mp, int baseDam) : race(raceInfo, hp) , _Mp(mp) , _BaseDam(baseDam)
{
	_baseSkill = new Skill(baseDam, baseDam, -20, "맨손공격");
}


Slayer::~Slayer()
{
	delete _baseSkill;
}

void Slayer::attack()
{
	cout << "기본공격 : 맨손주먹" << endl;
}

void Slayer::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "마력 : " << _Mp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
}
