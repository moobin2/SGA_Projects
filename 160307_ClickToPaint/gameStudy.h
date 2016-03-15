#pragma once

#include "gameNode.h"

enum direction
{
	Right,
	Left
};

class gameStudy : public gameNode
{
private:
	RECT _rc;
	int _x, _y;
	int red, green, blue;
	bool _direction;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void rectMove(void);
};

