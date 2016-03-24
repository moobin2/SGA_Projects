#pragma once

#include "gameNode.h"

struct tagCookie
{
	RECT CookieRc;
	float jumpPower;
	float gravity;
	bool sliding;
	bool jump;
	bool run;
	int jumpCount;
};

class gameStudy : public gameNode
{
private:
	image* _CookieImage;
	image* _background1[2];
	image* _background2[2];
	image* _button;
	tagCookie _Cookie;
	RECT _land;
	bool _slideButton;
	bool _jumpButton;
	int _motionCount;
	int _gameCount;
	int _backX1;
	int _backX2;
public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void imageSetting(void);
	void silding(void);
	void jump(void);
	void jumpMove(void);
};

