#include "stdafx.h"
#include "gameStudy.h"
#include "resource.h"



gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init();
	width = RND->getInt(200) + 200;
	_rc = RectMakeCenter (WINSIZEX / 5, WINSIZEY - 150, 50, 50);

	_gravity = _jumpPower = _jumpCount = 0;

	for (int i = 0; i < 2; i++)
	{
		_land[i] = RectMakeCenter(200 + i * 600, WINSIZEY - 100, width, 50);
		Hurdle[i].Hstruct = RectMake(RND->getInt(100) + 400 + 600 * i, RND->getInt(200) + 200, RND->getInt(100) + 200, 50);
		Hurdle[i].FireBall = RectMake(WINSIZEX + 650 * i, RND->getInt(WINSIZEY - 300) + 200, 50, 50);
	}
	Hurdle[0].Vstruct = RectMakeLB(RND->getInt(200) + 800, 0, 50, 300);
	Hurdle[1].Vstruct = RectMake(RND->getInt(200) + 800 + 650, WINSIZEY, 50, 300);

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5;
		_rc.right -= 5;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5;
		_rc.right += 5;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))
	{
		if (_jumpCount < 2)
		{ 
			_jumpPower = 6;
			_gravity = 0.1;
			_jumpCount += 1;
		}
	}

	if (_jumpCount <= 2)
	{
		_rc.top -= _jumpPower;
		_rc.bottom -= _jumpPower;
		_jumpPower -= _gravity;
	}

	if (_rc.top < 6)
	{
		_jumpPower = 0;
		_rc.top += 4;
		_rc.bottom += 4;
	}


	for (int i = 0; i < 2; i++)
	{
		//장애물 이동 속도
		_land[i].left -= 5;
		_land[i].right -= 5;
		Hurdle[i].Hstruct.left -= 4;
		Hurdle[i].Hstruct.right -= 4;
		Hurdle[i].Vstruct.left -= 5;
		Hurdle[i].Vstruct.right -= 5;
		Hurdle[i].FireBall.left -= 7;
		Hurdle[i].FireBall.right -= 7;
		if (Hurdle[0].Vstruct.bottom < 300 && Hurdle[0].Vstruct.left < WINSIZEX)
		{
			Hurdle[0].Vstruct.top += 3;
			Hurdle[0].Vstruct.bottom += 3;
		}
		if (Hurdle[1].Vstruct.top > WINSIZEY - 300 && Hurdle[1].Vstruct.left < WINSIZEX)
		{
			Hurdle[1].Vstruct.top -= 3;
			Hurdle[1].Vstruct.bottom -= 3;
		}

		//지나간 장애물 다시 그려주기
		if (_land[0].right < 0)
		{
			_land[0] = RectMakeCenter(_land[1].right + 600, WINSIZEY - 100, RND->getInt(400) + 100, 50);
		}
		if (_land[1].right < 0)
		{
			_land[1] = RectMakeCenter(_land[0].right + 600, WINSIZEY - 100, RND->getInt(400) + 100, 50);
		}
		if (Hurdle[0].Hstruct.right < 0)
		{
			Hurdle[0].Hstruct = RectMakeCenter(Hurdle[1].Hstruct.right + 600, RND->getInt(200) + 300, RND->getInt(100) + 200, 50);
		}
		if (Hurdle[1].Hstruct.right < 0)
		{
			Hurdle[1].Hstruct = RectMakeCenter(Hurdle[0].Hstruct.right + 600, RND->getInt(200) + 300, RND->getInt(100) + 200, 50);
		}
		if (Hurdle[0].Vstruct.right < 0)
		{
			Hurdle[0].Vstruct = RectMakeLB(Hurdle[1].Vstruct.right + 600, 0, 50, 300);
		}
		if (Hurdle[1].Vstruct.right < 0)
		{
			Hurdle[1].Vstruct = RectMake(Hurdle[0].Vstruct.right + 600, WINSIZEY, 50, 300);
		}

		if (Hurdle[0].FireBall.right < 0)
		{
			Hurdle[0].FireBall = RectMakeCenter(Hurdle[1].FireBall.right + 800, RND->getInt(WINSIZEY - 300) + 200, 50, 50);
		}
		if (Hurdle[1].FireBall.right < 0)
		{
			Hurdle[1].FireBall = RectMakeCenter(Hurdle[0].FireBall.right + 800, RND->getInt(WINSIZEY - 300) + 200, 50, 50);
		}

		// 장애물 충돌
		if (collisionUp(&_rc, &Hurdle[i].Hstruct) || collisionUp(&_rc, &Hurdle[i].Vstruct) || collisionUp(&_rc, &_land[i]))
		{
			_jumpCount = 0;
		}
		if (collisionDown(&_rc, &Hurdle[i].Hstruct) || collisionDown(&_rc, &Hurdle[i].Vstruct) || collisionDown(&_rc, &_land[i]))
		{
			_jumpPower = 0;
			_jumpPower -= _gravity;
			_rc.top -= _jumpPower;
			_rc.bottom -= _jumpPower;
		}
		if (collisionRight(&_rc, &Hurdle[i].Hstruct) || collisionRight(&_rc, &Hurdle[i].Vstruct) || collisionRight(&_rc, &_land[i])) {}
		if (collisionLeft(&_rc, &Hurdle[i].Hstruct) || collisionLeft(&_rc, &Hurdle[i].Vstruct) || collisionLeft(&_rc, &_land[i])) {}
	}


	if (_rc.right < 0 || _rc.top > WINSIZEY || IntersectRect(&_temp, &_rc, &Hurdle[0].FireBall) || IntersectRect(&_temp, &_rc, &Hurdle[1].FireBall))
	{
		release();
		MessageBox(_hWnd, TEXT("Game over"), TEXT(""), MB_OK);
		PostMessage(_hWnd, WM_DESTROY, 0, 0);
	}

	int tempLeft = _rc.left;
	int tempTop = _rc.top;
	_rc = RectMake(tempLeft, tempTop, 50, 50);

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	HDC MemDC;
	HBITMAP MyBitMap, OldBitMap;
	MemDC = CreateCompatibleDC(hdc);
	MyBitMap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	OldBitMap = (HBITMAP)SelectObject(MemDC, MyBitMap);

	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	BitBlt(hdc, _rc.left, _rc.top, 50, 50, MemDC, 0, 0, SRCCOPY);

	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _land[i].left, _land[i].top, _land[i].right, _land[i].bottom);
		Rectangle(hdc, Hurdle[i].Hstruct.left, Hurdle[i].Hstruct.top, Hurdle[i].Hstruct.right, Hurdle[i].Hstruct.bottom);
		Rectangle(hdc, Hurdle[i].Vstruct.left, Hurdle[i].Vstruct.top, Hurdle[i].Vstruct.right, Hurdle[i].Vstruct.bottom);
		Rectangle(hdc, Hurdle[i].FireBall.left, Hurdle[i].FireBall.top, Hurdle[i].FireBall.right, Hurdle[i].FireBall.bottom);
		BitBlt(hdc, Hurdle[i].Vstruct.left, Hurdle[i].Vstruct.top, 50, 300, MemDC, 100 + 50 * i, 0, SRCCOPY);
	}

	for (int i = 0; i < 2; i++)
	{
		BitBlt(hdc, Hurdle[i].FireBall.left, Hurdle[i].FireBall.top, 50, 50, MemDC, 50, 0, SRCCOPY);
	}
	SelectObject(MemDC, OldBitMap);
	DeleteObject(MyBitMap);
	DeleteDC(MemDC);
}

BOOL gameStudy::collisionUp(RECT* r1, RECT* r2)
{
	if (IntersectRect(&_temp, &*r1, &*r2) && (*r1).bottom > (*r2).top && (*r1).top < (*r2).top)
	{

		int height = (*r1).bottom - (*r1).top;
		(*r1).bottom = (*r2).top;
		(*r1).top = (*r1).bottom - height;
		return TRUE;
	}
	else return FALSE;
}

BOOL gameStudy::collisionDown(RECT* r1, RECT* r2)
{
	if (IntersectRect(&_temp, &*r1, &*r2) && (*r1).bottom > (*r2).bottom && (*r1).top < (*r2).bottom)
	{
		int height = (*r1).bottom - (*r1).top;
		(*r1).top = (*r2).bottom;
		(*r1).bottom = (*r1).top + height;
		return TRUE;
	}
	else return FALSE;
}

BOOL gameStudy::collisionRight(RECT* r1, RECT* r2)
{
	if (IntersectRect(&_temp, &*r1, &*r2) && (*r1).left < (*r2).right && (*r1).right > (*r2).right)
	{
		int width = (*r1).right - (*r1).left;
		(*r1).left = (*r2).right;
		(*r1).right = (*r1).left + width;
		return TRUE;
	}
	else return FALSE;
}

BOOL gameStudy::collisionLeft(RECT* r1, RECT* r2)
{
	if (IntersectRect(&_temp, &*r1, &*r2) && (*r1).left < (*r2).left && (*r1).right > (*r2).left)
	{
		int width = (*r1).right - (*r1).left;
		(*r1).right = (*r2).left;
		(*r1).left = (*r1).right - width;
		return TRUE;
	}
	else return FALSE;
}
