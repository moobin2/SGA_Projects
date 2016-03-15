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
	_xMyPos = WINSIZEX / 6;
	_yMyPos = CENTERY;
	for (int i = 0; i < 2; i++)
	{
		_player[i] = RectMakeCenter(_xMyPos + 550 * i, _yMyPos, 50, 70);
		_HPbar[i] = RectMakeCenter(_xMyPos + 65 + 400 * i	, CENTERY / 6, 300, 50);
		_red[i] = 0;
		_green[i] = 255;
		_blue[i] = 0;
	}
	_xComPos = (_player[com].right - _player[com].left) / 2 + _player[com].left;
	_yComPos = (_player[com].bottom - _player[com].top) / 2 + _player[com].top;
	_comMove = Up;
	_missileCount = _comMissileCount = 0;
	return S_OK;
}

void gameStudy::release()
{
	gameNode::release();
}

void gameStudy::update()
{

	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))
	{
		shotMissile(me);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if(_yMyPos > 150) _yMyPos -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if(_yMyPos < WINSIZEY - 50) _yMyPos += 3;
	}

	ComMove();
	shotMissile(com);
	if (_missileCount > 0 || _comMissileCount > 0) missileMove();

	if (Collision(me))
	{
		_HPbar[com].left += 10;				//»¡ 255, 0, 0  ³ë 255 228 0 ³ì 0 255 0
		if (_HPbar[com].right - _HPbar[com].left > 150)
		{
			_red[com] += 17;
			_green[com] -= 2;
		}
		else
		{
			_green[com] -= 15;
		}
	}
	else if (Collision(com))
	{
		_HPbar[me].right -= 10;
		if (_HPbar[me].right - _HPbar[me].left > 150)
		{
			_red[me] += 17;
			_green[me] -= 2;
		}
		else
		{
			_green[me] -= 15;
		}
	}
	outOfMissile();

	for (int i = 0; i < 2; i++)
	{
		if (_HPbar[i].right - _HPbar[i].left < 10)
		{
			release();
			PostMessage(_hWnd, WM_DESTROY, 0, 0);
		}
	}

	_player[me] = RectMakeCenter(_xMyPos, _yMyPos, 30, 70);
	_player[com] = RectMakeCenter(_xComPos, _yComPos, 30, 70);
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
#pragma comment(lib, "msimg32.lib")
	HDC MemDC;
	HBITMAP MyBitMap, OldBitMap;
	HBRUSH bitmap, oldbitmap;

	MemDC = CreateCompatibleDC(hdc);
	MyBitMap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	OldBitMap = (HBITMAP)SelectObject(MemDC, MyBitMap);

	BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, MemDC, 0, 0, SRCCOPY);

	for (int i = 0; i < 2; i++)
	{
		bitmap = CreateSolidBrush(RGB(_red[i], _green[i], _blue[i]));
		oldbitmap = (HBRUSH)SelectObject(hdc, bitmap);
		Rectangle(hdc, _HPbar[i].left, _HPbar[i].top, _HPbar[i].right, _HPbar[i].bottom);
		SelectObject(hdc, oldbitmap);
		DeleteObject(bitmap);
	}
	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _player[i].left, _player[i].top, _player[i].right, _player[i].bottom);
		TransparentBlt(hdc, _player[i].left - 15, _player[i].top - 15 , 100, 100, MemDC, 800, i * 100, 100, 100, RGB(255, 0, 255));
	}
	for (int i = 0; i < _missileCount; i++)
	{
		Rectangle(hdc, _vMissile[i].left, _vMissile[i].top, _vMissile[i].right, _vMissile[i].bottom);
		TransparentBlt(hdc, _vMissile[i].left - 15, _vMissile[i].top, 30, 10, MemDC, 0, 600, 30, 10, RGB(255, 0, 255));
	}
	for (int i = 0; i < _comMissileCount; i++)
	{
		Rectangle(hdc, _vComMissile[i].left, _vComMissile[i].top, _vComMissile[i].right, _vComMissile[i].bottom);
		TransparentBlt(hdc, _vComMissile[i].left, _vComMissile[i].top, 30, 10, MemDC, 30, 600, 30, 10, RGB(255, 0, 255));
	}
	SelectObject(MemDC, OldBitMap);
	DeleteObject(MyBitMap);
	DeleteDC(MemDC);
}

void gameStudy::ComMove(void)
{
	if (_comMove == Up)
	{
		if (_yComPos > 150) _yComPos -= 3;
		else _comMove = Down;
	}
	else if (_comMove ==  Down)
	{
		if (_yComPos < WINSIZEY - 50) _yComPos += 3;
		else _comMove = Up;
	}
}

void gameStudy::shotMissile(int player)
{
	int _pCenterY;
	if (player == me)
	{
		_pCenterY = (_player[me].bottom - _player[me].top) / 2 + _player[me].top;
		if (_missileCount == 0)
		{
			_vMissile.push_back(RectMakeCenter(_player[me].right + 10, _pCenterY, 15, 10));
			_missileCount++;
		}
		else if (_missileCount > 0 && _vMissile[_missileCount-1].left > _player[me].right + 35)
		{
			_vMissile.push_back(RectMakeCenter(_player[me].right + 10, _pCenterY, 15, 10));
			_missileCount++;
		}
	}
	else if (player == com)
	{
		_pCenterY = (_player[com].bottom - _player[com].top) / 2 + _player[com].top;
		if (_comMissileCount == 0)
		{
			_vComMissile.push_back(RectMakeCenter(_player[com].left - 25, _pCenterY, 15, 10));
			_comMissileCount++;
		}
		else if (_comMissileCount > 0 && _vComMissile[_comMissileCount - 1].right < _player[com].left - 80)
		{
			_vComMissile.push_back(RectMakeCenter(_player[com].left - 25, _pCenterY, 15, 10));
			_comMissileCount++;
		}
	}
}

void gameStudy::missileMove(void)
{
	for (int i = 0; i < _missileCount; i++)
	{
		_vMissile[i].left += 3;
		_vMissile[i].right += 3;
	}
	for (int i = 0; i < _comMissileCount; i++)
	{
		_vComMissile[i].left -= 3;
		_vComMissile[i].right -= 3;
	}
}

void gameStudy::outOfMissile(void)
{
	int i = 0;
	for (_viMissile = _vMissile.begin(); _viMissile != _vMissile.end(); ++_viMissile, ++i)
	{
		if (_vMissile[i].left > WINSIZEX)
		{
			_viMissile = _vMissile.erase(_viMissile);
			_missileCount--;
			break;
		}
	}

	i = 0;
	for (_viComMissile = _vComMissile.begin(); _viComMissile != _vComMissile.end(); ++_viComMissile , ++i)
	{
		if (_vComMissile[i].right < 0)
		{
			_viComMissile = _vComMissile.erase(_viComMissile);
			_comMissileCount--;
			break;
		}
	}
}

BOOL gameStudy::Collision(int player)
{
	RECT temp1;
	if (player == me)
	{
		for (_viMissile = _vMissile.begin(); _viMissile != _vMissile.end(); ++_viMissile)
		{
			RECT tempWall = RectMake((*_viMissile).left, (*_viMissile).top, 15, 10);
			if (IntersectRect(&temp1, &_player[com], &tempWall))
			{
				_viMissile = _vMissile.erase(_viMissile);
				_missileCount--;
				return true;
			}
		}
	}
	else if (player == com)
	{

		for (_viComMissile = _vComMissile.begin(); _viComMissile != _vComMissile.end(); ++_viComMissile)
		{
			RECT tempWall = RectMake((*_viComMissile).left, (*_viComMissile).top, 15, 10);
			if (IntersectRect(&temp1, &_player[me], &tempWall))
			{
				_viComMissile = _vComMissile.erase(_viComMissile);
				_comMissileCount--;
				return true;
			}
		}
	}
	return false;
}

