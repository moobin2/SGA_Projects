#pragma once
#include <iostream>

using namespace std;

class Item
{
	char* _name;
	char* _type;
	int _dam;
	int _def;
	int _buyPrice;
	int _sellPrice;
	char* _Info;
public:
	char* getName(void) const;
	char* getType(void) const;
	int getDam(void) const;
	int getDef(void) const;
	int getBuyPrice(void) const;
	int getSellPrice(void) const;
	char* getInfo(void) const;
	Item(char* name, char* type, int dam, int def, int bprice, int sprice, char* info);
	~Item();
};

