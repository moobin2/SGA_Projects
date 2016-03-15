#pragma once

#include "gameNode.h"
#define PI 3.141592654f

struct tagWatch
{
	POINT second;
	POINT minute;
	POINT hour;
	POINT first;
	int hourBar;
	int minuteBar;
	int secondBar;

};

class gameStudy : public gameNode
{
private:
	SYSTEMTIME _time;
	tagWatch _watch;
	int _sec, _min, _hour;
	float hourAngle;
	float minuteAngle;
	float secondAngle;
	int count;
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

};

