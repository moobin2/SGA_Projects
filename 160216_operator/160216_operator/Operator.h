#pragma once
#include <iostream>

using namespace std;

class Operator
{
	char* _name;
	int _age;
	char* _gender;
public:
	Operator();
	Operator(char* _name, int _age, char* _info);
	~Operator();
	void showInfo(void);

	Operator& operator=(const Operator& ref);
	Operator& operator+(int num);
	Operator& operator-(int num);

};

