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

	_rc = RectMakeCenter(WINSIZEX / 5, WINSIZEY / 2, 100, 100);

	_gravity = _jumpPower = _isJump = 0;

	for (int i = 0; i < 2; i++)
	{
		_Hstruct[i].hUp = RectMakeLT(WINSIZEX /3 + 350 * i, 0, WINSIZEX / 3 + 100 + 350 * i, WINSIZEY / 5);
		_Hstruct[i].hDown = RectMakeLT(WINSIZEX / 3 + 350 * i, WINSIZEY / 5 + 250, WINSIZEX / 3 + 100 + 350 * i, WINSIZEY - 100);
	}
	_land = RectMake(0, WINSIZEY - 100, WINSIZEX, 100);


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
		_jumpPower = 3;
		_gravity = 0.1;
		_isJump = true;
		if (!_start) _start = true;
	}

	if (_isJump)	//점프중일때
	{
		if (_rc.top < 4)
		{	
			_isJump = false;
		}
		else
		{
		_rc.top -= _jumpPower;
		_rc.bottom -= _jumpPower;
		_jumpPower -= _gravity;
		}
		if (_rc.bottom > WINSIZEY - 100)
		{
			_jumpPower = _gravity = 0;
			_isJump = true;
		}
	}
	else if (!_isJump)	//점프아닐떄 
	{
		if (_rc.top > 4)
		{
			_isJump = false;
		}
		_rc.top += _jumpPower;
		_rc.bottom += _jumpPower;
		_jumpPower += _gravity;	
		if (_rc.bottom > WINSIZEY - 100)
		{
			_jumpPower = _gravity = 0;
			_isJump = true;
		}
	}

	if (_start)
	{
		for (int i = 0; i < 2; i++)
		{
			_Hstruct[i].hUp.left -= 4;
			_Hstruct[i].hUp.right -= 4;
			_Hstruct[i].hDown.left -= 4;
			_Hstruct[i].hDown.right -= 4;

			if (_Hstruct[0].hUp.right < 0)
			{
				int randomNum = RND->getInt(300);
				int left = _Hstruct[1].hUp.right + 350;
				_Hstruct[0].hUp = RectMakeLT(left, 0, left + 100, randomNum);
				_Hstruct[0].hDown = RectMakeLT(_Hstruct[1].hUp.right + 350, randomNum + 200, left + 100, WINSIZEY - 100);
			}
			if (_Hstruct[1].hUp.right < 0)
			{
				int randomNum = RND->getInt(300);
				int left = _Hstruct[0].hUp.right + 350;
				_Hstruct[1].hUp = RectMakeLT(left, 0, left + 100, randomNum);
				_Hstruct[1].hDown = RectMakeLT(left, randomNum + 200, left + 100, WINSIZEY - 100);
			}
		}
	}
	if (IntersectRect(&_temp, &_rc, &_Hstruct[0].hUp) || IntersectRect(&_temp, &_rc, &_Hstruct[0].hDown) 
		|| IntersectRect(&_temp, &_rc, &_Hstruct[1].hUp) || IntersectRect(&_temp, &_rc, &_Hstruct[1].hDown))
	{
		_rc.right -= 4;
		_rc.left -= 4;
	}

	if (_rc.right < 0)
	{
		KillTimer(_hWnd, 1);
		MessageBox(_hWnd, "Game over", "충돌", MB_OK);
		PostMessage(_hWnd, WM_DESTROY, 0, 0);
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	HBRUSH MyBrush, OldBrush;
	MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

	SetDCBrushColor(hdc, RGB(255, 0, 0));
	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	
	SetDCBrushColor(hdc, RGB(102, 0, 0));
	Rectangle(hdc, _land.left, _land.top, _land.right, _land.bottom);
	
	SetDCBrushColor(hdc, RGB(0, 255, 0));
	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _Hstruct[i].hUp.left, _Hstruct[i].hUp.top, _Hstruct[i].hUp.right, _Hstruct[i].hUp.bottom);
		Rectangle(hdc, _Hstruct[i].hDown.left, _Hstruct[i].hDown.top, _Hstruct[i].hDown.right, _Hstruct[i].hDown.bottom);
	}
	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);
}
