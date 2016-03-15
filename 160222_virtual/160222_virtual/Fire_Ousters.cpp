#include "Fire_Ousters.h"




Fire_Ousters::Fire_Ousters(int fireDam, int fireHp, int fireEp, char * job)
	: Ousters("아우스터즈", 2500, 100, 75) ,  _FireDam(fireDam), _FireHp(fireHp) , _FireEp(fireEp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_FireSkill[0] = new Skill(_BaseDam, _BaseDam + fireDam, 30, "플레어");
	_FireSkill[1] = new Skill(_BaseDam + fireDam, _BaseDam + (fireDam * 2), 30, "스피어");
}

Fire_Ousters::~Fire_Ousters()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _FireSkill[i];
}

void Fire_Ousters::attack()
{
	cout << "불정령의 힘으로 ";
}

void Fire_Ousters::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "염력 : " << _Ep << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _FireHp << endl;
	cout << "추가염력 : " << _FireEp << endl;
	cout << "추가데미지 : " << _FireDam << endl;
}
