#include "STR_Vampire.h"



STR_Vampire::STR_Vampire(int strDam, int strHp, char * job)
	: Vampire("뱀파이어", 3000, 50), _StrDam(strDam), _StrHp(strHp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_StrSkill[0] = new Skill(_BaseDam, _BaseDam + strDam, 30, "크로우");
	_StrSkill[1] = new Skill(_BaseDam + strDam, _BaseDam + (strDam * 2), 30, "제니스");
}

STR_Vampire::~STR_Vampire()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _StrSkill[i];
}

void STR_Vampire::attack()
{
	cout << "강력하게 ";
}

void STR_Vampire::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _StrHp << endl;
	cout << "추가데미지 : " << _StrDam << endl;
}
