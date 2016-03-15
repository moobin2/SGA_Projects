#pragma once
#include "Human.h"

class Student : public Human
{
public:
	void eating();
	void study();
	void play();
	Student();
	~Student();
};

