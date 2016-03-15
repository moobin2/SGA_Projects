#include "Earth_Ousters.h"





Earth_Ousters::Earth_Ousters(int earthDam, int earthHp, int earthEp, char * job)
	: Ousters("�ƿ콺����", 2500, 100, 75), _EarthDam(earthDam), _EarthHp(earthHp), _EarthEp(earthEp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_EarthSkill[0] = new Skill(_BaseDam, _BaseDam + earthDam, 30, "Ƽ��");
	_EarthSkill[1] = new Skill(_BaseDam + earthDam, _BaseDam + (earthDam * 2), 30, "���");
}

Earth_Ousters::~Earth_Ousters()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _EarthSkill[i];
}

void Earth_Ousters::attack()
{
	cout << "���������� ������ ";
}

void Earth_Ousters::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Ep << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _EarthHp << endl;
	cout << "�߰����� : " << _EarthEp << endl;
	cout << "�߰������� : " << _EarthDam << endl;
}
