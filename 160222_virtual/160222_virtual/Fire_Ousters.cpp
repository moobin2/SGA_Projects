#include "Fire_Ousters.h"




Fire_Ousters::Fire_Ousters(int fireDam, int fireHp, int fireEp, char * job)
	: Ousters("�ƿ콺����", 2500, 100, 75) ,  _FireDam(fireDam), _FireHp(fireHp) , _FireEp(fireEp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_FireSkill[0] = new Skill(_BaseDam, _BaseDam + fireDam, 30, "�÷���");
	_FireSkill[1] = new Skill(_BaseDam + fireDam, _BaseDam + (fireDam * 2), 30, "���Ǿ�");
}

Fire_Ousters::~Fire_Ousters()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _FireSkill[i];
}

void Fire_Ousters::attack()
{
	cout << "�������� ������ ";
}

void Fire_Ousters::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Ep << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _FireHp << endl;
	cout << "�߰����� : " << _FireEp << endl;
	cout << "�߰������� : " << _FireDam << endl;
}
