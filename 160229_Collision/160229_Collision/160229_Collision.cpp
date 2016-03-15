// 160229_�浹.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	//MSG : �ü������ �����ϴ� �޽��� ������ �����ϱ� ���� ����ü
	MSG message;

	//WNDCLASS : �������� ������ �����ϱ� ���� ����ü
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//������ Ŭ���� ���
	RegisterClass(&wndClass);

	//������ ����
	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WINSTYLE,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	//ȭ�鿡 ������ �����ش�
	ShowWindow(_hWnd, nCmdShow);

	//�޽��� ť�� �޽����� ������ �޽��� ó��...
	while (GetMessage(&message, 0, 0, 0)) //�Ϲ� ���α׷���
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static Rect rc;


	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(_hWnd, &ps);
		//=============================
	
		rc.printRect(hdc);											// ��Ʈ �׷��ֱ�.
		rc.impactCheck(rc.GetRect(0), rc.GetRect(2), hdc);			// �浹üũ Ȯ��.

		//=============================
		EndPaint(_hWnd, &ps);
	}
	break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		case VK_LEFT:
			rc.MoveRect(Left);
			InvalidateRect(hWnd, NULL, true);
			break;

		case VK_RIGHT:
			rc.MoveRect(Right);
			InvalidateRect(hWnd, NULL, true);
			break;

		case VK_UP:
			rc.MoveRect(Up);
			InvalidateRect(hWnd, NULL, true);
			break;

		case VK_DOWN:
			rc.MoveRect(Down);
			InvalidateRect(hWnd, NULL, true);
			break;

		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	//������ ���ν������� ó������ ���� ������ �޽����� ó�����ش�
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc;

	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left),
		(rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
