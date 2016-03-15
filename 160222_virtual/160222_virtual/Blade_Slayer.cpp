#include "Blade_Slayer.h"


Blade_Slayer::Blade_Slayer(int bladeDam, int bladeHp, int bladeMp, char* job)
	: Slayer("슬레이어", 2000, 500, 100) , _BladeDam(bladeDam), _BladeHp(bladeHp), _BladeMp(bladeMp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_BladeSkill[0] = new Skill(_BaseDam, _BaseDam + bladeDam, 30, "스메쉬");
	_BladeSkill[1] = new Skill(_BaseDam + bladeDam, _BaseDam + (bladeDam*2), 30, "타이푼");
}

Blade_Slayer::~Blade_Slayer()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _BladeSkill[i];
}

void Blade_Slayer::attack()
{
	cout << "기본공격 : 횡베기" << endl;
}

void Blade_Slayer::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "마력 : " << _Mp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _BladeHp << endl;
	cout << "추가마력 : " << _BladeMp << endl;
	cout << "추가데미지 : " << _BaseDam << endl;
}
