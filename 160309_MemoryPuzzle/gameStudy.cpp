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
	
	int j = 0;
	// ���� �ʱ�ȭ
	for (int i = 0; i < CardNum; i += 2)
	{
		inCardState[i].red = inCardState[i + 1].red = 25 + 25 * (i / 2);
		inCardState[i].green = inCardState[i + 1].green = RND->getInt(256);
		inCardState[i].blue = inCardState[i + 1].blue = 255 - 25 * (i / 2);
	}
	// ī��� ����( ��������, ������ �ƴѰ� )
	for (int i = 0; i < CardNum; i++)
	{
		inCardState[i].CardOpen = Open;
		inCardState[i].answer = false;
	}
	//ī��Ʈ, ������ 0
	_clickCount = _TimeCount = first = second = 0;

	//����
	shuffle(inCardState);

	//ī�� ��ġ
	for (int i = 0; i < CardNum; i++)
	{
		if ( i < 6 ) inCardState[i]._rc = RectMakeCenter(WINSIZEX / 5 + i * 100, WINSIZEY / 5 + 100 * j, 70, 100);
		else if (i >= 6 && i < 12)
		{
			j = 1;
			inCardState[i]._rc = RectMakeCenter(WINSIZEX / 5 + (i - 6) * 100, WINSIZEY / 5 + 150 * j, 70, 100);
		}
		else if (i >= 12 && i < 18)
		{
			j = 2;
			inCardState[i]._rc = RectMakeCenter(WINSIZEX / 5 + (i - 12) * 100, WINSIZEY / 5 + 150 * j, 70, 100);
		}
	}
	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	//5�ʰ� �����ְ� �� �ٽ� ����������
	if (_TimeCount < 500)
	{
		_TimeCount++;
		if (_TimeCount == 500)
		{
			for (int i = 0; i < CardNum; i++)
			{
				inCardState[i].CardOpen = nonOpen;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && _clickCount < 2)
	{
		for (int i = 0; i < CardNum; i++)
		{
			//ùŬ�� ���� & �ε��� ����
			if (PtInRect(&inCardState[i]._rc, _ptMouse) && _clickCount == 0)
			{
				inCardState[i].CardOpen = Open;
				first = i;
				_clickCount++;
			}
			//�ι�° Ŭ�� ���� & �ε��� ����
			else if (PtInRect(&inCardState[i]._rc, _ptMouse) && _clickCount == 1)
			{
				inCardState[i].CardOpen = Open;
				second = i;
				_clickCount++;
			}
		}
	}

	//2��° Ŭ���� �Ǹ�
	if (_clickCount == 2)
	{
		_TimeCount++;
		if (_TimeCount == 550)	//0.5�� Ÿ�̸� ����
		{
			if (answerCheck(first, second)) //���� 2�� �� ������ true������
			{
				inCardState[first].answer = true;
				inCardState[second].answer = true;
			}
			for (int i = 0; i < CardNum; i++)	//������ �ƴ� ī��� �ٽ� ������. ������ ���α�
			{
				if (inCardState[i].answer) inCardState[i].CardOpen = Open;
				else if(!inCardState[i].answer) inCardState[i].CardOpen = nonOpen;
			}
			//ī��Ʈ 0���� �ʱ�ȭ
			_TimeCount = 500;
			_clickCount = 0;
		}
	}
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//���µ� ī��� �����, ������ ī��� �������
	for (int i = 0; i < 18; i++)
	{
		if (inCardState[i].CardOpen == Open)
		{
			HBRUSH nowBrush, oldBrush;
			nowBrush = CreateSolidBrush(RGB(inCardState[i].red, inCardState[i].green, inCardState[i].blue));
			oldBrush = (HBRUSH)SelectObject(hdc, nowBrush);
			Rectangle(hdc, inCardState[i]._rc.left, inCardState[i]._rc.top, inCardState[i]._rc.right, inCardState[i]._rc.bottom);
			SelectObject(hdc, oldBrush);
			DeleteObject(nowBrush);
		}
		else Rectangle(hdc, inCardState[i]._rc.left, inCardState[i]._rc.top, inCardState[i]._rc.right, inCardState[i]._rc.bottom);
	}
}

//����
void gameStudy::shuffle(Card * card)
{
	int dest, sour;
	Card temp;
	for (int i = 0; i < CardNum; i++)
	{
		card[i]._number = i;
	}

	for (int i = 0; i < 30; i++)
	{
		dest = RND->getInt(18);
		sour = RND->getInt(18);
		
		temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;
	}
}

//����üũ
BOOL gameStudy::answerCheck(int first, int Second)
{
	if ( inCardState[first].red == inCardState[Second].red )
	{
		inCardState[first].answer = true;
		inCardState[Second].answer = true;
		return TRUE;
	}
	else return FALSE;
}
