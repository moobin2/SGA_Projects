#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init();

	_CookieImage = new image;
	_CookieImage->init("Cookie.bmp", 480, 330);
	for (int i = 0; i < 2; i++)
	{
		_background1[i] = new image;
		_background1[i]->init("background_2.bmp", 589, 319, true, false);
		_background2[i] = new image;
		_background2[i]->init("background_1.bmp", 843, 296, true, RGB(255, 0, 255));
	}
	//트렌스컬러 함수를 불러옴으로써 특정 색을 제외해서 출력할수있다.
	_CookieImage->setTransColor(true, RGB(255, 0, 255));
	_button = new image;
	_button->init("button.bmp", 202, 144, true, RGB(255, 0, 255));

	_Cookie.CookieRc = RectMake( WINSIZEX / 5, WINSIZEY / 5 * 4 - 132, 120, 132);
	_land = RectMake(-1, WINSIZEY / 5 * 4, WINSIZEX + 2, 50);
	_motionCount = _gameCount = _Cookie.jumpCount = _backX1 = _backX2 = 0;
	_Cookie.run = true;
	_Cookie.sliding = _Cookie.jump = _slideButton = _jumpButton = false;
	return S_OK;
}

void gameStudy::release()
{
	_CookieImage->release();
	SAFE_DELETE(_CookieImage);
	for (int i = 0; i < 2; i++)
	{
		_background1[i]->release();
		_background2[i]->release();
		SAFE_DELETE(_background1[i])
		SAFE_DELETE(_background2[i]);
	}
	_button->release();
	SAFE_DELETE(_button);

	gameNode::release();
}

void gameStudy::update()
{
	//마우스 오른쪽클릭으로 그 렉트의 인덱스번호와 구조체를 이용하여 무브함수를 실행한다.
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _Cookie.run)
	{
		_slideButton = true;
		_motionCount = 0;
		silding();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN) && _Cookie.sliding)
	{
		_slideButton = false;
		_Cookie.sliding = false;
		_Cookie.run = true;
		_Cookie.CookieRc = RectMake(WINSIZEX / 5, WINSIZEY / 5 * 4 - 132, 120, 132);
		_motionCount = 0;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _Cookie.jumpCount < 2)
	{
		_jumpButton = true;
		jump();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_SPACE))
	{
		_jumpButton = false;
	}

	if (_Cookie.jump) jumpMove();

	
	_gameCount++;
	_backX1--;
	_backX2-=3;
	if (_backX1 <= -WINSIZEX) _backX1 = 0;
	if (_backX2 <= -WINSIZEX) _backX2 = 0;
	if (_gameCount == 4)
	{
		_gameCount = 0;
		_motionCount++;
		if (_Cookie.run)
		{
			if (_motionCount == 4) _motionCount = 0;
		}
		else if (_Cookie.sliding)
		{
			if (_motionCount == 2) _motionCount = 0;
		}
		else if (_Cookie.jump)
		{
			if ( _Cookie.jumpCount == 1 && _motionCount == 1) _motionCount = 0;
			else if( _Cookie.jumpCount == 2 && _motionCount == 3) _motionCount = 0;
		}
	}
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	//배경 이미지 출력
	_background1[0]->render(backDC, _backX1, 0 , WINSIZEX, WINSIZEY, 0, 0, 589, 319);
	_background1[1]->render(backDC, _backX1 + WINSIZEX, 0, WINSIZEX, WINSIZEY, 0, 0, 589, 319);
	_background2[0]->render(backDC, _backX2, 0, WINSIZEX, WINSIZEY, 0, 0, 843, 296);
	_background2[1]->render(backDC, _backX2 + WINSIZEX, 0, WINSIZEX, WINSIZEY, 0, 0, 843, 296);

	Rectangle(backDC, _land.left, _land.top, _land.right, _land.bottom);
	Rectangle(backDC, _Cookie.CookieRc.left, _Cookie.CookieRc.top, _Cookie.CookieRc.right, _Cookie.CookieRc.bottom);
	
	//슬라이드 _slideButton = _jumpButton
	if(_slideButton) _button->render(backDC, WINSIZEX - 153, 407, 125, 85, 0, 0, 101, 72);
	else if (!_slideButton) _button->render(backDC, WINSIZEX - 151, 410, 122, 80, 0, 72, 101, 72);
	//점프 
	if (_jumpButton) _button->render(backDC, 27, 407, 125, 85, 101, 0, 101, 72);
	else if (!_jumpButton) _button->render(backDC, 29, 410, 122, 80, 101, 72, 101, 72);

	//버튼 이미지
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(backDC, pen);
	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, brush);
	EllipseMake(backDC, 30, 410, 120, 80);
	EllipseMake(backDC, WINSIZEX - 150, 410, 120, 80);
	DeleteObject(SelectObject(backDC, oldPen));
	DeleteObject(SelectObject(backDC, oldBrush));


	//쿠키 이미지 출력
	if (_Cookie.sliding)
	{
		_CookieImage->cookieRender(backDC, _Cookie.CookieRc.left, _Cookie.CookieRc.top , 170 , 70, 170 * _motionCount, 132);
	}
	else if (_Cookie.run)
	{
		_CookieImage->cookieRender(backDC, _Cookie.CookieRc.left, _Cookie.CookieRc.top, 120, 132, 120 * _motionCount, 0);
	}
	else if (_Cookie.jump)
	{
		if (_Cookie.jumpCount == 1)
		{
			_CookieImage->cookieRender(backDC, _Cookie.CookieRc.left - 10, _Cookie.CookieRc.top, 125, 115, 353, 139);
		}
		else if (_Cookie.jumpCount == 2)
		{
			_CookieImage->cookieRender(backDC, _Cookie.CookieRc.left, _Cookie.CookieRc.top, 120, 120, 120 * _motionCount, 205);
		}
	}

	char str[128];
	sprintf_s(str, "점프카운트 : %.f", _Cookie.jumpPower);
	TextOut(backDC, 10, 10, str, strlen(str));

	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::imageSetting(void)
{

}

void gameStudy::silding(void)
{
	_Cookie.run = _Cookie.jump = false;
	_Cookie.sliding = true;
	_Cookie.CookieRc = RectMake(WINSIZEX / 5, WINSIZEY / 5 * 4 - 70, 170, 70);
}

void gameStudy::jump(void)
{
	if(_Cookie.jumpCount == 0) _Cookie.CookieRc = RectMake(WINSIZEX / 5, WINSIZEY / 5 * 4 - 132, 120, 132);
	_Cookie.run = _Cookie.sliding = false;
	_Cookie.jump = true;
	_Cookie.jumpPower = 10.5f;
	_Cookie.gravity = 0.4f;
	_Cookie.jumpCount++;
	_motionCount = 0;
}

void gameStudy::jumpMove(void)
{
	_Cookie.CookieRc.bottom -= _Cookie.jumpPower;
	_Cookie.CookieRc.top -= _Cookie.jumpPower;
	_Cookie.jumpPower -= _Cookie.gravity;

	if (_Cookie.CookieRc.bottom >= WINSIZEY / 5 * 4)
	{
		_Cookie.CookieRc = RectMake(WINSIZEX / 5, WINSIZEY / 5 * 4 - 132, 120, 132);
		_Cookie.jumpPower = 0.f;
		_Cookie.gravity = 0.f;
		_Cookie.jump = _Cookie.sliding = false;
		_Cookie.run = true;
		_motionCount = 0;
		_Cookie.jumpCount = 0;
	}
}
