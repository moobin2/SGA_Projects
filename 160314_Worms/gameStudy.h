#pragma once

#include "gameNode.h"

#define PI 3.141592654f
#define WormsNum 30

enum item
{
	addBody,
	destroy
};

struct tagObject
{
	float CenterX;
	float CenterY;
	bool screenOn;
};

struct tagWorms
{
	float CenterX;
	float CenterY;
	bool move;
};

class gameStudy : public gameNode
{
private:
	float _angle[2];
	float _speed[2];
	tagWorms _Worms[WormsNum];
	tagWorms _comWorms[WormsNum];
	tagObject _itemBox[2];
	int _gameCount;
	int _pointCount;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	float getDistance(float x1, float y1, float x2, float y2);
	float getAngle(float x1, float y1, float x2, float y2);
	void moveWorms(void);
	void CollisionItemBox(void);
	void CreatTails(void);
	void CreatComTails(void);
	void DestroyTails(void);
	void Collision(void);
};

