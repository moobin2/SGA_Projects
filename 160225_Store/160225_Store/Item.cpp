#include "Item.h"

//char* _name;
//int _damNdef;
//int _buyPrice;
//int _sellPrice;
//char* _Info;

char * Item::getName(void) const
{
	return _name;
}

char * Item::getType(void) const
{
	return _type;
}

int Item::getDam(void) const
{
	return _dam;
}

int Item::getDef(void) const
{
	return _def;
}

int Item::getBuyPrice(void) const
{
	return _buyPrice;
}

int Item::getSellPrice(void) const
{
	return _sellPrice;
}

char * Item::getInfo(void) const
{
	return _Info;
}

Item::Item(char* name, char* type, int dam, int def, int bprice, int sprice, char* info) : _dam(dam), _def(def), _buyPrice(bprice), _sellPrice(sprice)
{
	_name = new char[strlen(name) + 1]; 
	strcpy_s(_name, strlen(name) + 1, name);

	_type = new char[strlen(type) + 1];
	strcpy_s(_type, strlen(type) + 1, type);

	_Info = new char[strlen(info) + 1];
	strcpy_s(_Info, strlen(info) + 1, info);
}

Item::~Item()
{
	delete[]_name;
	delete[]_type;
	delete[]_Info;
}
