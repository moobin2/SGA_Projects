#include "Blade_Slayer.h"


Blade_Slayer::Blade_Slayer(int bladeDam, int bladeHp, int bladeMp, char* job)
	: Slayer("�����̾�", 2000, 500, 100) , _BladeDam(bladeDam), _BladeHp(bladeHp), _BladeMp(bladeMp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_BladeSkill[0] = new Skill(_BaseDam, _BaseDam + bladeDam, 30, "���޽�");
	_BladeSkill[1] = new Skill(_BaseDam + bladeDam, _BaseDam + (bladeDam*2), 30, "Ÿ��Ǭ");
}

Blade_Slayer::~Blade_Slayer()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _BladeSkill[i];
}

void Blade_Slayer::attack()
{
	cout << "�⺻���� : Ⱦ����" << endl;
}

void Blade_Slayer::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Mp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _BladeHp << endl;
	cout << "�߰����� : " << _BladeMp << endl;
	cout << "�߰������� : " << _BaseDam << endl;
}
