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

	_x = CENTERX;
	_y = CENTERY;

	_rc = RectMakeCenter(_x, _y, 100, 100);
	_direction = Right;
	red = green = blue = 255;

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{

	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		if (PtInRect(&_rc, _ptMouse))
		{
			red = RND->getInt(256);
			green = RND->getInt(256);
			blue = RND->getInt(256);
		}
	}

	rectMove();

	_rc = RectMakeCenter(_x, _y, 100, 100);

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	HBRUSH bitmap, oldbitmap;
	bitmap = CreateSolidBrush(RGB(red, green, blue));
	oldbitmap = (HBRUSH)SelectObject(hdc, bitmap);
	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(hdc, oldbitmap);
	DeleteObject(bitmap);
}

void gameStudy::rectMove(void)
{
	if (_direction == Right)
	{
		_x += 4;
		if (_rc.right > WINSIZEX) _direction = Left;
	}
	else if (_direction == Left)
	{
		_x -= 4;
		if (_rc.left < 0) _direction = Right;
	}
}
