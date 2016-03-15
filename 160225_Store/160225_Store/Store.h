#pragma once
#include "Item.h"
class Store
{
	Item* itemList[5];
public:
	Store();
	~Store();
	
	int itemPrice(int itemNum);
	char* itemName(int itemNum);
	void showItemList(void);
};

