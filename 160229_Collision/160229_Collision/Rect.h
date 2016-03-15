#pragma once
enum direction
{
	Up = 1,
	Down,
	Right,
	Left
};

class Rect
{
	int _oldx;										// 움직이는 렉트 전 x좌표
	int _oldy;										// 움직이는 렉트 전 x좌표
	int _rx[3];										// 각각의 렉트 x좌표 (left)
	int _ry[3];										// 각각의 렉트 y좌표 (left)
	RECT _rc[3];									// 3개의 렉트
	BOOL _nowMove;									// 움직이는 렉트 판단 변수
public:
	BOOL impactCheck(RECT r1, RECT r2, HDC hdc);	// 충돌 판단 함수
	void printRect(HDC hdc);						// 렉트 프린트 함수
	void MoveRect(int dir);							// 렉트 이동 함수
	void OldPos(int num);							// 움직이는 렉트 전 위치 기억함수
	RECT GetRect(int num);							// 렉트 get함수
	Rect();
	~Rect();
};

