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
	
	_ellipse = RectMakeCenter(CENTERX, WINSIZEY - 10, 100, 100);
	
	_angle = 90.0f;

	for (int i = 0; i < bulletNum; i++)
	{
		_bullet[i].isFire = false;
		_bullet[i].speed = 3.0f;
		_bullet[i].bitmapNumber = RND->getInt(3);
	}

	return S_OK;
}

void gameStudy::release()
{
	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _angle < 180)
	{
		_angle += 1.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _angle > 0)
	{
		_angle -= 1.0f;
	}
  	if (KEYMANAGER->isStayKeyDown(VK_SPACE))
	{
		bulletFire();
	}

	bulletMove();

	_lineX = cosf(_angle * PI / 180) * 80 + CENTERX;
	_lineY = -sinf(_angle * PI / 180) * 80 + WINSIZEY - 10;

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
#pragma comment(lib, "msimg32.lib")
	HDC memDC;
	HBITMAP bitmap, oldbitmap;
	HPEN pen, oldpen;

	memDC = CreateCompatibleDC(hdc);
	pen = CreatePen(PS_SOLID, 15, RGB(255, 0, 0));
	oldpen = (HPEN)SelectObject(hdc, pen);
	MoveToEx(hdc, _lineX, _lineY, NULL);
	LineTo(hdc, CENTERX, WINSIZEY - 10);
	SelectObject(hdc, oldpen);
	DeleteObject(pen);
	bitmap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	oldbitmap = (HBITMAP)SelectObject(memDC, bitmap);
	Ellipse(hdc, _ellipse.left, _ellipse.top, _ellipse.right, _ellipse.bottom);

	for (int i = 0; i < bulletNum; i++)
	{
		if (!_bullet[i].isFire) continue;
		Ellipse(hdc, _bullet[i].rcBullet.left, _bullet[i].rcBullet.top, _bullet[i].rcBullet.right, _bullet[i].rcBullet.bottom);
		TransparentBlt(hdc, _bullet[i].rcBullet.left, _bullet[i].rcBullet.top, 20, 20, memDC, 20 * _bullet[i].bitmapNumber, 0, 20, 20, RGB(255, 0, 255));
	}
	DeleteObject(SelectObject(memDC, oldbitmap));
	DeleteDC(memDC);

	char str[128];
	char str1[128];
	sprintf_s(str, "X: %.5f, Y: %.5f, A: %.5f", _bullet[0].centerX, _bullet[0].centerY, _bullet[0].bulletAngle);
	sprintf_s(str1, "X: %.5f, Y: %.5f, A: %.5f", _bullet[1].centerX, _bullet[1].centerY, _bullet[1].bulletAngle);
	TextOut(hdc, 10, 10, str, strlen(str));
	TextOut(hdc, 10, 30, str1, strlen(str1));

}

void gameStudy::bulletFire(void)
{
	for (int i = 0; i < bulletNum; i++)
	{
		if (_bullet[i].isFire) continue;
		_bullet[i].isFire = true;
		_bullet[i].centerX = _lineX;
		_bullet[i].centerY = _lineY;
		_bullet[i].bulletAngle = _angle;
		_bullet[i].rcBullet = RectMakeCenter(_bullet[i].centerX, _bullet[i].centerY, 20, 20);
		break;
	}
}

void gameStudy::bulletMove(void)
{
	for (int i = 0; i < bulletNum; i++)
	{
		if (!_bullet[i].isFire) continue;

		_bullet[i].centerX += cosf(_bullet[i].bulletAngle * PI / 180) * _bullet[i].speed;
		_bullet[i].centerY += -sinf(_bullet[i].bulletAngle * PI / 180) * _bullet[i].speed;
		_bullet[i].rcBullet = RectMakeCenter(_bullet[i].centerX, _bullet[i].centerY, 20, 20);

		// 왼쪽 or 오른쪽 충돌했을때
		if (_bullet[i].rcBullet.left < 0)
		{
			_bullet[i].centerX = 10;
			_bullet[i].bulletAngle = 180 - _bullet[i].bulletAngle;
		}
		else if (_bullet[i].rcBullet.right > WINSIZEX)
		{
			_bullet[i].centerX = WINSIZEX - 10;
			_bullet[i].bulletAngle = 180 - _bullet[i].bulletAngle;
		}
		// 위 or 아래 충돌했을때
		else if (_bullet[i].rcBullet.top < 0)
		{
			_bullet[i].centerY = 10;
			_bullet[i].bulletAngle = 360 - _bullet[i].bulletAngle;
		}
		else if (_bullet[i].rcBullet.bottom > WINSIZEY)
		{
			_bullet[i].centerY = WINSIZEY - 10;
			_bullet[i].bulletAngle = 360 - _bullet[i].bulletAngle;
		}

		/*if (_bullet[i].centerX < 0 || _bullet[i].centerX > WINSIZEX || _bullet[i].centerY < 0 || _bullet[i].centerY > WINSIZEY)
		{
			_bullet[i].isFire = false;
		}*/

	}
}
