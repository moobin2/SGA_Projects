#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init();

	_working = new image;
	_background = new image;
	_working->init("working.bmp", 900, 816, true, RGB(255, 0, 255));
//	_background->init("background.bmp", 256, 256, false, false);

	_x = CENTERX;
	_y = CENTERY;
	_direction = DOWN;
	_motionCount = _gameCount = 0;
	_standing = true;

	return S_OK;
}

void gameStudy::release()
{
	_working->release();
	SAFE_DELETE(_working);



	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_standing = false;
		_y -= 2;
		_direction = UP;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_standing = false;
		_y += 2;
		_direction = DOWN;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_standing = false;
		_x -= 2;
		_direction = LEFT;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_standing = false;
		_x += 2;
		_direction = RIGHT;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && (KEYMANAGER->isStayKeyDown(VK_LEFT)))
	{
		_direction = RIGHTUP;
		_standing = false;
		_x -= 0.5f;
		_y -= 0.5f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && (KEYMANAGER->isStayKeyDown(VK_RIGHT)))
	{
		_direction = LEFTUP;
		_standing = false;
		_x += 0.5f;
		_y -= 0.5f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && (KEYMANAGER->isStayKeyDown(VK_LEFT)))
	{
		_direction = RIGHTDOWN;
		_standing = false;
		_x -= 0.5f;
		_y += 0.5f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && (KEYMANAGER->isStayKeyDown(VK_RIGHT)))
	{
		_direction = LEFTDOWN;
		_standing = false;
		_x += 0.5f;
		_y += 0.5f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP) || KEYMANAGER->isOnceKeyUp(VK_DOWN) || KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_standing = true;
		_motionCount = 0;
	}

	_gameCount++;
	motion();
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//HBRUSH brush = CreatePatternBrush(_background);
	//HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
	//if (!_standing)
	//{
		if (_direction == UP) _working->render(backDC, _x, _y, _motionCount * 73 + 462, 0, 73, 128);
		else if (_direction == DOWN) _working->render(backDC, _x, _y, _motionCount * 77, 0, 77, 128);
		else if (_direction == LEFT) _working->render(backDC, _x, _y, _motionCount * 150, 128, 150, 115);
		else if (_direction == RIGHT) _working->render(backDC, _x, _y, (5 - _motionCount) * 150, 243, 150, 115);
		else if (_direction == LEFTUP) _working->render(backDC, _x, _y, _motionCount * 135, 707, 135, 109);
		else if (_direction == RIGHTUP) _working->render(backDC, _x, _y, _motionCount * 135, 598, 135, 109);
		else if (_direction == LEFTDOWN) _working->render(backDC, _x, _y, _motionCount * 136, 478, 136, 120);
		else if (_direction == RIGHTDOWN) _working->render(backDC, _x, _y, _motionCount * 136, 358, 136, 120);
	//}
	//else if (_standing)
	//{

	//}

	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::motion(void)
{
	if (_gameCount == 5)
	{
		_gameCount = 0;
		_motionCount++;
		if (_motionCount == 6) _motionCount = 0;
	}
}


