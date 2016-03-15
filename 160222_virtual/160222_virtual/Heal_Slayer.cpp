#include "Heal_Slayer.h"



Heal_Slayer::Heal_Slayer(int healDam, int healHp, int healMp, char* job)
	: Slayer("�����̾�", 2000, 500, 100), _HealDam(healDam), _HealHp(healHp), _HealMp(healMp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_HealSkill[0] = new Skill(_BaseDam, _BaseDam + healDam, 30, "����");
	_HealSkill[1] = new Skill(_BaseDam + healDam, _BaseDam + (healDam * 2), 30, "��ŵ��");
}


Heal_Slayer::~Heal_Slayer()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _HealSkill[i];
}

void Heal_Slayer::attack()
{
	cout << "�⺻���� : ���ڰ�����" << endl;
}

void Heal_Slayer::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Mp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _HealHp << endl;
	cout << "�߰����� : " << _HealMp << endl;
	cout << "�߰������� : " << _HealDam << endl;
}
