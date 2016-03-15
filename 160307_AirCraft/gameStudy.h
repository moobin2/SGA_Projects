#pragma once

#include "gameNode.h"
#include <vector>

enum User
{
	me,
	com
};

enum Direction
{
	Up,
	Down
};

class gameStudy : public gameNode
{
private:
	int _xMyPos, _yMyPos;
	int _xComPos, _yComPos;
	bool _comMove;
	RECT _player[2];
	RECT _HPbar[2];
	vector<RECT> _vMissile;
	vector<RECT> ::iterator _viMissile;
	vector<RECT> _vComMissile;
	vector<RECT> ::iterator _viComMissile;
	int _missileCount , _comMissileCount;
	int _red[2], _green[2], _blue[2];
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void ComMove(void);
	void shotMissile(int player);
	void missileMove(void);
	void outOfMissile(void);
	BOOL Collision(int player);
};

