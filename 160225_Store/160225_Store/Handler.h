#pragma once
#include "Player.h"
#include "Store.h"
#include <Windows.h>

class Handler
{
	Player _buyer;
	Store _seller;
public:
	void gotoStore(void);
	void gotoinven(void);
	void printFirstScreen(void);
	Handler();
	~Handler();
};

