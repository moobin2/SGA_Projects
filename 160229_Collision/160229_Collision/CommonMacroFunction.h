#pragma once
//#include "stdafx.h"
#include <vector>

inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

inline void LineMake(HDC hdc, std::vector<POINT> vPt)
{
	std::vector<POINT>::iterator viPoint;
	int i = 0;
	for (viPoint = vPt.begin(); viPoint != vPt.end(); ++viPoint, i++)
	{
		if (i == 0) MoveToEx(hdc, viPoint->x, viPoint->y, NULL);
		else LineTo(hdc, viPoint->x, viPoint->y);

	}
	vPt.clear();
}

inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;

}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2 , y - height / 2 , x + width / 2 , y + height / 2 };

	return rc;
}

//인라인 함수 : inline이라고 붙으면 일반 함수보다 좀 더 빠르게 실행시킬수 있게.. (3~5줄 이내의 함수만 사용)
//				(가장 빠른곳은 레지스터, 그곳에 이 함수를 넣고 실행시킬수 있게. ps. 레지스터에서 여유가 있다면)
//				(줄수가 적은 함수에만 인라인 함수를 붙여라. 안그러면 프로그램이 커지게 되면서 읽어들일때 시간이 오래 걸린다.)
//				단점 -> 코드영역의 크기가 커진다. 

inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}