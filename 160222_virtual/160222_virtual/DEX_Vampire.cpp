#include "DEX_Vampire.h"



DEX_Vampire::DEX_Vampire(int dexDam, int dexHp, char * job)
	: Vampire("�����̾�", 3000, 50) , _DexDam(dexDam) , _DexHp(dexHp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_DexSkill[0] = new Skill(_BaseDam, _BaseDam + dexDam, 30, "����");
	_DexSkill[1] = new Skill(_BaseDam + dexDam, _BaseDam + (dexDam * 2), 30, "����");
}

DEX_Vampire::~DEX_Vampire()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _DexSkill[i];
}

void DEX_Vampire::attack()
{
	cout << "��ø�ϰ� ";
}

void DEX_Vampire::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _DexHp << endl;
	cout << "�߰������� : " << _DexDam << endl;
}
