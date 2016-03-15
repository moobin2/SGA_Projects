#include "Water_Ousters.h"





Water_Ousters::Water_Ousters(int waterDam, int waterHp, int waterEp, char * job)
	: Ousters("�ƿ콺����", 2500, 100, 75), _WaterDam(waterDam), _WaterHp(waterHp), _WaterEp(waterEp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_WaterSkill[0] = new Skill(_BaseDam, _BaseDam + waterDam, 30, "�н�");
	_WaterSkill[1] = new Skill(_BaseDam + waterDam, _BaseDam + (waterDam * 2), 30, "����");
}

Water_Ousters::~Water_Ousters()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _WaterSkill[i];

}

void Water_Ousters::attack()
{
	cout << "�������� ������";
}

void Water_Ousters::showInfo()
{
	cout << "���� : " << _raceInfo << endl;
	cout << "���� : " << _JobInfo << endl;
	cout << "ü�� : " << _Hp << endl;
	cout << "���� : " << _Ep << endl;
	cout << "�⺻������ : " << _BaseDam << endl;
	cout << " = = << �������ʽ� > = =" << endl;
	cout << "�߰�ü�� : " << _WaterHp << endl;
	cout << "�߰����� : " << _WaterEp << endl;
	cout << "�߰������� : " << _WaterDam << endl;
}
