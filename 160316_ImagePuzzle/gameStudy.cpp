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
	_background->init("background.bmp", 400, 400);
	//트렌스컬러 함수를 불러옴으로써 특정 색을 제외해서 출력할수있다.
	_background->setTransColor(true, RGB(255, 0, 255));

	shuffle(_image);

	//각각의 렉트위치 초기화
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
	//마우스 오른쪽클릭으로 그 렉트의 인덱스번호와 구조체를 이용하여 무브함수를 실행한다.
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < PuzzleNum; i++)
		{
			if (PtInRect(&_image[i].imageRC, _ptMouse)) rectMove(_image, i);
		}
	}

	if (clear(_image))
	{
		_gameCount++;
		if (_gameCount == 200)
		{
			_gameCount = 0;
			init();
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

	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	Rectangle(backDC, WINSIZEX / 15 - 5, WINSIZEY / 5 - 5, WINSIZEX / 15 + 420, WINSIZEY / 5 + 420);
	Rectangle(backDC, WINSIZEX / 15 * 8  - 5, WINSIZEY / 5 - 5, WINSIZEX / 15 * 8 + 420, WINSIZEY / 5 + 420);
	_background->render(backDC, WINSIZEX / 15 * 8, WINSIZEY / 5, 415, 415);
	DeleteObject(SelectObject(backDC, oldPen));

	for (int i = 0; i < PuzzleNum; i++)
	{
		_background->render(backDC, _image[i].imageRC, _image[i].num);
		//BitBlt(hdc, rc.left, rc.top, width, height, _imageInfo->hMemDC,  (num % 4) * width, (num / 4) * height, SRCCOPY);
		if(_image[i].num == 15) Rectangle(backDC, _image[i].imageRC.left, _image[i].imageRC.top, _image[i].imageRC.right, _image[i].imageRC.bottom);
	}
	
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::imageSetting(void)
{

}

void gameStudy::shuffle(tagImage * image)
{
	int dest, sour;
	int count = 0;
	tagImage temp;
	//순차적으로 넘버값 넣어준다
	for (int i = 0; i < PuzzleNum; i++)
	{
		image[i].num = i;
	}

	//인덱스 자체로 섞어준다
	for (int i = 0; i < 30; i++)
	{
		dest = RND->getInt(PuzzleNum-1);
		sour = RND->getInt(PuzzleNum-1);

		temp = image[dest];
		image[dest] = image[sour];
		image[sour] = temp;
	}

	//만약 무질서계수가 홀수로 나오면 다시 섞어준다
	for (int i = 0; i < PuzzleNum; ++i)
	{
		for (int j = i + 1; j < PuzzleNum; j++)
		{
			if (image[i].num > image[j].num) count++;
		}
	}
	if (count % 2 == 1) shuffle(_image);
}

void gameStudy::rectMove(tagImage * image, int index)
{
	//무브 조건
	tagImage temp;

	//아래로 바꿀때
	if (image[index + 4].num == PuzzleNum - 1 && index < 12)
	{
		temp.num = image[index].num;
		image[index].num = image[index + 4].num;
		image[index + 4].num = temp.num;
	}
	//위로 바꿀때
	else if (image[index - 4].num == PuzzleNum - 1 && index > 3)
	{
		temp.num = image[index].num;
		image[index].num = image[index - 4].num;
		image[index - 4].num = temp.num;
	}

	//왼쪽으로 바꿀때
	else if (image[index - 1].num == PuzzleNum - 1 && index % 4 != 0)
	{
		temp.num = image[index].num;
		image[index].num = image[index - 1].num;
		image[index - 1].num = temp.num;
	}

	//오른쪽으로 바꿀때
	else if (image[index + 1].num == PuzzleNum - 1 && index % 4 != 3)
	{
		temp.num = image[index].num;
		image[index].num = image[index + 1].num;
		image[index + 1].num = temp.num;
	}
}

//클리어 조건
BOOL gameStudy::clear(tagImage * image)
{
	int answer = 0;
	for (int i = 0; i < PuzzleNum; i++)
	{
		if (image[i].num == i) answer++;
	}
	if (answer == PuzzleNum) return TRUE;
	else return FALSE;
}
