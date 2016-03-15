#pragma once

#include "gameNode.h"


class gameStudy : public gameNode
{
private:
	int _x, _y;
	RECT _rc, _rcEll, _tempRc;
	TCHAR str[128];
	POINT pRect;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	LONG Distance(POINT p1, POINT p2);
};

