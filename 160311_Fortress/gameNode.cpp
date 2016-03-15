#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}


HRESULT gameNode::init()
{
	SetTimer(_hWnd, 1, 10, NULL);

	KEYMANAGER->init();

	return S_OK;
}

void gameNode::release()
{
	KillTimer(_hWnd, 1);

	KEYMANAGER->release();
	KEYMANAGER->releaseSingleton();
}

void gameNode::update()
{
	InvalidateRect(_hWnd, NULL, false);
}

void gameNode::render(HDC hdc)
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc , memDC;
	PAINTSTRUCT ps;
	HBITMAP Mybitmap, OldBitmap;
	RECT crt;

	switch (iMessage)
	{
	case WM_TIMER:
	{
		this->update();
	}
	break;

	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(_hWnd, &ps);
		GetClientRect(hWnd, &crt);
		memDC = CreateCompatibleDC(hdc);
		Mybitmap = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		OldBitmap = (HBITMAP)SelectObject(memDC, Mybitmap);
		FillRect(memDC, &crt, (HBRUSH)GetStockObject(WHITE_BRUSH));
		//=============================

		this->render(memDC);

		//=============================
		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, memDC, 0, 0, SRCCOPY);
		DeleteObject(SelectObject(memDC, OldBitmap));
		DeleteDC(memDC);
		EndPaint(_hWnd, &ps);
	}
	break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(_hWnd, WM_DESTROY, 0, 0);
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