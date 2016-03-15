#include "INT_Vampire.h"



INT_Vampire::INT_Vampire(int intDam, int intHp, char* job)
	: Vampire("�����̾�", 3000, 50), _IntDam(intDam), _IntHp(intHp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_IntSkill[0] = new Skill(_BaseDam, _BaseDam + intDam, 30, "����");
	_IntSkill[1] = new Skill(_BaseDam + intDam, _BaseDam + (intDam * 2), 30, "����");
}

INT_Vampire::~INT_Vampire()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _IntSkill[i];
}

void INT_Vampire::attack()
{
	cout << "���������� ";
}

void INT_Vampire::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _IntHp << endl;
	cout << "�߰������� : " << _IntDam << endl;
}
