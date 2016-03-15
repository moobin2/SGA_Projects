#include "Operator.h"



Operator::Operator()
{
}

Operator::Operator(char* name, int age, char* gender) : _age(age)
{
	_name = new char[strlen(name) + 1];
	strcpy_s(_name, strlen(name) + 1, name);

	_gender = new char[strlen(gender) + 1];
	strcpy_s(_gender, strlen(gender) + 1, gender);
}

Operator::~Operator()
{
	delete[]_name;
	delete[]_gender;
}

void Operator::showInfo(void)
{
	cout << "이름 : " << _name << endl;
	cout << "나이 : " << _age << endl;
	cout << "성별 : " << _gender << endl << endl;
}

Operator & Operator::operator=(const Operator & ref)
{
	_name = new char[strlen(ref._name) + 1];
	strcpy_s(_name, strlen(ref._name) + 1, ref._name);

	_gender = new char[strlen(ref._gender) + 1];
	strcpy_s(_gender, strlen(ref._gender) + 1, ref._gender);

	_age = ref._age;

	return*this;
}

Operator & Operator::operator+(int num)
{
		this->_age += num;
		return*this;
}

Operator & Operator::operator-(int num)
{
		this->_age -= num;
		return*this;
}
