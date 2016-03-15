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

	_x = CENTERX;
	_y = CENTERY;
	_rc = RectMakeCenter(_x, _y, 100, 100);
	_rcEll = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (_ptMouse.x > _rc.left && _ptMouse.x < _rc.right)
	{
		if(IntersectRect(&_tempRc, &_rcEll, &_rc)) wsprintf(str, "충돌");
		else wsprintf(str, "");
	}
	if (_ptMouse.y > _rc.top && _ptMouse.y < _rc.bottom)
	{
		if (IntersectRect(&_tempRc, &_rcEll, &_rc)) wsprintf(str, "충돌");
		else wsprintf(str, "");
	}
	//대각선 (1사분면)
	if (_ptMouse.x > _rc.right && _ptMouse.y < _rc.top)
	{
		pRect = { _rc.right, _rc.top };
		if (Distance(pRect, _ptMouse) <= (long)50) wsprintf(str, "충돌");
		else wsprintf(str, "");
	}
	//대각선 (2사분면)
	if (_ptMouse.x < _rc.left && _ptMouse.y < _rc.top)
	{
		pRect = { _rc.left, _rc.top };
		if (Distance(pRect, _ptMouse) <= (long)50) wsprintf(str, "충돌");
		else wsprintf(str, "");
	}
	//대각선 (3사분면)
	if (_ptMouse.x < _rc.left && _ptMouse.y > _rc.bottom)
	{
		pRect = { _rc.left, _rc.bottom };
		if (Distance(pRect, _ptMouse) <= (long)50) wsprintf(str, "충돌");
		else wsprintf(str, "");
	}
	//대각선 (4사분면)
	if (_ptMouse.x > _rc.right && _ptMouse.y > _rc.bottom)
	{
		pRect = { _rc.right, _rc.bottom };
		if (Distance(pRect, _ptMouse) <= (long)50) wsprintf(str, "충돌");
		else wsprintf(str, "");
	}

	

	_rcEll = RectMakeCenter(_ptMouse.x, _ptMouse.y, 100, 100);
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	TextOut(hdc, 10, 10, str, strlen(str));
	Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);
	EllipseMakeCenter(hdc, _ptMouse.x, _ptMouse.y, 100, 100);

}

LONG gameStudy::Distance(POINT p1, POINT p2)
{
	long distance;

	distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

	return distance;
}

