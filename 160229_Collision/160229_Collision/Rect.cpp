#include "stdafx.h"
#include "Rect.h"


BOOL Rect::impactCheck(RECT r1, RECT r2, HDC hdc)
{
	RECT temp;
	if (r1.top < r2.bottom && r1.bottom > r2.top && r1.right > r2.left && r1.left < r2.right)	// 두 렉트가 충돌했을 때
	//if(IntersectRect(&temp, &r1, &r2))
	{
		if (_nowMove == TRUE)
		{
			TextOut(hdc, 10, 10, "<< 충돌 >>", strlen("<< 충돌 >>"));
			_nowMove = FALSE;
			_rx[0] = _oldx;			//움직이는 렉트 이전 위치 돌려주고
			_ry[0] = _oldy;
			_rx[1] = _rx[2] + 30;	//작은 렉트 다른 렉트안으로 이동
			_ry[1] = _ry[2] + 30;
			return TRUE;
		}
		else
		{
			TextOut(hdc, 10, 10, "<< 충돌 >>", strlen("<< 충돌 >>"));
			_nowMove = TRUE;
			_rx[2] = _oldx;
			_ry[2] = _oldy;
			_rx[1] = _rx[0] + 30;
			_ry[1] = _ry[0] + 30;
			return FALSE;
		}
	}
	else return FALSE;
}

void Rect::printRect(HDC hdc)
{
	HBRUSH nowBrush, oldbrush;

	_rc[0] = RectMake(_rx[0], _ry[0], 100, 100);
	_rc[1] = RectMake(_rx[1], _ry[1], 20, 20);
	_rc[2] = RectMake(_rx[2], _ry[2], 100, 100);

	Rectangle(hdc, _rc[0].left, _rc[0].top, _rc[0].right, _rc[0].bottom);
	Rectangle(hdc, _rc[2].left, _rc[2].top, _rc[2].right, _rc[2].bottom);

	nowBrush = CreateSolidBrush(RGB(255, 0, 0));		//작은 렉트 빨간 브러쉬로 생성
	oldbrush = (HBRUSH)SelectObject(hdc, nowBrush);
	Rectangle(hdc, _rc[1].left, _rc[1].top, _rc[1].right, _rc[1].bottom);
	SelectObject(hdc, oldbrush);
	DeleteObject(nowBrush);

}

void Rect::MoveRect(int dir)
{
	switch (dir)
	{
	case Up:
		if (_nowMove && _rc[1].bottom < _rc[0].bottom)			// 0번 렉트 혼자 움직일때
		{
			OldPos(0);		// 움직이기 전 위치 저장
			_ry[0] -= 5;	// 좌표 이동
		}
		else if (_nowMove && _rc[1].bottom >= _rc[0].bottom)	// 0번, 1번 렉트 같이 움직일때
		{
			OldPos(0);
			_ry[0] -= 5;
			_ry[1] -= 5;
		}
		else if (!_nowMove && _rc[1].bottom < _rc[2].bottom)	// 2번 렉트 혼자 움직일때
		{
			OldPos(2);
			_ry[2] -= 5;
		}
		else if (!_nowMove && _rc[1].bottom >= _rc[2].bottom)	// 2번, 1번 렉트 같이 움직일때
		{
			OldPos(2);
			_ry[2] -= 5;
			_ry[1] -= 5;
		}
		break;
	case Down:
		if (_nowMove && (_rc[1].top > _rc[0].top))
		{	
			OldPos(0);
			_ry[0] += 5;
		}
		else if (_nowMove && (_rc[1].top <= _rc[0].top))
		{	
			OldPos(0);
			_ry[0] += 5;
			_ry[1] += 5;
		}
		else if (!_nowMove && (_rc[1].top > _rc[2].top))
		{
			OldPos(2);
			_ry[2] += 5;
		}
		else if (!_nowMove && (_rc[1].top <= _rc[2].top))
		{
			OldPos(2);
			_ry[2] += 5;
			_ry[1] += 5;
		}
		break;
	case Right:
		if (_nowMove && (_rc[1].left > _rc[0].left))
		{
			OldPos(0);
			_rx[0] += 5;
		}
		else if (_nowMove && (_rc[1].left <= _rc[0].left))
		{
			OldPos(0);
			_rx[0] += 5;
			_rx[1] += 5;
		}
		else if (!_nowMove && (_rc[1].left > _rc[2].left))
		{
			OldPos(2);
			_rx[2] += 5;
		}
		else if (!_nowMove && (_rc[1].left <= _rc[2].left))
		{
			OldPos(2);
			_rx[2] += 5;
			_rx[1] += 5;
		}
		break;
	case Left:
		if (_nowMove && (_rc[1].right < _rc[0].right))
		{
			OldPos(0);
			_rx[0] -= 5;
		}
		else if (_nowMove && (_rc[1].right >= _rc[0].right))
		{
			OldPos(0);
			_rx[0] -= 5;
			_rx[1] -= 5;
		}
		else if (!_nowMove && (_rc[1].right < _rc[2].right))
		{
			OldPos(2);
			_rx[2] -= 5;
		}
		else if (!_nowMove && (_rc[1].right >= _rc[2].right))
		{
			OldPos(2);
			_rx[2] -= 5;
			_rx[1] -= 5;
		}
		break;
	}
}

void Rect::OldPos(int num)
{
	_oldx = _rx[num];				// 움직이는 렉트 전위치 x, y 좌표 저장
	_oldy = _ry[num];
}

RECT Rect::GetRect(int num)
{
	return _rc[num];
}

Rect::Rect() : _nowMove(TRUE)		// 각각의 변수(렉트) 초기화
{
	_rx[0] = 100;
	_ry[0] = 100;
	_rx[1] = 140;
	_ry[1] = 140;
	_rx[2] = 300;
	_ry[2] = 100;
	_rc[0] = RectMake(_rx[0], _ry[0], 100, 100);
	_rc[1] = RectMake(_rx[1], _ry[1], 20, 20);
	_rc[2] = RectMake(_rx[2], _ry[2], 100, 100);
}


Rect::~Rect()
{
}
