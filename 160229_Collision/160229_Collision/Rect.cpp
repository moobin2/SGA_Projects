#include "stdafx.h"
#include "Rect.h"


BOOL Rect::impactCheck(RECT r1, RECT r2, HDC hdc)
{
	RECT temp;
	if (r1.top < r2.bottom && r1.bottom > r2.top && r1.right > r2.left && r1.left < r2.right)	// �� ��Ʈ�� �浹���� ��
	//if(IntersectRect(&temp, &r1, &r2))
	{
		if (_nowMove == TRUE)
		{
			TextOut(hdc, 10, 10, "<< �浹 >>", strlen("<< �浹 >>"));
			_nowMove = FALSE;
			_rx[0] = _oldx;			//�����̴� ��Ʈ ���� ��ġ �����ְ�
			_ry[0] = _oldy;
			_rx[1] = _rx[2] + 30;	//���� ��Ʈ �ٸ� ��Ʈ������ �̵�
			_ry[1] = _ry[2] + 30;
			return TRUE;
		}
		else
		{
			TextOut(hdc, 10, 10, "<< �浹 >>", strlen("<< �浹 >>"));
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

	nowBrush = CreateSolidBrush(RGB(255, 0, 0));		//���� ��Ʈ ���� �귯���� ����
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
		if (_nowMove && _rc[1].bottom < _rc[0].bottom)			// 0�� ��Ʈ ȥ�� �����϶�
		{
			OldPos(0);		// �����̱� �� ��ġ ����
			_ry[0] -= 5;	// ��ǥ �̵�
		}
		else if (_nowMove && _rc[1].bottom >= _rc[0].bottom)	// 0��, 1�� ��Ʈ ���� �����϶�
		{
			OldPos(0);
			_ry[0] -= 5;
			_ry[1] -= 5;
		}
		else if (!_nowMove && _rc[1].bottom < _rc[2].bottom)	// 2�� ��Ʈ ȥ�� �����϶�
		{
			OldPos(2);
			_ry[2] -= 5;
		}
		else if (!_nowMove && _rc[1].bottom >= _rc[2].bottom)	// 2��, 1�� ��Ʈ ���� �����϶�
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
	_oldx = _rx[num];				// �����̴� ��Ʈ ����ġ x, y ��ǥ ����
	_oldy = _ry[num];
}

RECT Rect::GetRect(int num)
{
	return _rc[num];
}

Rect::Rect() : _nowMove(TRUE)		// ������ ����(��Ʈ) �ʱ�ȭ
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
