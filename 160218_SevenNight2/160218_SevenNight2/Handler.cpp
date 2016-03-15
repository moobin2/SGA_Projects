#include "Handler.h"



void Handler::MakePlayer(void)
{
	int pHP, pMP, cHP, cMP;
	char playname[20];
	char computername[20];
	cout << "본인 케릭터 이름을 입력하세요 : "; cin >> playname;
	cout << "본인 케릭터 체력을 입력하세요 : "; cin >> pHP;
	cout << "본인 케릭터 마나를 입력하세요 : "; cin >> pMP;
	cout << "----------------------------------------" << endl;
	cout << "상대 케릭터 이름을 입력하세요 : "; cin >> computername;
	cout << "상대 케릭터 체력을 입력하세요 : "; cin >> cHP;
	cout << "상대 케릭터 마나를 입력하세요 : "; cin >> cMP;
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
		cout << " << 1P의 턴 >> " << endl << "스킬 : ";
		cin >> skillNum;
		if (randHit != 0)
		{
			int skilldamage = _player[player]->skilldamage(skillNum-1);
			if (random == 0) cout << "엄청난 몸놀림을 보여주며 '";
			else if (random == 1) cout << "신들린듯이 '";
			else if (random == 2) cout << "초하이퍼강력한 '";
			else cout << "미친듯이 '";
			cout << _player[player]->getSkillname(skillNum - 1) << "'을(를) 사용하였다" << endl;;
			cout << skilldamage << "의 피해를 입혔다." << endl;
			_player[computer]->decreaseHP(skilldamage);
			cout << endl << "상대남은체력 : " << _player[computer]->getHP() << endl;
		}
		else
		{
			cout << "발이 미끄러져 공격에 실패했다" << endl;
			cout << endl << "상대남은체력 : " << _player[computer]->getHP() << endl;
		}
	}
	else
	{
		int randHit = rand() % 5;
		int random = rand() % 4;
		int skillNum = rand() % 3;
		cout << endl << " << 2P의 턴 >> " << endl << "스킬 : " << skillNum + 1 << endl;
		if (randHit != 0)
		{
			int skilldamage = _player[computer]->skilldamage(skillNum);
			if (random == 0) cout << "엄청난 몸놀림을 보여주며 '";
			else if (random == 1) cout << "신들린듯이 '";
			else if (random == 2) cout << "초하이퍼강력한 '";
			else cout << "미친듯이 '";
			cout << _player[computer]->getSkillname(skillNum) << "'을(를) 사용하였다" << endl;
			cout << skilldamage << "의 피해를 입혔다" << endl;
			_player[player]->decreaseHP(skilldamage);
			cout << endl << "상대남은체력 : " << _player[player]->getHP() << endl;
		}
		else
		{
			cout << "발이 미끄러져 공격에 실패했다" << endl;
			cout << endl << "상대남은체력 : " << _player[player]->getHP() << endl;
		}
	}
}

void Handler::showPlayerInfo(void)
{  
	cout << endl << "         << 1P >>                               << 2P >>" << endl;
	cout << "━━━━━━━━━━━━━  기본정보  ━━━━━━━━━━━━━" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 0) cout << "  이름 : " << _player[j]->getname() << "\t\t\t\t";
			else if (i == 0 && j == 1) cout << "이름 : " << _player[j]->getname();
			else if (i == 1 && j == 0) cout << "  체력 : " << _player[j]->getHP() << "\t\t\t\t";
			else if (i == 1 && j == 1) cout << "체력 : " << _player[j]->getHP();
			else if (i == 2 && j == 0) cout << "  마나 : " << _player[j]->getMP() << "\t\t\t\t";
			else cout << "마나 : " << _player[j]->getMP() << "\t\t\t\t";
		}
		cout << endl;
	}
	cout << "━━━━━━━━━━━━━  스킬정보  ━━━━━━━━━━━━━" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 0) cout << "  스킬1 : " << _player[j]->getSkillname(i) << "\t\t";
			else if (i == 0 && j == 1) cout << "스킬1 : " << _player[j]->getSkillname(i);
			else if (i == 1 && j == 0) cout << "  스킬2 : " << _player[j]->getSkillname(i) << "\t\t";
			else if (i == 1 && j == 1) cout << "스킬2 : " << _player[j]->getSkillname(i);
			else if (i == 2 && j == 0) cout << "  스킬3 : " << _player[j]->getSkillname(i) << "\t\t";
			else cout << "스킬3 : " << _player[j]->getSkillname(i) << "\t\t";
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
			cout << endl << "\t\t\t<< 승자는!! 1P : " << _player[player]->getname() << " >>" << endl;
		}
		else cout << endl << "\t\t\t<< 승자는!! 2P : " << _player[computer]->getname() << " >>" << endl;
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
	cout << endl << "프로그램을 종료합니다." << endl << endl;
}
