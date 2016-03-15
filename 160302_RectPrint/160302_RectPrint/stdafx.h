// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include "commonMacroFunction.h"

/* ===== 디파인문 ===== */
#define WINNAME (LPTSTR)(TEXT("[160302] 렉트늘리기 & 옴기기"))
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 800
#define WINSIZEY 600
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p)			{if(p) { delete (p);		(p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) { delete[] (p);		(p) = NULL;}}
#define SAFE_RELEASE(p)			{if(p) { (p)->release();	(p) = NULL;}}
