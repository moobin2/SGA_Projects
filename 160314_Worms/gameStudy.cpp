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

//	ZeroMemory(_Worms, sizeof(tagWorms));
//	ZeroMemory(_comWorms, sizeof(tagWorms));

	for (int i = 0; i < WormsNum; ++i)
	{
		_Worms[i].move = false;
		_comWorms[i].move = false;
	}

	for (int i = 0; i < 4; i++)
	{
		_Worms[i].CenterX = WINSIZEX / 5;
		_Worms[i].CenterY = CENTERY + i * 30;
		_Worms[i].move = true;
		_comWorms[i].CenterX = WINSIZEX / 5 * 4;
		_comWorms[i].CenterY = CENTERY + i * 20;
		_comWorms[i].move = true;
	}
	
	_angle[0] = 0.0f;
	_speed[0] = 3.0f;
	_angle[1] = RND->getFromFloatTo(2.0, 3.0);
	_speed[1] = 3.0f;

	_itemBox[addBody].CenterX = RND->getFromIntTo(100, 200);
	_itemBox[addBody].CenterY = RND->getFromIntTo(100, 200);
	_itemBox[addBody].screenOn = true;
	_itemBox[destroy].CenterX = RND->getFromIntTo(300, 400);
	_itemBox[destroy].CenterY = RND->getFromIntTo(400, 500);
	_itemBox[destroy].screenOn = true;
	_gameCount = 0;

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
		_angle[0] += 0.08f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_angle[0] -= 0.08f;
	}

	CollisionItemBox();
	moveWorms();
	Collision();

	_Worms[0].CenterX += cosf(_angle[0]) * _speed[0];
	_Worms[0].CenterY += -sinf(_angle[0]) * _speed[0];
	_comWorms[0].CenterX += cosf(_angle[1]) * _speed[1];
	_comWorms[0].CenterY += -sinf(_angle[1]) * _speed[1];

	_gameCount++;
	_pointCount++;

	//2초가 지나면 카운트 초기화 하고 컴퓨터 속도 & 꼬리 ++;
	if (_gameCount % 150 == 0)
	{
		_gameCount = 0;
		_speed[1] += 0.8f;
		CreatComTails();
	}
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
#pragma comment(lib, "msimg32.lib")

	HDC memDC = CreateCompatibleDC(hdc);
	HBITMAP backBitmap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, backBitmap);
	TransparentBlt(hdc, 0, 0, 800, 600, memDC, 0, 0, 790, 474, RGB(255, 0, 255));
	DeleteObject(SelectObject(memDC, backBitmap));

	HBITMAP WormBitmap = LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
	oldBitmap = (HBITMAP)SelectObject(memDC, WormBitmap);

	for (int i = 1; i < WormsNum; i++)
	{
		if (!_Worms[i].move) continue;
		TransparentBlt(hdc, _Worms[i].CenterX - 20, _Worms[i].CenterY - 20, 40, 40, memDC, 0, 57, 66, 57, RGB(255, 0, 255));
	}
	if (_itemBox[addBody].screenOn) TransparentBlt(hdc, _itemBox[addBody].CenterX - 15, _itemBox[addBody].CenterY - 15, 30, 30, memDC, 132, 0, 30, 27, RGB(255, 0, 255));
	if (_itemBox[destroy].screenOn) TransparentBlt(hdc, _itemBox[destroy].CenterX - 15, _itemBox[destroy].CenterY - 15, 30, 30, memDC, 132, 27, 30, 36, RGB(255, 0, 255));

	for (int i = 1; i < WormsNum; i++)
	{
		if (!_comWorms[i].move) continue;
		TransparentBlt(hdc, _comWorms[i].CenterX - 20, _comWorms[i].CenterY - 20, 40, 40, memDC, 66, 57, 66, 57, RGB(255, 0, 255));
	}

	TransparentBlt(hdc, _comWorms[0].CenterX - 30, _comWorms[0].CenterY - 30, 60, 60, memDC, 66, 0, 66, 57, RGB(255, 0, 255));
	TransparentBlt(hdc, _Worms[0].CenterX - 30, _Worms[0].CenterY - 30, 60, 60, memDC, 0, 0, 66, 57, RGB(255, 0, 255));
	DeleteObject(SelectObject(memDC, WormBitmap));
	DeleteDC(memDC);
}

//두점사이의 거리 구해라
float gameStudy::getDistance(float x1, float y1, float x2, float y2)
{
	float distance = sqrtf(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	return distance;
}

float gameStudy::getAngle(float x1, float y1, float x2, float y2)
{
	//두 점사이의 각도 구해라
	float x = x2 - x1;
	float y = y2 - y1;

	float d = sqrtf(x * x + y * y);
	float angle = acosf(x / d);

	//각도가 180보다 크면 180보다 작게 변환 
	if (y > 0)
	{
		angle = PI * 2 - angle;
		if (angle >= PI * 2) angle -= PI * 2;
	}
	return angle;
}

void gameStudy::moveWorms(void)
{
	for (int i = 1; i < WormsNum; i++)
	{
		if (!_Worms[i].move) continue;
		// 거리가 30보다 커지면 
		if (getDistance(_Worms[i].CenterX, _Worms[i].CenterY, _Worms[i - 1].CenterX, _Worms[i - 1].CenterY) >= 30)
		{
			// 두 원 사이의 각도 구하고
			float angle = getAngle(_Worms[i].CenterX, _Worms[i].CenterY, _Worms[i - 1].CenterX, _Worms[i - 1].CenterY);
			// 그 각도만큼 이동해라.
			_Worms[i].CenterX += cosf(angle) * _speed[0];
			_Worms[i].CenterY += -sinf(angle) * _speed[0];
		}
	}
	for (int i = 1; i < WormsNum; i++)
	{
		if (!_comWorms[i].move) continue;
		// 거리가 30보다 커지면 
		if (getDistance(_comWorms[i].CenterX, _comWorms[i].CenterY, _comWorms[i - 1].CenterX, _comWorms[i - 1].CenterY) >= 30)
		{
			// 두 원 사이의 각도 구하고
			float angle = getAngle(_comWorms[i].CenterX, _comWorms[i].CenterY, _comWorms[i - 1].CenterX, _comWorms[i - 1].CenterY);
			// 그 각도만큼 이동해라.
			_comWorms[i].CenterX += cosf(angle) * _speed[1];
			_comWorms[i].CenterY += -sinf(angle) * _speed[1];
		}
	}

	// 벽 충돌 튀기기 (본인케릭)
	if (_Worms[0].CenterX + 10 >= WINSIZEX - 50)
	{
		_Worms[0].CenterX = WINSIZEX - 60;
		_angle[0] = PI - _angle[0];
	}
	else if (_Worms[0].CenterX - 10 <= 50)
	{
		_Worms[0].CenterX = 60;
		_angle[0] = PI - _angle[0];
	}
	else if (_Worms[0].CenterY - 10 <= 50)
	{
		_Worms[0].CenterY = 60;
		_angle[0] = 2 * PI - _angle[0];
	}
	else if (_Worms[0].CenterY + 10 >= WINSIZEY - 50)
	{
		_Worms[0].CenterY = WINSIZEY - 60;
		_angle[0] = 2 * PI - _angle[0];
	}

	// 벽 충돌 튀기기 (상대케릭)
	if (_comWorms[0].CenterX + 10 >= WINSIZEX - 50)
	{
		_comWorms[0].CenterX = WINSIZEX - 60;
		_angle[1] = PI - _angle[1];
	}
	else if (_comWorms[0].CenterX - 10 <= 50)
	{
		_comWorms[0].CenterX = 60;
		_angle[1] = PI - _angle[1];
	}
	else if (_comWorms[0].CenterY - 10 <= 50)
	{
		_comWorms[0].CenterY = 60;
		_angle[1] = 2 * PI - _angle[1];
	}
	else if (_comWorms[0].CenterY + 10 >= WINSIZEY - 50)
	{
		_comWorms[0].CenterY = WINSIZEY - 60;
		_angle[1] = 2 * PI - _angle[1];
	}
}

void gameStudy::CollisionItemBox(void)
{
	// 아이템박스 충돌하면 해당함수 실행하고 다른위치에 재생성
	if (_itemBox[addBody].screenOn && getDistance(_itemBox[addBody].CenterX, _itemBox[addBody].CenterY, _Worms[0].CenterX, _Worms[0].CenterY) < 30)
	{
		_itemBox[addBody].screenOn = false;
		CreatTails();
	}
	else if (!_itemBox[addBody].screenOn)
	{
		_itemBox[addBody].screenOn = true;
		_itemBox[addBody].CenterX = RND->getFromIntTo(100, WINSIZEX - 100);
		_itemBox[addBody].CenterY = RND->getFromIntTo(100, WINSIZEY - 100);
	}
	else if (_itemBox[destroy].screenOn && getDistance(_itemBox[destroy].CenterX, _itemBox[destroy].CenterY, _Worms[0].CenterX, _Worms[0].CenterY) < 30)
	{
		_itemBox[destroy].screenOn = false;
		DestroyTails();
	}
	else if (!_itemBox[destroy].screenOn)
	{
		_itemBox[destroy].screenOn = true;
		_itemBox[destroy].CenterX = RND->getFromIntTo(100, WINSIZEX - 100);
		_itemBox[destroy].CenterY = RND->getFromIntTo(100, WINSIZEY - 100);
	}
}

void gameStudy::CreatTails(void)
{
	//꼬리추가시켜라
	for (int i = 0; i < WormsNum; i++)
	{
		if (_Worms[i].move) continue;
		_Worms[i].CenterX = _Worms[i - 1].CenterX;
		_Worms[i].CenterY = _Worms[i - 1].CenterY;
		_Worms[i].move = true;
		break;
	}
}

void gameStudy::CreatComTails(void)
{
	//컴퓨터 꼬리 추가시켜라
	for (int i = 0; i < WormsNum; i++)
	{
		if (_comWorms[i].move) continue;
		_comWorms[i].CenterX = _comWorms[i - 1].CenterX;
		_comWorms[i].CenterY = _comWorms[i - 1].CenterY;
		_comWorms[i].move = true;
		break;
	}
}

void gameStudy::DestroyTails(void)
{
	//꼬리으로 줄여라
	int nowTail, i;
	for (i = 0; i < WormsNum; i++)
	{
		if (!_Worms[i].move) break;
	}

	//머리만 있으면 패스
	if (i == 1) return;
	else if (i % 2 == 1) nowTail = (i + 1) / 2;
	else if (i % 2 == 0) nowTail = i / 2;

	for (i = nowTail; i < WormsNum; i++)
	{
		_Worms[i].move = false;
	}
}

void gameStudy::Collision(void)
{
	for (int i = 3; i < WormsNum; i++)
	{
		if (!_Worms[i].move) continue;
		if (getDistance(_Worms[0].CenterX, _Worms[0].CenterY, _Worms[i].CenterX, _Worms[i].CenterY) <= 20 )
		{
			release();
			if (MessageBox(_hWnd, "다시 할래?", "Game Over", MB_YESNO) == IDYES) 
			{
				init();
			}
			else 
			{
				PostMessage(_hWnd, WM_DESTROY, 0, 0);
			}
		}
	}

	for (int i = 0; i < WormsNum; ++i)
	{
		if (!_Worms[i].move) continue;
		for (int j = 0; j < WormsNum; ++j)
		{
			if (!_comWorms[j].move) continue;
			if (j == 0)
			{
				if (getDistance(_comWorms[j].CenterX, _comWorms[j].CenterY, _Worms[i].CenterX, _Worms[i].CenterY) <= 50)
				{
					release();
					if (MessageBox(_hWnd, "다시 할래?", "Game Over", MB_YESNO) == IDYES)
					{
						init();
					}
					else
					{
						PostMessage(_hWnd, WM_DESTROY, 0, 0);
					}
				}
			}
			else if (getDistance(_comWorms[j].CenterX, _comWorms[j].CenterY, _Worms[i].CenterX, _Worms[i].CenterY) <= 40)
			{
				release();
				if (MessageBox(_hWnd, "다시 할래?", "Game Over", MB_YESNO) == IDYES)
				{
					init();
				}
				else
				{
					PostMessage(_hWnd, WM_DESTROY, 0, 0);
				}
			}
		}
	}
}
