#include "Handler.h"



void Handler::MakePlayer(void)
{
	int pHP, pMP, cHP, cMP;
	char playname[20];
	char computername[20];
	cout << "���� �ɸ��� �̸��� �Է��ϼ��� : "; cin >> playname;
	cout << "���� �ɸ��� ü���� �Է��ϼ��� : "; cin >> pHP;
	cout << "���� �ɸ��� ������ �Է��ϼ��� : "; cin >> pMP;
	cout << "----------------------------------------" << endl;
	cout << "��� �ɸ��� �̸��� �Է��ϼ��� : "; cin >> computername;
	cout << "��� �ɸ��� ü���� �Է��ϼ��� : "; cin >> cHP;
	cout << "��� �ɸ��� ������ �Է��ϼ��� : "; cin >> cMP;
	_player[0] = new Hero(pHP, pMP, playname, player);
	_player[1] = new Hero(cHP, cMP, computername, computer);
}

void Handler::MakeAttack(int character)
{
	if (character == player)
	{
		int randHit = rand() % 4;
		int skillNum;
		int random = rand() % 4;
		cout << " << 1P�� �� >> " << endl << "��ų : ";
		cin >> skillNum;
		if (randHit != 0)
		{
			int skilldamage = _player[player]->skilldamage(skillNum-1);
			if (random == 0) cout << "��û�� ����� �����ָ� '";
			else if (random == 1) cout << "�ŵ鸰���� '";
			else if (random == 2) cout << "�������۰����� '";
			else cout << "��ģ���� '";
			cout << _player[player]->getSkillname(skillNum - 1) << "'��(��) ����Ͽ���" << endl;;
			cout << skilldamage << "�� ���ظ� ������." << endl;
			_player[computer]->decreaseHP(skilldamage);
			cout << endl << "��볲��ü�� : " << _player[computer]->getHP() << endl;
		}
		else
		{
			cout << "���� �̲����� ���ݿ� �����ߴ�" << endl;
			cout << endl << "��볲��ü�� : " << _player[computer]->getHP() << endl;
		}
	}
	else
	{
		int randHit = rand() % 5;
		int random = rand() % 4;
		int skillNum = rand() % 3;
		cout << endl << " << 2P�� �� >> " << endl << "��ų : " << skillNum + 1 << endl;
		if (randHit != 0)
		{
			int skilldamage = _player[computer]->skilldamage(skillNum);
			if (random == 0) cout << "��û�� ����� �����ָ� '";
			else if (random == 1) cout << "�ŵ鸰���� '";
			else if (random == 2) cout << "�������۰����� '";
			else cout << "��ģ���� '";
			cout << _player[computer]->getSkillname(skillNum) << "'��(��) ����Ͽ���" << endl;
			cout << skilldamage << "�� ���ظ� ������" << endl;
			_player[player]->decreaseHP(skilldamage);
			cout << endl << "��볲��ü�� : " << _player[player]->getHP() << endl;
		}
		else
		{
			cout << "���� �̲����� ���ݿ� �����ߴ�" << endl;
			cout << endl << "��볲��ü�� : " << _player[player]->getHP() << endl;
		}
	}
}

void Handler::showPlayerInfo(void)
{  
	cout << endl << "         << 1P >>                               << 2P >>" << endl;
	cout << "��������������������������  �⺻����  ��������������������������" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 0) cout << "  �̸� : " << _player[j]->getname() << "\t\t\t\t";
			else if (i == 0 && j == 1) cout << "�̸� : " << _player[j]->getname();
			else if (i == 1 && j == 0) cout << "  ü�� : " << _player[j]->getHP() << "\t\t\t\t";
			else if (i == 1 && j == 1) cout << "ü�� : " << _player[j]->getHP();
			else if (i == 2 && j == 0) cout << "  ���� : " << _player[j]->getMP() << "\t\t\t\t";
			else cout << "���� : " << _player[j]->getMP() << "\t\t\t\t";
		}
		cout << endl;
	}
	cout << "��������������������������  ��ų����  ��������������������������" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 0) cout << "  ��ų1 : " << _player[j]->getSkillname(i) << "\t\t";
			else if (i == 0 && j == 1) cout << "��ų1 : " << _player[j]->getSkillname(i);
			else if (i == 1 && j == 0) cout << "  ��ų2 : " << _player[j]->getSkillname(i) << "\t\t";
			else if (i == 1 && j == 1) cout << "��ų2 : " << _player[j]->getSkillname(i);
			else if (i == 2 && j == 0) cout << "  ��ų3 : " << _player[j]->getSkillname(i) << "\t\t";
			else cout << "��ų3 : " << _player[j]->getSkillname(i) << "\t\t";
		}
		cout << endl;
	}
}

bool Handler::HPcheck(void)
{
	if ((_player[player]->getHP()) <= 0 || (_player[computer]->getHP() <= 0))
	{
		if (_player[player]->getHP() > _player[computer]->getHP())
		{
			cout << endl << "\t\t\t<< ���ڴ�!! 1P : " << _player[player]->getname() << " >>" << endl;
		}
		else cout << endl << "\t\t\t<< ���ڴ�!! 2P : " << _player[computer]->getname() << " >>" << endl;
		return TRUE;
	}
	else return FALSE;

}

Handler::Handler()
{
}


Handler::~Handler()
{
	for (int i = 0; i < 2; i++)
	{
		delete _player[i];
	}
	cout << endl << "���α׷��� �����մϴ�." << endl << endl;
}
