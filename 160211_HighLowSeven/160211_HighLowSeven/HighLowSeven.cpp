#include "HighLowSeven.h"

HighLowSeven::HighLowSeven()
{
	srand((unsigned int)time(NULL));
	money = 10000;
	int num;
	int dest, sour, betting;
	int cnt = 0;
	char type;

	for (int i = 0; i < 52; i++)
	{
		num = i / 13;
		switch (num)
		{
		case 0:
			trump[i].shape = "♠";
			break;
		case 1:
			trump[i].shape = "◆";
			break;
		case 2:
			trump[i].shape = "♥";
			break;
		case 3:
			trump[i].shape = "♣";
			break;
		}
		num = i % 13 + 1;
		trump[i].number = num;
	}

	for (int i = 0; i < 200; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		Card temp = trump[dest];
		trump[dest] = trump[sour];
		trump[sour] = temp;
	}

	while (true)
	{
		system("cls");	

		cout << endl << "\t\t\t    << HighLowSeven >>" << endl << endl;
		cout << "\t┌──────────────────────────┐" << endl;
		cout << "\t│           배팅종류 : High , Low , Seven            │" << endl;
		cout << "\t│배팅방법 : High -> 8 , Low -> 2 , Seven -> 5 만 입력│" << endl;
		cout << "\t│배팅금액 : 무조건 100원 이상배팅, Seven성공시 13배!!│" << endl;
		cout << "\t└──────────────────────────┘" << endl << endl;
		if (cnt == 46) cout << "\t\t\t 마지막 시도" << endl << endl;
		else cout << "\t\t\t\t" << cnt + 1 << "번째 시도" << endl << endl;

		cout << "\t\t";
		for (int i = cnt; i < cnt + 5; i++)
		{
			CardPrint(i);
			if (i == cnt + 4) cout << "XXXX" << endl << endl;
		}

		cout << "소지금액 : " << money << endl << endl;
		cout << "High(8), Low(2), Seven(5)" << endl << endl;
		type = _getch();

		while (true)
		{
			if (type != 56 && type != 53 && type != 50)
			{
				cout << "다시입력하세요 High(8), Low(2), Seven(5) " << endl;
				type = _getch();
				continue;
			}
			break;
		}

		cout << "배팅금액 : ";
		cin >> betting;
		while (true)
		{
			if (!cin.good() || betting < 100 || betting > money)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "다시배팅 ( 100 ~ " << money << " ) : ";
				cin >> betting;
				continue;
			}
			break;
		}

		switch (type)
		{
		case 56:
			if (trump[cnt + 5].number > 7)
			{
				cout << endl << "\t\t\t      오올 찍신?" << endl;
				money += betting;
				Sleep(1500);
			}
			else
			{
				cout << endl << "\t\t\t      ㅉㅉ 잘찍어봐" << endl;
				money -= betting;
				Sleep(1500);
			}
			break;
		case 50:
			if (trump[cnt + 5].number < 7)
			{
				cout << endl << "\t\t\t      오올 찍신?" << endl;
				money += betting;
				Sleep(1500);
			}
			else
			{
				cout << endl << "\t\t\t      ㅉㅉ 잘찍어봐" << endl;
				money -= betting;
				Sleep(1500);
			}
			break;
		case 53:
			if (trump[cnt + 5].number == 7)
			{
				cout << endl << "\t\t\t      예아!! 잭팟!!!" << endl;
				money = money + betting * 13;
				Sleep(1500);
			}
			else
			{
				cout << endl << "\t\t\t      ㅉㅉ 잘찍어봐" << endl;
				money -= betting;
				Sleep(1500);
			}
			break;
		}

		if (cnt == 46)					//횟수 다 사용했을때 카운팅에 쓰인 배열중 0인자리 인덱스 번호 찾아서 출력
		{
			cout << endl << endl << "소지금액 : " << money << endl << endl;

			if (money > 10000) cout << endl << endl << "\t\t   당신은 놀랍게도" << money - 10000 << "원을 따셨습니다." << endl;
			else cout << endl << endl << "\t\t   당신은 아쉽게도 " << 10000 - money << "원을 잃었습니다." << endl;
			cout << endl << endl;
			break;
		}
		else if (money < 100)			//금액 100원이하일때
		{
			cout << endl << endl << "소지금액 : " << money << endl << endl;
			cout << endl << "\t\t " << money << "원?????? 내가 빙다리 핫바지로 보이냐?" << endl << endl;
			cout << "\t\t\t<< 파 ~~~~~~~~~~~ 산 >>" << endl;
			break;
		}
		cnt++;
	}
}


HighLowSeven::~HighLowSeven()
{
}

void HighLowSeven::CardPrint(int num)
{
	switch (trump[num].number)
	{
	case 1:
		cout << trump[num].shape << "A\t";
		break;
	case 11:
		cout << trump[num].shape << "J\t";
		break;
	case 12:
		cout << trump[num].shape << "Q\t";
		break;
	case 13:
		cout << trump[num].shape << "K\t";
		break;
	default:
		cout << trump[num].shape << trump[num].number << "\t";
		break;
	}
}