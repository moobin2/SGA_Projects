// 160229_충돌.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	//MSG : 운영체제에서 발행하는 메시지 정보를 저장하기 위한 구조체
	MSG message;

	//WNDCLASS : 윈도우의 정보를 저장하기 위한 구조체
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

	//윈도우 클래스 등록
	RegisterClass(&wndClass);

	//윈도우 생성
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

	//화면에 윈도우 보여준다
	ShowWindow(_hWnd, nCmdShow);

	//메시지 큐에 메시지가 있으면 메시지 처리...
	while (GetMessage(&message, 0, 0, 0)) //일반 프로그램용
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
	
		rc.printRect(hdc);											// 렉트 그려주기.
		rc.impactCheck(rc.GetRect(0), rc.GetRect(2), hdc);			// 충돌체크 확인.

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

	//윈도우 프로시져에서 처리되지 않은 나머지 메시지를 처리해준다
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
