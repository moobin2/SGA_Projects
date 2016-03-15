#include <Windows.h>

#define Blue 66, 120, 186
#define Pink 252, 116, 180
#define Green 117, 194, 78

////////////숫자 적을수록 진한색
#define Hair0_0 75, 60, 75
#define Hair0 120, 90, 105
#define Hair1 181, 135, 135
#define Hair2 226, 196, 181
#define Hair3 241, 241, 226

#define Band0 105, 45, 75
#define Band1 151, 60, 75
#define Band2 181, 60, 75
#define Band3 241, 75, 75

#define Skin0 241, 166, 120
#define Skin1 241, 211, 181

HINSTANCE _hInstance;
HWND _hWnd;

void PixelPrint(HDC hdc, int x, int y, int r, int g, int b);
void Pixel5Print(HDC hdc, int x, int y, int r, int g, int b);
LPTSTR _lpszClass = TEXT("[160226] 구구단 & 그림");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdshow)
{
	_hInstance = hInstance;
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = _lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 10, 10, 800, 600, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(_hWnd, nCmdshow);

	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR gugudan[30];
	static int i, j;
	static int x = 10;
	static int y = 10;


	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// 구구단 출력
		for (i = 2; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
			{
				wsprintf(gugudan, "%d x %d = %d", i, j, i*j);
				TextOut(hdc, x, y, gugudan, strlen(gugudan));
				x += 87;
			}
			y += 20;
			x = 10;
		}

		// 그림 그리기

		PixelPrint(hdc, 240, 200, 0, 0, 0);
		PixelPrint(hdc, 230, 210, 0, 0, 0);
		PixelPrint(hdc, 240, 210, Pink);
		PixelPrint(hdc, 250, 210, 0, 0, 0);
		for (int i = 0; i < 60; i += 10)	PixelPrint(hdc, 180 + i, 220, 0,0,0);
		for (int i = 0; i < 30; i += 10)	PixelPrint(hdc, 230 + i, 220, Pink);
		PixelPrint(hdc, 260, 220, 0, 0, 0);
		PixelPrint(hdc, 170, 230, 0, 0, 0);
		for (int i = 0; i < 40; i += 10)	PixelPrint(hdc, 180 + i, 230, Pink);
		for (int i = 0; i < 50; i += 10)	PixelPrint(hdc, 220 + i, 230, Blue);
		PixelPrint(hdc, 270, 230, 0, 0, 0);
		PixelPrint(hdc, 180, 240, 0, 0, 0);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 190 + i, 240, Pink);
		for (int i = 0; i < 70; i += 10)	PixelPrint(hdc, 210 + i, 240, Blue);
		PixelPrint(hdc, 280, 240, 0, 0, 0);
		for (int i = 0; i < 30; i += 10)	PixelPrint(hdc, 170 + i, 250, 0,0,0);
		PixelPrint(hdc, 160, 260, 0, 0, 0);
		PixelPrint(hdc, 170, 270, 0, 0, 0);
		for (int i = 0; i < 20; i += 10) PixelPrint(hdc, 170 + i, 280, 0, 0, 0);
		PixelPrint(hdc, 160, 290, 0, 0, 0);
		PixelPrint(hdc, 170, 300, 0, 0, 0);
		PixelPrint(hdc, 180, 310, 0, 0, 0);
		for (int i = 0; i < 20; i += 10) PixelPrint(hdc, 170, 320 + i, 0, 0, 0);
		PixelPrint(hdc, 160, 340, 0, 0, 0);
		for (int i = 0; i < 20; i += 10) PixelPrint(hdc, 150, 350 + i, 0, 0, 0);
		for (int i = 0; i < 90; i += 10)	PixelPrint(hdc, 200 + i, 250, Blue);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 240 + i, 250, 255, 255, 255);
		PixelPrint(hdc, 270, 250, 255, 255, 255);
		for (int i = 0; i < 30; i += 10)    PixelPrint(hdc, 290, 250 + i, 0, 0, 0);
		for (int i = 0; i < 30; i += 10)    PixelPrint(hdc, 300, 280 + i, 0, 0, 0);
		for (int i = 0; i < 20; i += 10)    PixelPrint(hdc, 290, 310 + i, 0, 0, 0);
		for (int i = 0; i < 20; i += 10)    PixelPrint(hdc, 280, 330 + i, 0, 0, 0);
		for (int i = 0; i < 20; i += 10)    PixelPrint(hdc, 290, 350 + i, 0, 0, 0);
		for (int i = 0; i < 30; i += 10)	PixelPrint(hdc, 170 + i, 260, Pink);
		for (int i = 0; i < 90; i += 10)	PixelPrint(hdc, 200 + i, 260, Blue);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 230 + i, 260, 255, 255, 255);
		PixelPrint(hdc, 250, 260, 0, 0, 0);
		PixelPrint(hdc, 270, 260, 0, 0, 0);
		PixelPrint(hdc, 280, 260, 255, 255, 255);
		PixelPrint(hdc, 180, 270, Pink);
		for (int i = 0; i < 90; i += 10)	PixelPrint(hdc, 190 + i, 270, Blue);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 230 + i, 270, 255, 255, 255);
		PixelPrint(hdc, 250, 270, 0, 0, 0);
		PixelPrint(hdc, 270, 270, 0, 0, 0);
		PixelPrint(hdc, 280, 270, 255, 255, 255);
		for (int i = 0; i < 110; i += 10)	PixelPrint(hdc, 190 + i, 280, Blue);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 230 + i, 280, 255, 255, 255);
		PixelPrint(hdc, 250, 280, 0, 0, 0);
		PixelPrint(hdc, 270, 280, 0, 0, 0);
		PixelPrint(hdc, 280, 280, 255, 255, 255);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 170 + i, 290, Pink);
		for (int i = 0; i < 110; i += 10)	PixelPrint(hdc, 190 + i, 290, Blue);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 230 + i, 290, 255, 255, 255);
		PixelPrint(hdc, 250, 290, 0, 0, 0);
		PixelPrint(hdc, 270, 290, 0, 0, 0);
		PixelPrint(hdc, 280, 290, 255, 255, 255);
		PixelPrint(hdc, 180, 300, Pink);
		for (int i = 0; i < 110; i += 10)	PixelPrint(hdc, 190 + i, 300, Blue);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 240 + i, 300, 255, 255, 255);
		PixelPrint(hdc, 270, 300, 255, 255, 255);
		for (int i = 0; i < 40; i += 10)	PixelPrint(hdc, 190 + i, 310, Blue);
		PixelPrint(hdc, 200, 310, Pink);
		for (int i = 0; i < 60; i += 10)	PixelPrint(hdc, 230 + i, 310, 0,0,0);
		PixelPrint(hdc, 260, 310, 255,255,255);
		for (int i = 0; i < 110; i += 10)	PixelPrint(hdc, 180 + i, 320, Blue);
		for (int i = 0; i < 30; i += 10)	PixelPrint(hdc, 190 + i, 320, Pink);
		for (int i = 0; i < 50; i += 10)	PixelPrint(hdc, 180 + i, 330, Blue);
		for (int i = 0; i < 30; i += 10)	PixelPrint(hdc, 190 + i, 330, Pink);
		for (int i = 0; i < 50; i += 10)	PixelPrint(hdc, 180 + i, 340, Blue);
		PixelPrint(hdc, 170, 340, Pink);
		for (int i = 0; i < 20; i += 10)	PixelPrint(hdc, 190 + i, 340, Pink);
		PixelPrint(hdc, 160, 350, Pink);
		for (int i = 0; i < 50; i += 10)	PixelPrint(hdc, 170 + i, 350, Blue);
		for (int i = 0; i < 40; i += 10)	PixelPrint(hdc, 220 + i, 350, Pink);
		for (int i = 0; i < 60; i += 10)	PixelPrint(hdc, 160 + i, 360, Blue);
		for (int i = 0; i < 70; i += 10)	PixelPrint(hdc, 220 + i, 360, Pink);
		PixelPrint(hdc, 270, 360, 255,255,255);
		for (int i = 0; i < 130; i += 10)	PixelPrint(hdc, 160 + i, 370, 0,0,0);

		/////////////////////////////////////////////////////////////////////////

		for (int i = 0; i < 25; i += 5)	Pixel5Print(hdc, 400, 270 + i, Hair1);
		Pixel5Print(hdc, 395, 275, Hair1);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 370 + i, 275, Hair2);
		Pixel5Print(hdc, 365, 270, Hair2);
		Pixel5Print(hdc, 390, 280, Hair1);
		Pixel5Print(hdc, 375, 280, Hair1);
		Pixel5Print(hdc, 380, 280, Hair2);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 360 + i, 285, Hair1);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 370 + i, 285, Hair2);
		Pixel5Print(hdc, 390, 285, Hair3);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 395, 280 + i, Hair3);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 375 + i, 290, Hair2);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 340 + i, 290, Hair2);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 360 + i, 290, Hair3);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 405 + i, 290, Hair3);
		Pixel5Print(hdc, 425, 290, Hair2);
		Pixel5Print(hdc, 420, 285, Hair2);
		Pixel5Print(hdc, 425, 285, Hair3);
		Pixel5Print(hdc, 415, 285, Hair1);
		Pixel5Print(hdc, 430, 280, Hair2);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 330 + i, 295, Hair1);
		Pixel5Print(hdc, 345, 295, Hair2);
		for (int i = 0; i < 35; i += 5)	Pixel5Print(hdc, 350 + i, 295, Hair3);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 385 + i, 295, Hair2);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 400 + i, 295, Hair3);
		Pixel5Print(hdc, 420, 295, Hair1);
		Pixel5Print(hdc, 315, 300, Hair1);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 325 + i, 300, Hair1);
		Pixel5Print(hdc, 340, 300, Hair2);
		for (int i = 0; i < 35; i += 5)	Pixel5Print(hdc, 345 + i, 300, Hair3);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 380 + i, 300, Hair2);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 395 + i, 300, Hair3);
		Pixel5Print(hdc, 415, 300, Hair1);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 320 + i, 305, Hair1);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 330 + i, 305, Hair2);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 345 + i, 305, Hair1);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 355 + i, 305, Hair2);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 370 + i, 305, Hair3);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 385 + i, 305, Hair2);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 395 + i, 305, Hair1);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 405 + i, 305, Hair2);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 420 + i, 305, Hair1);
		Pixel5Print(hdc, 335, 310, Hair0);
		for (int i = 0; i < 10; i += 5)	Pixel5Print(hdc, 340 + i, 310, Hair1);
		Pixel5Print(hdc, 350, 310, Hair2);
		for (int i = 0; i < 45; i += 5)	Pixel5Print(hdc, 355 + i, 310, Hair3);
		Pixel5Print(hdc, 400, 310, Hair2);
		for (int i = 0; i < 20; i += 5)	Pixel5Print(hdc, 405 + i, 310, Hair3);
		Pixel5Print(hdc, 425, 310, Hair1);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 335 + i, 315, Hair1);
		for (int i = 0; i < 15; i += 5)	Pixel5Print(hdc, 350 + i, 315, Hair2);
		for (int i = 0; i < 35; i += 5)	Pixel5Print(hdc, 365 + i, 315, Hair3);
		Pixel5Print(hdc, 400, 315, Hair1);
		for (int i = 0; i < 25; i += 5)	Pixel5Print(hdc, 405 + i, 315, Hair3);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 330, 320 + i, Hair0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 335 + i, 320, Hair1);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 345 + i, 320, Hair2);
		for (int i = 0; i < 40; i += 5) Pixel5Print(hdc, 360 + i, 320, Hair3);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 400 + i, 320, Hair0);
		Pixel5Print(hdc, 410, 320, Hair3);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 415 + i, 320, Hair2);
		Pixel5Print(hdc, 425, 320, Hair3);
		Pixel5Print(hdc, 430, 320, Hair1);
		Pixel5Print(hdc, 335, 325, Hair1);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 340 + i, 325, Hair2);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 360 + i, 325, Hair3);
		Pixel5Print(hdc, 380, 325, Hair2);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 385 + i, 325, Hair3);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 395 + i, 325, Hair0);
		Pixel5Print(hdc, 400, 325, 75, 60, 75);
		Pixel5Print(hdc, 410, 325, Hair1);
		Pixel5Print(hdc, 415, 325, Hair3);
		Pixel5Print(hdc, 420, 325, Hair0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 425 + i, 325, Hair3);
		Pixel5Print(hdc, 325, 330, Hair1);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 330 + i, 330, Hair2);
		Pixel5Print(hdc, 345, 330, Hair1);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 350, 330 + i, Band0);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 355, 330 + i, Band1);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 360 + i, 330, Hair3);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375 + i, 330, Hair2);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 385 + i, 330, Hair3);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 395 + i, 330, Band2);
		Pixel5Print(hdc, 410, 330, Band1);
		Pixel5Print(hdc, 415, 330, Hair3);
		for (int i = 0; i < 30; i += 5) Pixel5Print(hdc, 420, 330 + i, Hair0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 425 + i, 330, Hair3);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 330 + i, 335, Hair0);
		Pixel5Print(hdc, 345, 335, 120, 75, 90);
		Pixel5Print(hdc, 360, 335, Hair3);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 + i, 335, Hair2);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375, 335 + i, Hair1);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 380 + i, 335, Hair3);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 390, 335 + i, Band2);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 395, 335 + i, Band3);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 400, 335 + i, Band3);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 405, 335 + i, Band3);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 400 + i, 335 + i, 226, 151, 60);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 410, 335 + i, Band2);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 415, 335 + i, Hair2);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 425, 335 + i, Hair0);
		Pixel5Print(hdc, 430, 335, Hair2);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 325 + i, 340, Hair0);
		Pixel5Print(hdc, 345, 340, Band0);
		Pixel5Print(hdc, 360, 340, Hair2);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 365, 340 + i, Hair1);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 370, 340 + i, Hair1);
		Pixel5Print(hdc, 380, 340, Hair3);
		Pixel5Print(hdc, 385, 340, Hair1);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 395 + i, 340 + i, 226, 151, 60);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 430 + i, 340 + i, Hair0);
		for (int i = 0; i < 30; i += 5) Pixel5Print(hdc, 320 + i, 345, Hair0);
		Pixel5Print(hdc, 355, 345, Hair2);
		Pixel5Print(hdc, 360, 345, Hair1);
		Pixel5Print(hdc, 375, 345, Hair0);
		Pixel5Print(hdc, 380, 345, Hair2);
		Pixel5Print(hdc, 385, 345, Band1);
		Pixel5Print(hdc, 410, 345, Hair2);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 415, 345 + i, Band1);
		Pixel5Print(hdc, 425, 345, Hair0_0);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 335 + i, 350, Hair0);
		Pixel5Print(hdc, 360, 350, 211, 120, 120);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 370, 350 + i, Hair0);
		Pixel5Print(hdc, 375, 350, Hair2);
		Pixel5Print(hdc, 380, 350, Band1);
		Pixel5Print(hdc, 385, 350, Band2);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 335 + i, 355, Hair0);
		Pixel5Print(hdc, 355, 355, Skin1);
		Pixel5Print(hdc, 360, 355, Skin0);
		Pixel5Print(hdc, 375, 355, 90, 75, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 380, 355 + i, 90, 75, 75);
		Pixel5Print(hdc, 385, 355, 211, 120, 120);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 390 + i, 355, Skin0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 410, 355 + i, 90, 75, 75);
		Pixel5Print(hdc, 415, 355, 211, 120, 120);
		Pixel5Print(hdc, 420, 355, Hair0_0);
		Pixel5Print(hdc, 330, 360, 75, 75, 60);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 335 + i, 360, Hair0);
		Pixel5Print(hdc, 350, 360, Skin1);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 355 + i, 360, Skin0);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 365, 360 + i, Hair0);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 370, 360 + i, Skin0);
		Pixel5Print(hdc, 375, 360, 196, 196, 181);
		Pixel5Print(hdc, 385, 360, Skin0);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 390 + i, 360, Skin1);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 415, 360 + i, Skin0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 420, 360 + i, 60, 60, 45);
		Pixel5Print(hdc, 425, 360, 60, 60, 45);
		Pixel5Print(hdc, 325, 365, 75, 75, 60);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 330 + i, 365, Band0);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 340 + i, 365, 181, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 355 + i, 365, 211, 120, 120);
		Pixel5Print(hdc, 375, 365, 226, 241, 226);
		Pixel5Print(hdc, 380, 365, 181, 60, 75);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 385 + i, 365, Skin1);
		Pixel5Print(hdc, 410, 365, 181, 60, 75);
		Pixel5Print(hdc, 425, 365, Band0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 430 + i, 365, 151, 60, 75);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 325 + i, 370, 105, 105, 90);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 340 + i, 370, 181, 60, 75);
		for (int i = 0; i < 40; i += 5) Pixel5Print(hdc, 375 + i, 370, Skin1);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 420, 370 + i, Band0);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 425 + i, 370, 181, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 435 + i, 370, 105, 105, 90);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 310 + i, 375 + i, 181, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 325 - i, 375 + i, 181, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 340 + i, 375, 105, 105, 90);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 350 + i, 375, Band0);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 375 + i, 375, Skin1);
		Pixel5Print(hdc, 390, 375, 166, 90, 90);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 395 + i, 375, 211, 120, 120);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 405 + i, 375, Skin1);
		Pixel5Print(hdc, 415, 375, 211, 120, 120);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 425 + i, 375, 105, 105, 90);
		Pixel5Print(hdc, 335, 380, 120, 90, 105);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 340, 380 + i, 181, 135, 135);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 345, 380 + i, 75, 60, 75);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 350 + i, 380, 75, 75, 60);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 + i, 380, Band0);
		Pixel5Print(hdc, 375, 380, 211, 120, 120);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 380 + i, 380, Skin0);
		Pixel5Print(hdc, 405, 380, 211, 120, 120);
		Pixel5Print(hdc, 410, 380, 120, 90, 105);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 415 + i, 380, 75, 75, 60);
		for (int i = 0; i < 30; i += 5) Pixel5Print(hdc, 335, 385 + i, 181, 135, 135);
		for (int i = 0; i < 50; i += 5) Pixel5Print(hdc, 365 + i, 385, 60, 60, 45);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 385 + i, 385, 211, 120, 120);
		Pixel5Print(hdc, 405, 385, 151, 60, 75);
		for (int i = 0; i < 20; i += 5) Pixel5Print(hdc, 330, 390 + i, 120, 90, 105);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 345, 390 + i, 120, 90, 105);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 + i, 390 + i, 211, 211, 181);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 370 + i, 390 + i, 241, 241, 226);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375 + i, 390 + i, 60, 60, 45);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 380 + i, 390 + i, 75, 75, 60);
		Pixel5Print(hdc, 385, 390, 105, 105, 90);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 390 + i, 390, 105, 45, 75);
		Pixel5Print(hdc, 400, 390, 75, 75, 60);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 330, 395 + i, 181, 135, 135);
		Pixel5Print(hdc, 360, 395, 105, 105, 90);
		Pixel5Print(hdc, 365, 395, 151, 151, 135);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 390 + i, 395 + i, 241, 241, 226);
		Pixel5Print(hdc, 395, 395, 181, 60, 75);
		for (int i = 0; i < 35; i += 5) Pixel5Print(hdc, 400, 395 + i, 60, 60, 45);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 - i, 400 + i, 60, 60, 45);
		Pixel5Print(hdc, 370, 400, 105, 105, 90);
		Pixel5Print(hdc, 375, 400, 151, 151, 135);
		Pixel5Print(hdc, 380, 400, 45, 45, 45);
		for (int i = 0; i < 30; i += 5) Pixel5Print(hdc, 385, 400 + i, 105, 105, 90);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 390 - i, 400 + i, 241, 75, 75);
		Pixel5Print(hdc, 340, 405, 120, 90, 105);
		Pixel5Print(hdc, 340, 410, 75, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 335 - i, 415 + i, 120, 90, 105);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 330 - i, 415 + i, 181, 135, 135);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 315 + i, 415 + i, 181, 135, 135);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 + i, 405, 105, 105, 90);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375, 405 + i, 60, 60, 45);
		Pixel5Print(hdc, 380, 405, 75, 75, 60);
		Pixel5Print(hdc, 390, 405, 105, 45, 75);
		Pixel5Print(hdc, 395, 405, 181, 120, 60);
		for (int i = 0; i < 25; i += 5) Pixel5Print(hdc, 405, 405 + i, 60, 60, 45);
		Pixel5Print(hdc, 360, 410, 151, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 + i, 410, 241, 75, 75);
		Pixel5Print(hdc, 380, 410, 181, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 390 + i, 410, 241, 241, 226);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 405, 410 + i, 75, 75, 60);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 365 + i, 415, 45, 45, 45);
		Pixel5Print(hdc, 375, 415, 181, 60, 75);
		for (int i = 0; i < 15; i += 5) Pixel5Print(hdc, 380, 415 + i, 75, 75, 60);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 390 + i, 415, 181, 60, 75);
		Pixel5Print(hdc, 370, 420, 105, 45, 75);
		Pixel5Print(hdc, 375, 420, 75, 75, 60);
		Pixel5Print(hdc, 380, 420, 45, 45, 45);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 390 + i, 420, 45, 45, 45);
		Pixel5Print(hdc, 370, 425, 60, 60, 45);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375 + i, 425, 75, 75, 60);
		Pixel5Print(hdc, 395, 425, 45, 45, 45);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375 + i, 430, 105, 45, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 395 + i, 430, 105, 45, 75);
		Pixel5Print(hdc, 375, 435, 105, 45, 75);
		Pixel5Print(hdc, 380, 435, 181, 60, 75);
		Pixel5Print(hdc, 395, 435, 105, 45, 75);
		Pixel5Print(hdc, 400, 435, 181, 60, 75);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 375 + i, 440, 196, 60, 90);
		for (int i = 0; i < 10; i += 5) Pixel5Print(hdc, 395 + i, 440, 196, 60, 90);


		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void PixelPrint(HDC hdc, int x, int y, int r, int g, int b)
{
	int i = 0;
	int _x = x;
	int _y = y;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			SetPixel(hdc, _x, _y, RGB(r, g, b));
			_x++;
		}
		_y++;
		_x = x;
	}
}

void Pixel5Print(HDC hdc, int x, int y, int r, int g, int b)
{
	int i = 0;
	int _x = x;
	int _y = y;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			SetPixel(hdc, _x, _y, RGB(r, g, b));
			_x++;
		}
		_y++;
		_x = x;
	}
}