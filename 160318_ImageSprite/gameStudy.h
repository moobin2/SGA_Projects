#pragma once

#include "gameNode.h"

enum tagDirection
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	RIGHTUP,
	LEFTUP,
	RIGHTDOWN,
	LEFTDOWN
};


class gameStudy : public gameNode
{
private:
	image* _working;
	image* _background;
	float _x, _y;
	bool _standing;
	int _direction;
	int _motionCount;
	int _gameCount;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void motion(void);
};

