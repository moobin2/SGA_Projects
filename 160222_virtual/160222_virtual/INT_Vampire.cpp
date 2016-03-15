#include "INT_Vampire.h"



INT_Vampire::INT_Vampire(int intDam, int intHp, char* job)
	: Vampire("뱀파이어", 3000, 50), _IntDam(intDam), _IntHp(intHp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_IntSkill[0] = new Skill(_BaseDam, _BaseDam + intDam, 30, "누스");
	_IntSkill[1] = new Skill(_BaseDam + intDam, _BaseDam + (intDam * 2), 30, "데쓰");
}

INT_Vampire::~INT_Vampire()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _IntSkill[i];
}

void INT_Vampire::attack()
{
	cout << "지능적으로 ";
}

void INT_Vampire::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _IntHp << endl;
	cout << "추가데미지 : " << _IntDam << endl;
}
