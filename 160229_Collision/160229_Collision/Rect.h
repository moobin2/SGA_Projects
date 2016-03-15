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
	int _oldx;										// �����̴� ��Ʈ �� x��ǥ
	int _oldy;										// �����̴� ��Ʈ �� x��ǥ
	int _rx[3];										// ������ ��Ʈ x��ǥ (left)
	int _ry[3];										// ������ ��Ʈ y��ǥ (left)
	RECT _rc[3];									// 3���� ��Ʈ
	BOOL _nowMove;									// �����̴� ��Ʈ �Ǵ� ����
public:
	BOOL impactCheck(RECT r1, RECT r2, HDC hdc);	// �浹 �Ǵ� �Լ�
	void printRect(HDC hdc);						// ��Ʈ ����Ʈ �Լ�
	void MoveRect(int dir);							// ��Ʈ �̵� �Լ�
	void OldPos(int num);							// �����̴� ��Ʈ �� ��ġ ����Լ�
	RECT GetRect(int num);							// ��Ʈ get�Լ�
	Rect();
	~Rect();
};

