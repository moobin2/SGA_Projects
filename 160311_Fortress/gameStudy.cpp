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

	_tank.rcTank = RectMakeCenter(100, WINSIZEY - 205, 30, 30);
	_tank.angle = 45;
	_tank.MoveBar = RectMake(253, WINSIZEY - 92, 539, 34);
	_tank.HpBar = RectMake(253, WINSIZEY - 142, 539, 34);
	_tank.move = true;
	_tank.direction = true;
	_tank.bombKinds = blackBin;
	_powerBar = RectMake(253, WINSIZEY - 42, 0, 34);
	_shotPower = 0;
	_gravity = 0.09f;
	_bombOn = false;
	_countOn = false;
	_doubleOn = false;
	_teleportOn = false;
	_gameCount = 0;
	for (int i = 0; i < 2; i++)
	{
		_bombKinds[i] = RectMake(i * 120, WINSIZEY - 30, 30, 30);
		_itemRect[i] = RectMake(i * 120, WINSIZEY-150, 30, 30);
		_tank.Bomb[i].bombMove = false;
	}
	
	return S_OK;
}

void gameStudy::release()
{
	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 2; i++)
		{
			// 폭탄선택
			if (PtInRect(&_bombKinds[i], _ptMouse))
			{
				if(i == 0) _tank.bombKinds = blackBin;
				else if (i == 1)_tank.bombKinds = redBin;
			}
			//아이템 선택
			if (PtInRect(&_itemRect[i], _ptMouse))
			{
				if (i == 0)
				{
					_doubleOn = true;
					_teleportOn = false;
				}
				else if (i == 1)
				{
					_doubleOn = false;
					_teleportOn = true;
				}
			}
		}	
	}
	// 탱크 움직임. 방향 바꾸면 각도방향도 바꿔주기. 무브바가 on 때만 이동가능
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _tank.rcTank.left > 0)
	{
		_tank.direction = false;
		if (_tank.angle < 90) _tank.angle = 180 - _tank.angle;
		if (_tank.move)
		{
			_tank.rcTank.left -= 1;
			_tank.rcTank.right -= 1;
			_tank.MoveBar.right -= 5;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _tank.rcTank.right < WINSIZEX)
	{
		_tank.direction = true;
		if (_tank.angle > 90) _tank.angle = 180 - _tank.angle;
		if (_tank.move)
		{
			_tank.rcTank.left += 1;
			_tank.rcTank.right += 1;
			_tank.MoveBar.right -= 5;
		}
	}
	//각도 조절 방향에 맞게 (위, 아래)
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if(_tank.angle <= 90) _tank.angle += 1;
		else if (_tank.angle > 90) _tank.angle -= 1;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _tank.angle > 0)
	{
		if (_tank.angle <= 90) _tank.angle -= 1;
		else if (_tank.angle > 90) _tank.angle += 1;
	}
	//포탄 발사. 스페이스 누르면서 파워조절. 
	if (KEYMANAGER->isStayKeyDown(VK_SPACE) )
	{
		if (_powerBar.right < WINSIZEX - 8)
		{
			_powerBar.right += 3;
			_shotPower += 0.08f;

		}
		else if (_powerBar.right >= WINSIZEX - 8) _powerBar.right = WINSIZEX - 8;
	}
	//스페이스 up일때 포탄 발사
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE) && !_bombOn)
	{
		BombFire(_tank.bombKinds);
		
		_powerBar.right = _powerBar.left;
		_tank.MoveBar.right = WINSIZEX - 8;
		_tank.move = true;
	}

	BombMove();

	for (int i = 0; i < 2; i++)
	{
		if (!_tank.Bomb[i].bombMove) continue;
		if (_tank.Bomb[i].rcBomb.bottom >= 420 || _tank.Bomb[i].rcBomb.left > WINSIZEX)
		{
			_tank.Bomb[i].bombMove = false;
			if (_doubleOn)
			{
				_doubleOn = false;
				BombFire(_tank.bombKinds);
			}
			_shotPower = 0;
		}
	}
	
	if (_tank.MoveBar.right - _tank.MoveBar.left <= 5) _tank.move = false;

	_tank.angleX = cosf(_tank.angle * PI / 180) * 60 + 75;
	_tank.angleY = -sinf(_tank.angle * PI / 180) * 60 + WINSIZEY - 75;
	_tank.cannonX = cosf(_tank.angle * PI / 180) * 40 + (_tank.rcTank.right - _tank.rcTank.left) / 2 + _tank.rcTank.left;
	_tank.cannonY = -sinf(_tank.angle * PI / 180) * 40 + (_tank.rcTank.bottom - _tank.rcTank.top) / 2 + _tank.rcTank.top;
	_tank.tankCenter = { (_tank.rcTank.right - _tank.rcTank.left) / 2 + _tank.rcTank.left , (_tank.rcTank.bottom - _tank.rcTank.top) / 2 + _tank.rcTank.top };
	/*if(_countOn) _gameCount++;

	if (_gameCount % 80 == 0)
	{
		_gameCount = 0;
		_shotPower = 0;
		_powerBar.right = _powerBar.left;
		_tank.MoveBar.right = WINSIZEX - 5;
		_countOn = false;
	}*/
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
#pragma comment(lib, "msimg32.lib")
	//배경 이미지
	HDC memDC = CreateCompatibleDC(hdc);
	HBITMAP background = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, background);
	BitBlt(hdc, 0, 0, 800, 400, memDC, 0, 80, SRCCOPY);
	DeleteObject(SelectObject(memDC, oldBitmap));

	//오브젝트 이미지
	HBITMAP bitmap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	oldBitmap = (HBITMAP)SelectObject(memDC, bitmap);

	//기본 인터페이스
	HBRUSH brush = CreateSolidBrush(RGB(51, 102, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
	Rectangle(hdc, 0, WINSIZEY - 150, WINSIZEX, WINSIZEY);
	DeleteObject(SelectObject(hdc, oldBrush));
	FillRect(hdc, &RectMake(170, WINSIZEY - 45, WINSIZEX - 175, 40), (HBRUSH)GetStockObject(BLACK_BRUSH));
	FillRect(hdc, &RectMake(170, WINSIZEY - 95, WINSIZEX - 175, 40), (HBRUSH)GetStockObject(BLACK_BRUSH));
	FillRect(hdc, &RectMake(170, WINSIZEY - 145, WINSIZEX - 175, 40), (HBRUSH)GetStockObject(BLACK_BRUSH));

	//각도기 & 땅
	TransparentBlt(hdc, 0, WINSIZEY - 150, 150, 131, memDC, 0, 33, 150, 131, RGB(255, 0, 255));
	TransparentBlt(hdc, 0, WINSIZEY - 226, 800, 76, memDC, 0, 165, 600, 76, RGB(255, 0, 255));

	HPEN anglePen = CreatePen(PS_DOT, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, anglePen);
	//각도 출력
	LineMake(hdc, 75, WINSIZEY - 75, _tank.angleX, _tank.angleY);
	LineMake(hdc, (_tank.rcTank.right - _tank.rcTank.left) / 2 + _tank.rcTank.left, (_tank.rcTank.bottom - _tank.rcTank.top) / 2 + _tank.rcTank.top, _tank.cannonX, _tank.cannonY);
	DeleteObject(SelectObject(hdc, oldPen));

	//플레이어 탱크
	//Rectangle(hdc, _tank.rcTank.left, _tank.rcTank.top, _tank.rcTank.right, _tank.rcTank.bottom);
	if(!_tank.direction) TransparentBlt(hdc, _tank.rcTank.left, _tank.rcTank.top, 33, 31, memDC, 0, 0, 33, 31, RGB(255, 0, 255));
	else TransparentBlt(hdc, _tank.rcTank.left, _tank.rcTank.top, 33, 31, memDC, 33, 0, 33, 31, RGB(255, 0, 255));

	//파워바 출력
	HBRUSH powerBrush = CreateSolidBrush(RGB(255, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, powerBrush);
	FillRect(hdc, &_powerBar, powerBrush);
	DeleteObject(SelectObject(hdc, oldBrush));
	TransparentBlt(hdc, 176, WINSIZEY - 40, 70, 30, memDC, 178, 8, 47, 8, RGB(255, 0, 255));

	//무브바 출력
	HBRUSH moveBrush = CreateSolidBrush(RGB(255, 204, 51));
	oldBrush = (HBRUSH)SelectObject(hdc, moveBrush);
	FillRect(hdc, &_tank.MoveBar, moveBrush);
	DeleteObject(SelectObject(hdc, oldBrush));
	TransparentBlt(hdc, 176, WINSIZEY - 90, 70, 30, memDC, 178, 16, 47, 8, RGB(255, 0, 255));

	//체력바 출력
	HBRUSH HpBrush = CreateSolidBrush(RGB(134, 235, 127));
	oldBrush = (HBRUSH)SelectObject(hdc, HpBrush);
	FillRect(hdc, &_tank.HpBar, HpBrush);
	DeleteObject(SelectObject(hdc, oldBrush));
	TransparentBlt(hdc, 176, WINSIZEY - 140, 70, 30, memDC, 178, 0, 47 , 8, RGB(255, 0, 255));

	//폭탄 선택박스 
	HBRUSH selecBrush = CreateSolidBrush(RGB(255, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, selecBrush);
	if (_tank.bombKinds == blackBin)
	{
		Rectangle(hdc, _bombKinds[0].left, _bombKinds[0].top, _bombKinds[0].right, _bombKinds[0].bottom);
		DeleteObject(SelectObject(hdc, oldBrush));
		HBRUSH unselecBrush = CreateSolidBrush(RGB(102, 102, 102));
		oldBrush = (HBRUSH)SelectObject(hdc, unselecBrush);
		Rectangle(hdc, _bombKinds[1].left, _bombKinds[1].top, _bombKinds[1].right, _bombKinds[1].bottom);
		DeleteObject(SelectObject(hdc, oldBrush));
	}
	else if (_tank.bombKinds = redBin)
	{
		Rectangle(hdc, _bombKinds[1].left, _bombKinds[1].top, _bombKinds[1].right, _bombKinds[1].bottom);
		DeleteObject(SelectObject(hdc, oldBrush));
		HBRUSH unselecBrush = CreateSolidBrush(RGB(102, 102, 102));
		oldBrush = (HBRUSH)SelectObject(hdc, unselecBrush);
		Rectangle(hdc, _bombKinds[0].left, _bombKinds[0].top, _bombKinds[0].right, _bombKinds[0].bottom);
		DeleteObject(SelectObject(hdc, oldBrush));
	}
	TransparentBlt(hdc, _bombKinds[0].left + 5, _bombKinds[0].top + 5, 20, 20, memDC, 86, 0, 20, 20, RGB(255, 0, 255));
	TransparentBlt(hdc, _bombKinds[1].left + 6, _bombKinds[1].top + 7, 20, 17, memDC, 106, 0, 20, 17, RGB(255, 0, 255));
	
	//아이템박스
	for (int i = 0; i < 2; i++)
	{
		Rectangle(hdc, _itemRect[i].left, _itemRect[i].top, _itemRect[i].right, _itemRect[i].bottom);
	}
	if(!_doubleOn) TransparentBlt(hdc, _itemRect[0].left + 1, _itemRect[0].top + 1, 28, 28, memDC, 126, 0, 26, 24, RGB(255, 0, 255));
	else if(_doubleOn ) TransparentBlt(hdc, _itemRect[0].left + 1, _itemRect[0].top + 1, 28, 28, memDC, 126, 24, 26, 24, RGB(255, 0, 255));

	if(!_teleportOn) TransparentBlt(hdc, _itemRect[1].left + 1, _itemRect[1].top + 1, 28, 28, memDC, 152, 0, 26, 24, RGB(255, 0, 255));
	else if (_teleportOn) TransparentBlt(hdc, _itemRect[1].left + 1, _itemRect[1].top + 1, 28, 28, memDC, 152, 24, 26, 24, RGB(255, 0, 255));

	//바람바 출력
	Rectangle(hdc, 30, WINSIZEY - 30, 120, WINSIZEY);


	//폭탄 출력
	if (_tank.Bomb[0].bombMove)
	{
		//Ellipse(hdc, _tank.Bomb[0].rcBomb.left, _tank.Bomb[0].rcBomb.top, _tank.Bomb[0].rcBomb.right, _tank.Bomb[0].rcBomb.bottom);
		TransparentBlt(hdc, _tank.Bomb[0].rcBomb.left, _tank.Bomb[0].rcBomb.top - 5, 20, 20, memDC, 66, 0, 20, 20, RGB(255, 0, 255));
	}
	if (_tank.Bomb[1].bombMove)
	{
		//Ellipse(hdc, _tank.Bomb[1].rcBomb.left, _tank.Bomb[1].rcBomb.top, _tank.Bomb[1].rcBomb.right, _tank.Bomb[1].rcBomb.bottom);
		TransparentBlt(hdc, _tank.Bomb[1].rcBomb.left, _tank.Bomb[1].rcBomb.top - 3, 14, 14, memDC, 66, 20, 14, 14, RGB(255, 0, 255));
	}

	DeleteObject(SelectObject(memDC, oldBitmap));
	DeleteDC(memDC);
}

void gameStudy::BombFire(int kinds)
{
	//폭탄 생성하고 폭탄 구조체 안의 변수들을 저장하자
	_tank.Bomb[kinds].bombMove = true;
	_tank.Bomb[kinds].rcBomb = RectMakeCenter(cosf(_tank.angle * PI / 180) * 50 + _tank.tankCenter.x, -sinf(_tank.angle * PI / 180) * 50 + _tank.tankCenter.y, 17 - 7 * kinds, 17 - 7 * kinds);
	_tank.Bomb[kinds].bombCenterX = (_tank.Bomb[kinds].rcBomb.right - _tank.Bomb[kinds].rcBomb.left) / 2 + _tank.Bomb[kinds].rcBomb.left;
	_tank.Bomb[kinds].bombCenterY = (_tank.Bomb[kinds].rcBomb.bottom - _tank.Bomb[kinds].rcBomb.top) / 2 + _tank.Bomb[kinds].rcBomb.top;
	_tank.Bomb[kinds].angle = _tank.angle;
	_tank.Bomb[kinds].speed = _shotPower;
	_tank.Bomb[kinds].powerX = cosf(_tank.Bomb[kinds].angle * PI / 180) * _tank.Bomb[kinds].speed;
	_tank.Bomb[kinds].powerY = -sinf(_tank.Bomb[kinds].angle * PI / 180) * _tank.Bomb[kinds].speed;
}

void gameStudy::BombMove(void)
{
	//x축은 등속도 , y축은 등가속도 운동
	for (int i = 0; i < 2; i++)
	{
		if (!_tank.Bomb[i].bombMove) continue;
		_tank.Bomb[i].bombCenterX += _tank.Bomb[i].powerX;
		_tank.Bomb[i].bombCenterY += _tank.Bomb[i].powerY;
		_tank.Bomb[i].powerY += _gravity;
		_tank.Bomb[i].rcBomb = RectMakeCenter(_tank.Bomb[i].bombCenterX, _tank.Bomb[i].bombCenterY, 17 - 7 * i, 17 - 7 * i);
	}
}


