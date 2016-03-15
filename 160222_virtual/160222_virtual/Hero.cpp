#include "Hero.h"



Hero::Hero()
{
	srand((size_t)time(NULL));
	int randNum = rand() % 9;
	switch (randNum)
	{
	case 0:
		_EnemyHero = new Blade_Slayer(100, 500, 100, "����");
		break;
	case 1:
		_EnemyHero = new Gun_Slayer(75, 375, 150, "�ѽ�");
		break;
	case 2:
		_EnemyHero = new Heal_Slayer(50, 250, 200, "����");
		break;
	case 3:
		_EnemyHero = new STR_Vampire(100, 400, "����");
		break;
	case 4:
		_EnemyHero = new DEX_Vampire(150, 250, "����");
		break;
	case 5:
		_EnemyHero = new INT_Vampire(200, 100, "�ι�");
		break;
	case 6:
		_EnemyHero = new Fire_Ousters(100, 200, 100, "�Ҿ�");
		break;
	case 7:
		_EnemyHero = new Water_Ousters(50, 400, 200, "����");
		break;
	case 8:
		_EnemyHero = new Earth_Ousters(75, 300, 150, "���");
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

	cout << endl << "\t\t\t << ���� >> " << endl << endl;
	cout << "1.  �����̾�  (�⺻ü�� : 2000, �⺻���� : 500, �⺻������ : 100)" << endl;
	cout << "2.  �����̾�  (�⺻ü�� : 3000,                 �⺻������ :  50)" << endl;
	cout << "3. �ƿ콺���� (�⺻ü�� : 2500, �⺻���� : 100, �⺻������ :  75)" << endl;
	cout << "���� : "; cin >> choice;

	cout << endl << "\t\t\t -- ���� -- " << endl << endl;
	switch (choice)
	{
	case 1:
		cout << "    1. ���� (�߰������� : 100, �߰�ü�� : 500, �߰����� : 100)" << endl;
		cout << "    2. �ѽ� (�߰������� :  75, �߰�ü�� : 375, �߰����� : 150)" << endl;
		cout << "    3. ���� (�߰������� :  50, �߰�ü�� : 250, �߰����� : 200)" << endl;
		cout << "���� : "; cin >> subChoice;
		cout << endl;
		if (subChoice == 1)
		{
			_MyHero = new Blade_Slayer(100, 500, 100, "����");
			break;
		}
		else if (subChoice == 2)
		{
			_MyHero = new Gun_Slayer(75, 375, 150, "�ѽ�");
			break;
		}
		else if (subChoice == 3)
		{
			_MyHero = new Heal_Slayer(50, 250, 200, "����");
			break;
		}
	case 2:
		cout << "\t   1. ���� (�߰������� : 100, �߰�ü�� : 400)" << endl;
		cout << "\t   2. ���� (�߰������� : 150, �߰�ü�� : 250)" << endl;
		cout << "\t   3. �ι� (�߰������� : 200, �߰�ü�� : 100)" << endl;
		cout << "���� : "; cin >> subChoice;
		if (subChoice == 1)
		{
			_MyHero = new STR_Vampire(100, 400, "����");
			break;
		}
		else if (subChoice == 2)
		{
			_MyHero = new DEX_Vampire(150, 250, "����");
			break;
		}
		else if (subChoice == 3)
		{
			_MyHero = new INT_Vampire(200, 100, "�ι�");
			break;
		}
	case 3:
		cout << "    1. �Ҿ� (�߰������� : 100, �߰�ü�� : 200, �߰����� : 100)" << endl;
		cout << "    2. ���� (�߰������� :  50, �߰�ü�� : 400, �߰����� : 200)" << endl;
		cout << "    3. ��� (�߰������� :  75, �߰�ü�� : 300, �߰����� : 150)" << endl;
		cout << "���� : "; cin >> subChoice;
		if (subChoice == 1)
		{
			_MyHero = new Fire_Ousters(100, 200, 100, "�Ҿ�");
			break;
		}
		else if (subChoice == 2)
		{
			_MyHero = new Water_Ousters(50, 400, 200, "����");
			break;
		}
		else if (subChoice == 3)
		{
			_MyHero = new Earth_Ousters(75, 300, 150, "���");
			break;
		}
	}
}

void Hero::showHeroInfo(void)
{
	_MyHero->showInfo();
}

