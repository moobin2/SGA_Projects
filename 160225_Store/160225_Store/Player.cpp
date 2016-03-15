#include "Player.h"


int Player::getmoney(void)
{
	return _money;
}

void Player::buyItem(int itemNum)
{
	switch (itemNum)
	{
	case 1:
		_inven.push_back(new Item("산타의 선물", "잡화", 0, 0, 50000, 100000, "뜬금없는 산타선물. 팔면..?!"));
		_money -= 50000;
		_itemNum++;
		break;
	case 2:
		_inven.push_back(new Item("  여의봉   ", "무기", 380, 0, 200000, 50000, "손오공의 손때가 있는 여의봉"));
		_money -= 200000;
		_itemNum++;
		break;
	case 3:
		_inven.push_back(new Item(" 사령의포 ", "갑옷", 0, 248, 100000, 1000, "카일이 밥먹다가 놓고간 옷"));
		_money -= 100000;
		_itemNum++;
		break;
	case 4:
		_inven.push_back(new Item("루디의 방패", "방패", 0, 200, 250000, 70000, "루디사마의 채취가 묻어있는 방패"));
		_money -= 250000;
		_itemNum++;
		break;
	case 5:
		_inven.push_back(new Item("장쌤 키보드", "전설", 999, 999, 500000, 1, "소유시 코딩능력이 증가하는 전설의템"));
		_money -= 300000;
		_itemNum++;
		break;
	}
}

void Player::sellItem(int itemNum)
{
	int i = 0;
	if (_inven.empty() == true)
	{
		cout << "소지한 아이템이 없습니다." << endl;
		return;
	}

	for (_invenPos = _inven.begin(); _invenPos != _inven.end(); ++_invenPos, ++i)
	{
		if (i == itemNum - 1)
		{
			cout << "\t\t'" << (*_invenPos)->getName() << "'을(를) " << (*_invenPos)->getSellPrice() << "원에 판매하였습니다." << endl;
			_itemNum--;
			_money += (*_invenPos)->getSellPrice();
			delete *_invenPos;
			_invenPos = _inven.erase(_invenPos);
			break;
		}
	}
}

void Player::showitemInfo(int itemPos)
{
	if (_inven.empty() == true)
	{
		cout << "소지한 아이템이 없습니다." << endl;
		return;
	}
	cout << endl << "\t\t\t <<" <<  _inven[itemPos - 1]->getName() <<">>" << endl << endl;
	cout << "\t\t타입 : " << _inven[itemPos - 1]->getType() << endl;
	cout << "\t\t공격 : " << _inven[itemPos - 1]->getDam() << endl;
	cout << "\t\t방어 : " << _inven[itemPos - 1]->getDef() << endl;
	cout << "\t\t구매가격 : " << _inven[itemPos - 1]->getBuyPrice() << endl;
	cout << "\t\t판매가격 : " << _inven[itemPos - 1]->getSellPrice() << endl;
	cout << "\t\t정보 : " << _inven[itemPos - 1]->getInfo() << endl;
}


void Player::showInven(void)
{
	cout << endl;
	cout << "     ■    ■     ■    ■      ■    ■■■■    ■     ■   " << endl;
	cout << "     ■    ■■   ■    ■      ■    ■          ■■   ■   " << endl;
	cout << "     ■    ■ ■  ■     ■    ■     ■          ■ ■  ■   " << endl;
	cout << "     ■    ■  ■ ■      ■  ■      ■■■■    ■  ■ ■   " << endl;
	cout << "     ■    ■   ■■       ■■       ■          ■   ■■   " << endl;
	cout << "     ■    ■     ■        ■        ■■■■    ■     ■   " << endl;
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "    < 이름 >      < 타입 >               < 정보 >" << endl << endl;
	for (int i = 0; i < _itemNum; i++)
	{
		cout << i + 1 << ". " << _inven[i]->getName() << "\t    " << _inven[i]->getType() << "\t" << _inven[i]->getInfo() << endl;
	}
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}

Player::Player() : _money(1000000), _itemNum(0)
{
}


Player::~Player()
{
	for (int i = 0; i < _itemNum; i++)
	{
		delete _inven[i];
	}
}
