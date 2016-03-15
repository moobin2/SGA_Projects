#pragma once

#include "gameNode.h"

enum GameSet
{
	NonClick,
	Click,
	GameEnd,
	GameAnswer
};

class gameStudy : public gameNode
{
private:
	RECT _toothRect[20];
	int _toothState[20];
	bool _isGameEnd;
	int _x, _y;
	int _red[20], _green[20], _blue[20];
	int _clickCount;
	TCHAR str[128];
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void toothMove(void);
};

