#include "DEX_Vampire.h"



DEX_Vampire::DEX_Vampire(int dexDam, int dexHp, char * job)
	: Vampire("뱀파이어", 3000, 50) , _DexDam(dexDam) , _DexHp(dexHp)
{
	_JobInfo = new char[strlen(job) + 1];
	strcpy_s(_JobInfo, strlen(job) + 1, job);
	_DexSkill[0] = new Skill(_BaseDam, _BaseDam + dexDam, 30, "베놈");
	_DexSkill[1] = new Skill(_BaseDam + dexDam, _BaseDam + (dexDam * 2), 30, "팬텀");
}

DEX_Vampire::~DEX_Vampire()
{
	delete[]_JobInfo;
	for (int i = 0; i < 2; i++) delete _DexSkill[i];
}

void DEX_Vampire::attack()
{
	cout << "민첩하게 ";
}

void DEX_Vampire::showInfo()
{
	cout << "종족 : " << _raceInfo << endl;
	cout << "직업 : " << _JobInfo << endl;
	cout << "체력 : " << _Hp << endl;
	cout << "기본데미지 : " << _BaseDam << endl;
	cout << " = = << 직업보너스 > = =" << endl;
	cout << "추가체력 : " << _DexHp << endl;
	cout << "추가데미지 : " << _DexDam << endl;
}
