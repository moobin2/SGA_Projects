#pragma once

#include "gameNode.h"
#define CardNum 18
enum Cardstate
{
	nonOpen,
	Open
};

struct Card
{
	RECT _rc;
	int _number;
	int red;
	int green;
	int blue;
	bool CardOpen;
	bool answer;
};

class gameStudy : public gameNode
{
private:
	Card inCardState[18];
	int _clickCount;
	int _TimeCount;
	int first, second;
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void shuffle(Card * card);
	BOOL answerCheck(int first, int Second);
};

