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

	_background = new image;
	_background->init("background.bmp", 400, 400, true);

	shuffle(_image);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_image[i + j * 4].imageRC = RectMake( WINSIZEX / 15 + i * 105, WINSIZEY / 5 + j * 105,  100 , 100);
			
		}
	}

	return S_OK;
}

void gameStudy::release()
{
	_background->release();
	SAFE_DELETE(_background);

	gameNode::release();
}

void gameStudy::update()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < PuzzleNum; i++)
		{
			if (PtInRect(&_image[i].imageRC, _ptMouse))
			{
				rectMove(_image, i);
			}
		}
	}

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();

	HPEN pen = CreatePen(PS_SOLID, 5, RGB(103 , 153, 255));
	HPEN oldPen = (HPEN)SelectObject(backDC, pen);

	Rectangle(backDC, WINSIZEX / 15 - 5, WINSIZEY / 5 - 5, WINSIZEX / 15 + 420, WINSIZEY / 5 + 420);
	Rectangle(backDC, WINSIZEX / 15 * 8  - 5, WINSIZEY / 5 - 5, WINSIZEX / 15 * 8 + 420, WINSIZEY / 5 + 420);
	_background->render(backDC, WINSIZEX / 15 * 8, WINSIZEY / 5, 415, 415);
	for (int i = 0; i < PuzzleNum; i++)
	{
		_background->render(backDC, _image[i].imageRC, _image[i].num);
		if(_image[i].num == 15) Rectangle(backDC, _image[i].imageRC.left, _image[i].imageRC.top, _image[i].imageRC.right, _image[i].imageRC.bottom);
	}
	
	DeleteObject(SelectObject(backDC, oldPen));
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::imageSetting(void)
{

}

void gameStudy::shuffle(tagImage * image)
{
	int dest, sour;
	tagImage temp;
	for (int i = 0; i < PuzzleNum; i++)
	{
		image[i].num = i;
	}

	for (int i = 0; i < 30; i++)
	{
		dest = RND->getInt(PuzzleNum-1);
		sour = RND->getInt(PuzzleNum-1);

		temp = image[dest];
		image[dest] = image[sour];
		image[sour] = temp;
	}
}

void gameStudy::rectMove(tagImage * image, int index)
{
	tagImage temp;
	if (image[index + 4].num == 15 && index < 12)
	{
		temp.num = image[index].num;
		image[index].num = image[index + 4].num;
		image[index + 4].num = temp.num;
	}
	else if (image[index - 4].num == 15 && index > 3)
	{
		temp.num = image[index].num;
		image[index].num = image[index - 4].num;
		image[index - 4].num = temp.num;
	}
	else if (image[index - 1].num == 15 && index % 4 != 0)
	{
		temp.num = image[index].num;
		image[index].num = image[index - 1].num;
		image[index - 1].num = temp.num;
	}
	else if (image[index + 1].num == 15 && index % 4 != 3)
	{
		temp.num = image[index].num;
		image[index].num = image[index + 1].num;
		image[index + 1].num = temp.num;
	}
}
