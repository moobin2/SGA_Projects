#include "Hero.h"



Hero::Hero()
{
	srand((size_t)time(NULL));
	int randNum = rand() % 9;
	switch (randNum)
	{
	case 0:
		_EnemyHero = new Blade_Slayer(100, 500, 100, "도슬");
		break;
	case 1:
		_EnemyHero = new Gun_Slayer(75, 375, 150, "총슬");
		break;
	case 2:
		_EnemyHero = new Heal_Slayer(50, 250, 200, "힐슬");
		break;
	case 3:
		_EnemyHero = new STR_Vampire(100, 400, "힘뱀");
		break;
	case 4:
		_EnemyHero = new DEX_Vampire(150, 250, "덱뱀");
		break;
	case 5:
		_EnemyHero = new INT_Vampire(200, 100, "인뱀");
		break;
	case 6:
		_EnemyHero = new Fire_Ousters(100, 200, 100, "불아");
		break;
	case 7:
		_EnemyHero = new Water_Ousters(50, 400, 200, "물아");
		break;
	case 8:
		_EnemyHero = new Earth_Ousters(75, 300, 150, "대아");
		break;
	}
}

Hero::~Hero()
{
	delete _MyHero;
}

void Hero::makeMyHero(void)
{
	int choice;
	int subChoice;

	cout << endl << "\t\t\t << 종족 >> " << endl << endl;
	cout << "1.  슬레이어  (기본체력 : 2000, 기본마력 : 500, 기본데미지 : 100)" << endl;
	cout << "2.  뱀파이어  (기본체력 : 3000,                 기본데미지 :  50)" << endl;
	cout << "3. 아우스터즈 (기본체력 : 2500, 기본염력 : 100, 기본데미지 :  75)" << endl;
	cout << "선택 : "; cin >> choice;

	cout << endl << "\t\t\t -- 직업 -- " << endl << endl;
	switch (choice)
	{
	case 1:
		cout << "    1. 도슬 (추가데미지 : 100, 추가체력 : 500, 추가마나 : 100)" << endl;
		cout << "    2. 총슬 (추가데미지 :  75, 추가체력 : 375, 추가마나 : 150)" << endl;
		cout << "    3. 힐슬 (추가데미지 :  50, 추가체력 : 250, 추가마나 : 200)" << endl;
		cout << "선택 : "; cin >> subChoice;
		cout << endl;
		if (subChoice == 1)
		{
			_MyHero = new Blade_Slayer(100, 500, 100, "도슬");
			break;
		}
		else if (subChoice == 2)
		{
			_MyHero = new Gun_Slayer(75, 375, 150, "총슬");
			break;
		}
		else if (subChoice == 3)
		{
			_MyHero = new Heal_Slayer(50, 250, 200, "힐슬");
			break;
		}
	case 2:
		cout << "\t   1. 힘뱀 (추가데미지 : 100, 추가체력 : 400)" << endl;
		cout << "\t   2. 덱뱀 (추가데미지 : 150, 추가체력 : 250)" << endl;
		cout << "\t   3. 인뱀 (추가데미지 : 200, 추가체력 : 100)" << endl;
		cout << "선택 : "; cin >> subChoice;
		if (subChoice == 1)
		{
			_MyHero = new STR_Vampire(100, 400, "힘뱀");
			break;
		}
		else if (subChoice == 2)
		{
			_MyHero = new DEX_Vampire(150, 250, "덱뱀");
			break;
		}
		else if (subChoice == 3)
		{
			_MyHero = new INT_Vampire(200, 100, "인뱀");
			break;
		}
	case 3:
		cout << "    1. 불아 (추가데미지 : 100, 추가체력 : 200, 추가염력 : 100)" << endl;
		cout << "    2. 물아 (추가데미지 :  50, 추가체력 : 400, 추가염력 : 200)" << endl;
		cout << "    3. 대아 (추가데미지 :  75, 추가체력 : 300, 추가염력 : 150)" << endl;
		cout << "선택 : "; cin >> subChoice;
		if (subChoice == 1)
		{
			_MyHero = new Fire_Ousters(100, 200, 100, "불아");
			break;
		}
		else if (subChoice == 2)
		{
			_MyHero = new Water_Ousters(50, 400, 200, "물아");
			break;
		}
		else if (subChoice == 3)
		{
			_MyHero = new Earth_Ousters(75, 300, 150, "대아");
			break;
		}
	}
}

void Hero::showHeroInfo(void)
{
	_MyHero->showInfo();
}

