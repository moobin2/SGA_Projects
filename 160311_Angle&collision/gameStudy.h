#pragma once

#include "gameNode.h"
#define PI 3.141592654f
#define bulletNum 200

struct tagBullet
{

	RECT rcBullet;
	float centerX;
	float centerY;
	float bulletAngle;
	float speed;
	int bitmapNumber;
	bool isFire;
};						

class gameStudy : public gameNode
{
private:
	RECT _ellipse;
	tagBullet _bullet[bulletNum];
	float _angle;
	float _lineX;
	float _lineY;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void bulletFire(void);
	void bulletMove(void);
	void collision(void);
	float distance(float x1, float x2, float y1, float y2);
};

