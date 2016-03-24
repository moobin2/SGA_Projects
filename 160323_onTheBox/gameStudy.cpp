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

	IMAGEMANAGER->addImage("background", "background.bmp", WINSIZEX, WINSIZEY, false, false);
	IMAGEMANAGER->addImage("tile", "tile.bmp", 1006, 134, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("object", "object.bmp", 50, 28, true, RGB(255, 0, 255));
	_Olivia = IMAGEMANAGER->addFrameImage("Olivia", "basicmotion.bmp", 240, 280, 4, 4, true, RGB(255, 0, 255));
	
	_rcOlivia = RectMake(CENTERX, CENTERY, 22, 70);
	_land = RectMake(0, WINSIZEY - 100, WINSIZEX, 100);
	_stone = RectMake(300, WINSIZEY - 127, 50, 28);
	_temp = RectMake(0, 0, 0, 0);

	_jumpPower = 0.f;
	_gravity = 0.8f;
	_isRight = false;
	_standing = true;
	_count = 0;
	_index = 0;

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_standing = false;
		if (_isRight) _isRight = !_isRight;
		_rcOlivia.left -= 3.f;
		_rcOlivia.right -= 3.f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_standing = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_standing = false;
		if (!_isRight) _isRight = !_isRight;
		_rcOlivia.left += 3.f;
		_rcOlivia.right += 3.f;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_jumping = true;
		_standing = false;
		_jumpPower = 10.f;
		_gravity = 0.8f;
	}

	_rcOlivia.top -= _jumpPower;
	_rcOlivia.bottom -= _jumpPower;
	_jumpPower -= _gravity;

	if (!_standing)
	{
		if (_isRight)
		{
			_count++;
			_Olivia->setFrameY(3);
			if (_count % 6 == 0)
			{
				_index++;
				if (_index > _Olivia->getMaxFrameX())
					_index = 0;

				_Olivia->setFrameX(_index);
			}
		}
		else
		{
			_count++;
			_Olivia->setFrameY(2);
			if (_count % 6 == 0)
			{
				_index++;
				if (_index > _Olivia->getMaxFrameX())
					_index = 0;

				_Olivia->setFrameX(_index);
			}
		}
	}
	else
	{
		if (_isRight)
		{
			_count++;
			_Olivia->setFrameY(1);
			if (_count % 6 == 0)
			{
				_index++;
				if (_index > _Olivia->getMaxFrameX() - 1)
					_index = 0;

				_Olivia->setFrameX(_index);
			}
		}
		else
		{
			_count++;
			_Olivia->setFrameY(0);
			if (_count % 6 == 0)
			{
				_index++;
				if (_index > _Olivia->getMaxFrameX() - 1)
					_index = 0;

				_Olivia->setFrameX(_index);
			}
		}
	}

	if (_jumping)
	{
		if (_isRight)
		{
			_Olivia->setFrameY(1);
			_Olivia->setFrameX(3);
		}
		else
		{
			_Olivia->setFrameY(0);
			_Olivia->setFrameX(3);
		}
	}

	if (IntersectRect(&_temp, &_rcOlivia, &_land))
	{
		_standing = true;
		_jumping = false;
		_jumpPower = 0;
		float tempLeft = _rcOlivia.left;
		_rcOlivia = RectMake(tempLeft, _land.top - 70, 22, 70);
	}
	if (IntersectRect(&_temp, &_rcOlivia, &_stone))
	{
		float _tempW = _temp.right - _temp.left;
		float _tempH = _temp.bottom - _temp.top;
		
		//좌우충돌
		if (_tempH > _tempW)
		{
			//왼쪽 충돌
			if (_temp.left == _stone.left)
			{
				_rcOlivia.left -= _tempW;
				_rcOlivia.right -= _tempW;
			}
			//오른쪽 충돌
			else if (_temp.right == _stone.right)
			{
				_rcOlivia.left += _tempW;
				_rcOlivia.right += _tempW;
			}
		}
		//위에서 충돌
		else if(_tempH <= _tempW && _jumpPower < 0)
		{
			_jumpPower = 0.f;
			_jumping = false;
			_standing = true;
			_rcOlivia.bottom -= (_tempH);
			_rcOlivia.top -= (_tempH);
		}
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//이 사이에서 그려주면 됨.

	//Rectangle(backDC, _land.left, _land.top, _land.right, _land.bottom);
	//Rectangle(backDC, _stone.left, _stone.top, _stone.right, _stone.bottom);
	//Rectangle(backDC, _rcOlivia.left, _rcOlivia.top, _rcOlivia.right, _rcOlivia.bottom);
	//IMAGEMANAGER->loopRender("background", backDC, &RectMake(0, 0, WINSIZEX, WINSIZEY), _x, _y);

	_Olivia->frameRender(backDC, _rcOlivia.left - 19, _rcOlivia.top + 2, _Olivia->getFrameX(), _Olivia->getFrameY());

	IMAGEMANAGER->render("tile", backDC, _land.left, _land.top, 0, 0, WINSIZEX, 110);
	IMAGEMANAGER->render("object", backDC, _stone.left, _stone.top, 0, 0, 50, 28);
	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}


