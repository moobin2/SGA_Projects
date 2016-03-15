#include "Heal_Slayer.h"



Heal_Slayer::Heal_Slayer(int healDam, int healHp, int healMp, char* job)
	: Slayer("슬레이어", 2000, 500, 100), _HealDam(healDam), _HealHp(healHp), _HealMp(healMp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_HealSkill[0] = new Skill(_BaseDam, _BaseDam + healDam, 30, "운즈");
	_HealSkill[1] = new Skill(_BaseDam + healDam, _BaseDam + (healDam * 2), 30, "비거드롭");
}


Heal_Slayer::~Heal_Slayer()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _HealSkill[i];
}

void Heal_Slayer::attack()
{
	cout << "기본공격 : 십자가어택" << endl;
}

void Heal_Slayer::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "마력 : " << _Mp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _HealHp << endl;
	cout << "추가마력 : " << _HealMp << endl;
	cout << "추가데미지 : " << _HealDam << endl;
}
