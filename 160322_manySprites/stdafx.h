// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN //MFC�� �ƴ� ���� ���α׷��� ���
							//WIN32_LEAN_AND_MEAN�� ������ commdlg.h ���
							//�ʿ���� ��������� ��Ŭ��� ���� �ʰ� ���ش�.

#include <Windows.h>		//������ ������� ��Ŭ���
#include <stdio.h>			//���Ĵٵ� ����� ��� ��Ŭ��� (printf, scanf ���)
#include <tchar.h>			//�����쿡�� ����� ���ڿ� ��� ��� ��Ŭ���
							//MBCS (Multi Byte Character Set)
							//->������ ����ϴ� ��Ƽ����Ʈ ������ ���ڿ�
							//WBCS (Wide Byte Character Set)
							//->��� ���ڸ� 2����Ʈ�� ó��. �����ڵ� ���

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"

/* ===== �����ι� ===== */
#define WINNAME (LPTSTR)(TEXT("CookieRun"))
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 800
#define WINSIZEY 500
#define CENTERX (WINSIZEX / 2)
#define CENTERY (WINSIZEY / 2)
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p)			{if(p) { delete (p);		(p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) { delete[] (p);		(p) = NULL;}}
#define SAFE_RELEASE(p)			{if(p) { (p)->release();	(p) = NULL;}}

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()


/* ===== ���� ���� ===== */
extern POINT _ptMouse;
extern HWND _hWnd;
extern HINSTANCE _hInstance;