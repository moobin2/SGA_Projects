#include "STR_Vampire.h"



STR_Vampire::STR_Vampire(int strDam, int strHp, char * job)
	: Vampire("�����̾�", 3000, 50), _StrDam(strDam), _StrHp(strHp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_StrSkill[0] = new Skill(_BaseDam, _BaseDam + strDam, 30, "ũ�ο�");
	_StrSkill[1] = new Skill(_BaseDam + strDam, _BaseDam + (strDam * 2), 30, "���Ͻ�");
}

STR_Vampire::~STR_Vampire()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _StrSkill[i];
}

void STR_Vampire::attack()
{
	cout << "�����ϰ� ";
}

void STR_Vampire::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _StrHp << endl;
	cout << "�߰������� : " << _StrDam << endl;
}
