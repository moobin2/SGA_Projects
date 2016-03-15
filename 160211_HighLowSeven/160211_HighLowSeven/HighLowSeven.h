#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Card
{
	char* shape;
	int number;
};

class HighLowSeven
{
	Card trump[52];
	int money;
public:
	HighLowSeven();
	~HighLowSeven();

	void CardPrint(int num);
};

