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
		_inven.push_back(new Item("��Ÿ�� ����", "��ȭ", 0, 0, 50000, 100000, "��ݾ��� ��Ÿ����. �ȸ�..?!"));
		_money -= 50000;
		_itemNum++;
		break;
	case 2:
		_inven.push_back(new Item("  ���Ǻ�   ", "����", 380, 0, 200000, 50000, "�տ����� �ն��� �ִ� ���Ǻ�"));
		_money -= 200000;
		_itemNum++;
		break;
	case 3:
		_inven.push_back(new Item(" ������� ", "����", 0, 248, 100000, 1000, "ī���� ��Դٰ� ���� ��"));
		_money -= 100000;
		_itemNum++;
		break;
	case 4:
		_inven.push_back(new Item("����� ����", "����", 0, 200, 250000, 70000, "���縶�� ä�밡 �����ִ� ����"));
		_money -= 250000;
		_itemNum++;
		break;
	case 5:
		_inven.push_back(new Item("��� Ű����", "����", 999, 999, 500000, 1, "������ �ڵ��ɷ��� �����ϴ� ��������"));
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
		cout << "������ �������� �����ϴ�." << endl;
		return;
	}

	for (_invenPos = _inven.begin(); _invenPos != _inven.end(); ++_invenPos, ++i)
	{
		if (i == itemNum - 1)
		{
			cout << "\t\t'" << (*_invenPos)->getName() << "'��(��) " << (*_invenPos)->getSellPrice() << "���� �Ǹ��Ͽ����ϴ�." << endl;
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
		cout << "������ �������� �����ϴ�." << endl;
		return;
	}
	cout << endl << "\t\t\t <<" <<  _inven[itemPos - 1]->getName() <<">>" << endl << endl;
	cout << "\t\tŸ�� : " << _inven[itemPos - 1]->getType() << endl;
	cout << "\t\t���� : " << _inven[itemPos - 1]->getDam() << endl;
	cout << "\t\t��� : " << _inven[itemPos - 1]->getDef() << endl;
	cout << "\t\t���Ű��� : " << _inven[itemPos - 1]->getBuyPrice() << endl;
	cout << "\t\t�ǸŰ��� : " << _inven[itemPos - 1]->getSellPrice() << endl;
	cout << "\t\t���� : " << _inven[itemPos - 1]->getInfo() << endl;
}


void Player::showInven(void)
{
	cout << endl;
	cout << "     ��    ��     ��    ��      ��    �����    ��     ��   " << endl;
	cout << "     ��    ���   ��    ��      ��    ��          ���   ��   " << endl;
	cout << "     ��    �� ��  ��     ��    ��     ��          �� ��  ��   " << endl;
	cout << "     ��    ��  �� ��      ��  ��      �����    ��  �� ��   " << endl;
	cout << "     ��    ��   ���       ���       ��          ��   ���   " << endl;
	cout << "     ��    ��     ��        ��        �����    ��     ��   " << endl;
	cout << "����������������������������������������������������������������" << endl;
	cout << "    < �̸� >      < Ÿ�� >               < ���� >" << endl << endl;
	for (int i = 0; i < _itemNum; i++)
	{
		cout << i + 1 << ". " << _inven[i]->getName() << "\t    " << _inven[i]->getType() << "\t" << _inven[i]->getInfo() << endl;
	}
	cout << "����������������������������������������������������������������" << endl;
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
