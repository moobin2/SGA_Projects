#include "Water_Ousters.h"





Water_Ousters::Water_Ousters(int waterDam, int waterHp, int waterEp, char * job)
	: Ousters("아우스터즈", 2500, 100, 75), _WaterDam(waterDam), _WaterHp(waterHp), _WaterEp(waterEp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_WaterSkill[0] = new Skill(_BaseDam, _BaseDam + waterDam, 30, "닉시");
	_WaterSkill[1] = new Skill(_BaseDam + waterDam, _BaseDam + (waterDam * 2), 30, "스톰");
}

Water_Ousters::~Water_Ousters()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _WaterSkill[i];

}

void Water_Ousters::attack()
{
	cout << "물정령의 힘으로";
}

void Water_Ousters::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "염력 : " << _Ep << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _WaterHp << endl;
	cout << "추가염력 : " << _WaterEp << endl;
	cout << "추가데미지 : " << _WaterDam << endl;
}
