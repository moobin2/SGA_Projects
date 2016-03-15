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

	GetLocalTime(&_time);
	_sec = _time.wSecond;
	_min = _time.wMinute;
	_hour = _time.wHour;
	hourAngle =  90 - ((_time.wHour % 12) * 30 + _time.wMinute * 0.5);
	minuteAngle = 90 - (_time.wMinute * 6 + _time.wSecond * 0.1);
	secondAngle = 90 - _time.wSecond * 6;

	count = 0;
	_watch.first = { CENTERX, CENTERY };

	_watch.minuteBar = 180;
	_watch.secondBar = 150;
	_watch.hourBar = 120;

	_watch.second.x = cosf(secondAngle * PI / 180) * _watch.secondBar + _watch.first.x;
	_watch.second.y = -sinf(secondAngle * PI / 180) * _watch.secondBar + _watch.first.y;
	_watch.minute.x = cosf(minuteAngle * PI / 180) * _watch.minuteBar + _watch.first.x;
	_watch.minute.y = -sinf(minuteAngle * PI / 180) * _watch.minuteBar + _watch.first.y;
	_watch.hour.x = cosf(hourAngle * PI / 180) * _watch.hourBar + _watch.first.x;
	_watch.hour.y = -sinf(hourAngle * PI / 180) * _watch.hourBar + _watch.first.y;
	

	return S_OK;
}

void gameStudy::release()
{
	gameNode::release();
}

void gameStudy::update()
{
	hourAngle -= (1 / 12000);
	minuteAngle -= (0.001f);
	secondAngle -= (0.06f);

	_watch.second.x = cosf(secondAngle * PI / 180) * _watch.secondBar + _watch.first.x;
	_watch.second.y = -sinf(secondAngle * PI / 180) * _watch.secondBar + _watch.first.y;
	_watch.minute.x = cosf(minuteAngle * PI / 180) * _watch.minuteBar + _watch.first.x;
	_watch.minute.y = -sinf(minuteAngle * PI / 180) * _watch.minuteBar + _watch.first.y;
	_watch.hour.x = cosf(hourAngle * PI / 180) * _watch.hourBar + _watch.first.x;
	_watch.hour.y = -sinf(hourAngle * PI / 180) * _watch.hourBar + _watch.first.y;

	count++;

	if (count % 100 == 0)
	{
		_sec += 1;
		if (_sec % 60 == 0)
		{
			_sec = 0;
			_min += 1;
			if (_min & 60 == 0)
			{
				_min = 0;
				_hour += 1;
				if (_hour % 24 == 0)
				{
					_hour = 0;
				}
			}
		}
	}
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
#pragma comment(lib, "msimg32.lib")
	HDC memDC = CreateCompatibleDC(hdc);

	//비트맵 출력
	HBITMAP bitMap = (HBITMAP)LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	HBITMAP oldBitMap = (HBITMAP)SelectObject(memDC, bitMap);
	EllipseMakeCenter(hdc, CENTERX, CENTERY, 400, 400);
	TransparentBlt(hdc, CENTERX - 200, CENTERY - 200, 400, 400, memDC, 0, 0, 400, 400, RGB(255, 0, 255));
	SelectObject(memDC, oldBitMap);
	DeleteObject(bitMap);
	DeleteDC(memDC);

	//펜 출력
	HPEN Spen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldpen = (HPEN)SelectObject(hdc, Spen);

	LineMake(hdc, _watch.first.x, _watch.first.y, _watch.second.x, _watch.second.y);

	HPEN Mpen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	oldpen = (HPEN)SelectObject(hdc, Mpen);
	LineMake(hdc, _watch.first.x, _watch.first.y, _watch.minute.x, _watch.minute.y);

	HPEN Hpen = CreatePen(PS_SOLID, 8, RGB(0, 0, 255));
	oldpen = (HPEN)SelectObject(hdc, Hpen);
	LineMake(hdc, _watch.first.x, _watch.first.y, _watch.hour.x, _watch.hour.y);
	SelectObject(hdc, oldpen);
	DeleteObject(Spen);
	DeleteObject(Mpen);
	DeleteObject(Hpen);
	
	char str[128];
	sprintf_s(str, "시: %d, 분: %d, 초:%d", _hour, _min, _sec);
	TextOut(hdc, 10, 10, str, strlen(str));
}