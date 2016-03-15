#include "Gun_Slayer.h"



Gun_Slayer::Gun_Slayer(int gunDam, int gunHp, int gunMp, char* job)
	: Slayer("슬레이어", 2000, 500, 100), _GunDam(gunDam), _GunHp(gunHp), _GunMp(gunMp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_GunSkill[0] = new Skill(_BaseDam, _BaseDam + gunDam, 30, "멀티샷");
	_GunSkill[1] = new Skill(_BaseDam + gunDam, _BaseDam + (gunDam * 2), 30, "스나이핑");
}


Gun_Slayer::~Gun_Slayer()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _GunSkill[i];
}

void Gun_Slayer::attack()
{
	cout << "기본공격 : 총탄발사" << endl;
}

void Gun_Slayer::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "마력 : " << _Mp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _GunHp << endl;
	cout << "추가마력 : " << _GunMp << endl;
	cout << "추가데미지 : " << _GunDam << endl;
}
