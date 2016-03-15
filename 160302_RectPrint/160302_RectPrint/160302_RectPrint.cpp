// 160302_RectPrint.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;

/* ==== 함수 프로토타입 선언 ===== */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
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

	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

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
	static TCHAR str[128];
	static RECT rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);
	static BOOL nowDraw = FALSE;
	static BOOL nowMove = FALSE;
	static BOOL DrawMode = FALSE;
	static int sx, sy, oldx, oldy, width, height, oldLeft, oldTop;
	static int kinds;
	
	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(_hWnd, &ps);
		//=============================

		if (!DrawMode)		// 크기조절모드 일때
			TextOut(hdc, 10, 10, "<< RECT 크기조절 >>", strlen("<< RECT 크기조절 >>"));
		else				// 이동모드 일때
			TextOut(hdc, 10, 10, "<< RECT 이동 >>", strlen("<< RECT 이동 >>"));

		TextOut(hdc, 10, 30, str, strlen(str));
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

		//=============================
		EndPaint(_hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_MOUSEMOVE:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		width = rc.right - rc.left;
		height = rc.bottom - rc.top;
		if (nowDraw && !DrawMode)
		{
			if (kinds == 1)			//렉트 in 1사분면
			{
				rc.right = sx;
				rc.top = sy;
			}
			else if (kinds == 2)	// 렉트 in 2사분면일때
			{
				rc.left = sx;
				rc.top = sy;
			}
			else if (kinds == 3)	// 렉트 in 3사분면
			{
				rc.left = sx;
				rc.bottom = sy;
			}
			else if (kinds == 4)	// 렉트 in 4사분면
			{
				rc.right = sx;
				rc.bottom = sy;
			}
		}
		else if (nowMove && DrawMode)
		{
			rc = RectMake(sx - (oldx - oldLeft), sy - (oldy - oldTop), width, height);		
			
		}
		wsprintf(str, TEXT("Left : %d , Top : %d , Right : %d , Bottom : %d"), rc.left, rc.top, rc.right, rc.bottom);
		if( nowMove | nowDraw) InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_LBUTTONDOWN:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		if (!DrawMode)	// 크기조절모드일때
		{
			nowDraw = TRUE;
			if (sx > rc.left + (rc.right - rc.left) / 2 && sx < rc.right && sy < rc.top + (rc.bottom - rc.top) / 2 && sy > rc.top)			//렉트 in 1사분면
			{
				kinds = 1;
			}
			else if (sx < rc.left + (rc.right - rc.left) / 2 && sx > rc.left && sy < rc.top + (rc.bottom - rc.top) / 2 && sy > rc.top)		// 렉트 in 2사분면일때
			{
				kinds = 2;
			}
			else if (sx < rc.left + (rc.right - rc.left) / 2 && sx > rc.left && sy >  rc.top + (rc.bottom - rc.top) / 2 && sy < rc.bottom)	// 렉트 in 3사분면
			{
				kinds = 3;
			}
			else if (sx > rc.left + (rc.right - rc.left) / 2 && sx < rc.right && sy > rc.top + (rc.bottom - rc.top) / 2 && sy < rc.bottom)	// 렉트 in 4사분면
			{
				kinds = 4;
			}
		}

		else if (DrawMode && sx < rc.right && sx > rc.left && sy > rc.top && sy < rc.bottom)	// 이동모드 일때 && 클릭위치가 렉트 in 일때
		{
			nowMove = TRUE;
			oldx = sx;
			oldy = sy;
			oldLeft = rc.left;
			oldTop = rc.top;
		}
		break;
	case WM_RBUTTONDOWN:
		if(DrawMode)
			DrawMode = FALSE;
		else
			DrawMode = TRUE;
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_LBUTTONUP:
		if (rc.left > rc.right)
		{
			int temp = rc.left;
			rc.left = rc.right;
			rc.right = temp;
		}
		if (rc.top > rc.bottom)
		{
			int temp = rc.bottom;
			rc.bottom = rc.top;
			rc.top = temp;
		}
		if (!DrawMode)
		{
			kinds = 0;
			nowDraw = FALSE;
		}
		else
		{
			nowMove = FALSE;
		}
		InvalidateRect(hWnd, NULL, TRUE);
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