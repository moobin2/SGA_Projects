#pragma once

#include "gameNode.h"


class gameStudy : public gameNode
{
private:
	image* _Olivia;
	RECT _rcOlivia;
	RECT _land;
	RECT _temp;
	RECT _stone;

	bool _isRight;
	bool _standing;
	bool _jumping;
	int _count;
	int _index;
	float _jumpPower;
	float _gravity;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

};

