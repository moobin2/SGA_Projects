#pragma once

#include "gameNode.h"
#include <time.h>

struct Hurdle
{
	RECT hUp;
	RECT hDown;
};

class gameStudy : public gameNode
{
private:
	RECT _rc;
	RECT _land;
	RECT _temp;
	float _gravity, _jumpPower;
	bool _isJump;
	bool _start;
	Hurdle _Hstruct[2];

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};

