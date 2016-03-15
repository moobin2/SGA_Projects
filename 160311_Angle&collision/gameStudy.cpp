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
	
	_angle = PI / 2;

	for (int i = 0; i < bulletNum; i++)
	{
		_bullet[i].isFire = false;
		_bullet[i].speed = 5.0f;
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
		_angle += PI / 180;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _angle > 0)
	{
		_angle -= PI / 180;
	}
  	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		bulletFire();
	}

	collision();
	
	bulletMove();

	_lineX = cosf(_angle) * 80 + CENTERX;
	_lineY = -sinf(_angle) * 80 + WINSIZEY - 10;

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

		_bullet[i].centerX += cosf(_bullet[i].bulletAngle) * _bullet[i].speed;
		_bullet[i].centerY += -sinf(_bullet[i].bulletAngle) * _bullet[i].speed;
		_bullet[i].rcBullet = RectMakeCenter(_bullet[i].centerX, _bullet[i].centerY, 20, 20);

		// 왼쪽 or 오른쪽 충돌했을때
		if (_bullet[i].rcBullet.left < 0)
		{
			_bullet[i].centerX = 10;
			_bullet[i].bulletAngle = PI - _bullet[i].bulletAngle;
		}
		else if (_bullet[i].rcBullet.right > WINSIZEX)
		{
			_bullet[i].centerX = WINSIZEX - 10;
			_bullet[i].bulletAngle = PI - _bullet[i].bulletAngle;
		}
		// 위 or 아래 충돌했을때
		else if (_bullet[i].rcBullet.top < 0)
		{
			_bullet[i].centerY = 10;
			_bullet[i].bulletAngle = 2 * PI - _bullet[i].bulletAngle;
		}
		else if (_bullet[i].rcBullet.bottom > WINSIZEY)
		{
			_bullet[i].centerY = WINSIZEY - 10;
			_bullet[i].bulletAngle = 2 * PI - _bullet[i].bulletAngle;
		}

		/*if (_bullet[i].centerX < 0 || _bullet[i].centerX > WINSIZEX || _bullet[i].centerY < 0 || _bullet[i].centerY > WINSIZEY)
		{
			_bullet[i].isFire = false;
		}*/

	}
}

void gameStudy::collision(void)
{
	for (int i = 0; i < bulletNum; i++)
	{
		if (!_bullet[i].isFire) continue;
		for (int j= 0; j < bulletNum; j++)
		{
			if (!_bullet[j].isFire) continue;
			if ( distance(_bullet[i].centerX, _bullet[i].centerY, _bullet[j].centerX, _bullet[j].centerY) <= 20 && i!= j)
			{
				_bullet[i].bulletAngle = atan2(_bullet[j].centerY - _bullet[i].centerY, _bullet[j].centerX - _bullet[i].centerX);
				_bullet[j].bulletAngle = atan2(_bullet[i].centerY - _bullet[j].centerY, _bullet[i].centerX - _bullet[j].centerX);
			}
		}
	}
}

float gameStudy::distance(float x1, float y1, float x2,  float y2)
{
	float distance;

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	return distance;
}
