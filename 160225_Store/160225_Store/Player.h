#pragma once
#include "Item.h"
#include <vector>

class Player
{
	int _money;
	int _itemNum;
	vector<Item*> _inven;
	vector<Item*>::iterator _invenPos;
public:
	int getmoney(void);
	void buyItem(int itemNum);
	void sellItem(int itemNum);
	void showitemInfo(int itemPos);
	void showInven(void);
	Player();
	~Player();
};

