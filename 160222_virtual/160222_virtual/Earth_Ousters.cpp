#include "Earth_Ousters.h"





Earth_Ousters::Earth_Ousters(int earthDam, int earthHp, int earthEp, char * job)
	: Ousters("아우스터즈", 2500, 100, 75), _EarthDam(earthDam), _EarthHp(earthHp), _EarthEp(earthEp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_EarthSkill[0] = new Skill(_BaseDam, _BaseDam + earthDam, 30, "티스");
	_EarthSkill[1] = new Skill(_BaseDam + earthDam, _BaseDam + (earthDam * 2), 30, "노옴");
}

Earth_Ousters::~Earth_Ousters()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _EarthSkill[i];
}

void Earth_Ousters::attack()
{
	cout << "대지정령의 힘으로 ";
}

void Earth_Ousters::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "염력 : " << _Ep << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _EarthHp << endl;
	cout << "추가염력 : " << _EarthEp << endl;
	cout << "추가데미지 : " << _EarthDam << endl;
}
