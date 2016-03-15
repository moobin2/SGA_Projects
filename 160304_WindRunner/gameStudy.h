#pragma once

#include "gameNode.h"
#include <time.h>

struct Obstacle
{
	RECT Hstruct;
	RECT Vstruct;
	RECT FireBall;
};

class gameStudy : public gameNode
{
private:
	RECT _rc;
	RECT _temp;
	RECT _land[2];
	Obstacle Hurdle[2];
	int _jumpCount;
	int width;
	float _gravity, _jumpPower;


public:
	gameStudy();
	virtual ~gameStudy();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	BOOL collisionUp(RECT* r1, RECT* r2);
	BOOL collisionDown(RECT* r1, RECT* r2);
	BOOL collisionRight(RECT* r1, RECT* r2);
	BOOL collisionLeft(RECT* r1, RECT* r2);
};

