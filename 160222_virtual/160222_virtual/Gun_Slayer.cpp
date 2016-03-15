#include "Gun_Slayer.h"



Gun_Slayer::Gun_Slayer(int gunDam, int gunHp, int gunMp, char* job)
	: Slayer("�����̾�", 2000, 500, 100), _GunDam(gunDam), _GunHp(gunHp), _GunMp(gunMp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_GunSkill[0] = new Skill(_BaseDam, _BaseDam + gunDam, 30, "��Ƽ��");
	_GunSkill[1] = new Skill(_BaseDam + gunDam, _BaseDam + (gunDam * 2), 30, "��������");
}


Gun_Slayer::~Gun_Slayer()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _GunSkill[i];
}

void Gun_Slayer::attack()
{
	cout << "�⺻���� : ��ź�߻�" << endl;
}

void Gun_Slayer::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Mp << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _GunHp << endl;
	cout << "�߰����� : " << _GunMp << endl;
	cout << "�߰������� : " << _GunDam << endl;
}
