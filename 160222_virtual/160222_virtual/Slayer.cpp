#include "Slayer.h"



Slayer::Slayer(char* raceInfo, int hp, int mp, int baseDam) : race(raceInfo, hp) , _Mp(mp) , _BaseDam(baseDam)
{
	_baseSkill = new Skill(baseDam, baseDam, -20, "�Ǽհ���");
}


Slayer::~Slayer()
{
	delete _baseSkill;
}

void Slayer::attack()
{
	cout << "�⺻���� : �Ǽ��ָ�" << endl;
}

void Slayer::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Mp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
}
