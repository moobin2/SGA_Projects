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
	// 색상 초기화
	for (int i = 0; i < CardNum; i += 2)
	{
		inCardState[i].red = inCardState[i + 1].red = 25 + 25 * (i / 2);
		inCardState[i].green = inCardState[i + 1].green = RND->getInt(256);
		inCardState[i].blue = inCardState[i + 1].blue = 255 - 25 * (i / 2);
	}
	// 카드들 상태( 뒤집히고, 정답이 아닌것 )
	for (int i = 0; i < CardNum; i++)
	{
		inCardState[i].CardOpen = Open;
		inCardState[i].answer = false;
	}
	//카운트, 변수들 0
	_clickCount = _TimeCount = first = second = 0;

	//셔플
	shuffle(inCardState);

	//카드 배치
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
	//5초간 보여주고 다 다시 뒤집어주자
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
			//첫클릭 오픈 & 인덱스 저장
			if (PtInRect(&inCardState[i]._rc, _ptMouse) && _clickCount == 0)
			{
				inCardState[i].CardOpen = Open;
				first = i;
				_clickCount++;
			}
			//두번째 클릭 오픈 & 인덱스 저장
			else if (PtInRect(&inCardState[i]._rc, _ptMouse) && _clickCount == 1)
			{
				inCardState[i].CardOpen = Open;
				second = i;
				_clickCount++;
			}
		}
	}

	//2번째 클릭이 되면
	if (_clickCount == 2)
	{
		_TimeCount++;
		if (_TimeCount == 550)	//0.5초 타이머 준후
		{
			if (answerCheck(first, second)) //정답 2개 비교 맞으면 true값으로
			{
				inCardState[first].answer = true;
				inCardState[second].answer = true;
			}
			for (int i = 0; i < CardNum; i++)	//정답이 아닌 카드는 다시 뒤집기. 정답은 냅두기
			{
				if (inCardState[i].answer) inCardState[i].CardOpen = Open;
				else if(!inCardState[i].answer) inCardState[i].CardOpen = nonOpen;
			}
			//카운트 0으로 초기화
			_TimeCount = 500;
			_clickCount = 0;
		}
	}
	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//오픈된 카드는 색깔로, 뒤집힌 카드는 흰색으로
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

//셔플
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

//정답체크
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
