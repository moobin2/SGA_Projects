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

	_x = WINSIZEX / 6;
	_y = WINSIZEY / 3;

	_toothState[20] = { NonClick, };
	_toothState[RND->getInt(20)] = GameAnswer;
	_isGameEnd = false;

	for (int i = 0; i < 20; i++)
	{
		if(i < 3) _toothRect[i] = RectMake(_x + 55* i, _y + 50 - 20 * i ,50, 50);
		else if( i >= 3 && i <=6) _toothRect[i] = RectMake(_x + 55 * i, _y, 50, 50);
		else if( i > 6 && i <= 9) _toothRect[i] = RectMake(_x + 55 * i, _y + 50 + 20 * (i-9), 50, 50);
		else if (i > 9 && i <= 12) _toothRect[i] = RectMake(_x + 55 * (i - 10), _y + 150 + 20 * (i - 10), 50, 50);
		else if (i > 12 && i <= 16) _toothRect[i] = RectMake(_x + 55 * (i - 10), _y + 200, 50, 50);
		else _toothRect[i] = RectMake(_x + 55 * (i - 10), _y + 150 - 20 * (i - 19), 50, 50);
	}
	_red[20] = _green[20] = _blue[20] = { 255, };
	_clickCount = 1;
	wsprintf(str, "%d번째 도전", _clickCount);

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && !_isGameEnd)
	{
		for (int i = 0; i < 20; i++)
		{
			if (PtInRect(&_toothRect[i], _ptMouse) && _toothState[i] == GameAnswer)
			{
				for (int i = 0; i < 20; i++) _toothState[i] = GameEnd;
				_isGameEnd = true;
				wsprintf(str, "%d번째에 위치를 찾았습니다.", _clickCount);
				
			}
			else if (PtInRect(&_toothRect[i], _ptMouse) && _toothState[i] != GameAnswer)
			{
				_toothState[i] = Click;
				_red[i] = RND->getInt(256);
				_green[i] = RND->getInt(256);
				_blue[i] = RND->getInt(256);
				_clickCount++;
				wsprintf(str, "%d번째 도전", _clickCount);
			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		if (_toothState[i] == Click && _toothRect[i].top + 10 < _toothRect[i].bottom && i < 10)
		{
			_toothRect[i].bottom -= 2;
		}
		else if (_toothState[i] == Click && _toothRect[i].top < _toothRect[i].bottom - 10 && i >= 10)
		{
			_toothRect[i].top += 2;
		}
	}

	if (_isGameEnd) toothMove();

	

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	for (int i = 0; i < 20; i++)
	{
		if (_toothState[i] == Click)
		{
			HBRUSH bitmap, oldbitmap;
			bitmap = CreateSolidBrush(RGB(_red[i], _green[i], _blue[i]));
			oldbitmap = (HBRUSH)SelectObject(hdc, bitmap);
			Rectangle(hdc, _toothRect[i].left, _toothRect[i].top, _toothRect[i].right, _toothRect[i].bottom);
			SelectObject(hdc, oldbitmap);
			DeleteObject(bitmap);
			
		}
		else if (_toothState[i] == GameEnd)
		{
			HBRUSH bitmap, oldbitmap;
			bitmap = CreateSolidBrush(RGB(0, 0, 0));
			oldbitmap = (HBRUSH)SelectObject(hdc, bitmap);
			Rectangle(hdc, _toothRect[i].left, _toothRect[i].top, _toothRect[i].right, _toothRect[i].bottom);
			SelectObject(hdc, oldbitmap);
			DeleteObject(bitmap);
		}
		else Rectangle(hdc, _toothRect[i].left, _toothRect[i].top, _toothRect[i].right, _toothRect[i].bottom);
	}

	if (!_isGameEnd) TextOut(hdc, CENTERX - 36, 325, str, strlen(str));
	else TextOut(hdc, CENTERX - 100, 170, str, strlen(str));

}

void gameStudy::toothMove()
{
	for (int i = 0; i < 20; i++)
	{
		if (i < 10 && _toothRect[i].top < 273)
		{
			_toothRect[i].top += 1;
			_toothRect[i].bottom += 1;
		}
		else if (i >= 10 && _toothRect[i].bottom > 377)
		{
			_toothRect[i].top -= 1;
			_toothRect[i].bottom -= 1;
		}
	}
}
