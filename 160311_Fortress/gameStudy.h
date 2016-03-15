#pragma once

#include "gameNode.h"
#define PI 3.141592654f

enum Bombkinds
{
	blackBin,
	redBin
};

struct tagBomb
{
	RECT rcBomb;
	float speed;
	float angle;	
	float bombCenterX;
	float bombCenterY;
	float powerX;
	float powerY;
	bool bombMove;
};

struct tagTank
{
	tagBomb Bomb[2];
	POINT tankCenter;
	RECT rcTank;
	RECT HpBar;
	RECT MoveBar;
	RECT EnergyBar;
	float angle;
	float angleX;
	float angleY;
	float cannonX;
	float cannonY;
	bool direction;
	bool move;
	bool bombKinds;
};

class gameStudy : public gameNode
{
private:
	tagTank _tank;
	RECT _bombKinds[2];
	RECT _itemRect[2];
	RECT _powerBar;
	float _gravity;
	float _shotPower;
	int _gameCount;
	bool _countOn;
	bool _bombOn;
	bool _doubleOn;
	bool _teleportOn;
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void BombFire(int kinds);
	void BombMove();
	
};

