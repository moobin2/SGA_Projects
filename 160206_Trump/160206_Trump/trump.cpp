#include "trump.h"

trump::trump()
{
	srand((unsigned int)time(NULL));

	int card[4][13], tableCard[6];
	int opencard[4][13] = { 0, };
	int number, shape;
	int gameCnt = 0;
	int money = 10000;
	int batting;
	int printCnt = 0;

	//배열 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
			card[i][j] = j + 1;
	}

	//게임 반복문 시작
	while (true)
	{
		cout << "\t\t   < 카운팅 도우미 > " << endl << endl;				//카운팅 배열 and 중복뽑기 방지배열
		cout << "\t    ♥ : ";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (opencard[i][j] == 1) cout << "A ";
				else if (opencard[i][j] == 11) cout << "J ";
				else if (opencard[i][j] == 12) cout << "Q ";
				else if (opencard[i][j] == 13) cout << "K ";
				else if (opencard[i][j] == 0) cout << "  ";
				else cout << opencard[i][j] << " ";
			}
			if(i == 0)	cout << endl << "\t    ♣ : ";
			else if (i == 1)	cout << endl << "\t    ♠ : ";
			else if (i == 2)	cout << endl << "\t    ◆ : ";
		}
		cout << endl << endl << "\t\t   <<< 배팅게임 >>>" << endl << endl << endl;

		//52장중 랜덤수 뽑기
		while (true)
		{
			shape = rand() % 4;		//0~3
			number = rand() % 13;	//0~12
			if (printCnt == 6)												//3장의 모양 숫자 저장하면 탈출
			{
				printCnt = 0;												//계속 뽑아야되므로 초기화
				break;
			}
			if (opencard[shape][number] == card[shape][number]) continue;	//중복자리면 컨티뉴
			else
			{
				opencard[shape][number] = card[shape][number];				//중복자리 아니면 빈배열에 같은위치값 저장 : 카운팅배열 and 랜덤한수 뽑이는거 보이기위해
				tableCard[printCnt] = shape;								//깔리는 카드모양은 0, 2, 4인덱스에 저장
				tableCard[printCnt + 1] = number + 1;						//깔리는 카드숫자는 1, 3, 5인덱스에 저장
				printCnt += 2;												//모양, 숫자 2개씩이므로 2씩 증가
			}
		}

		cout << "\t 처음\t         중간\t          끝" << endl << endl << "\t";

		//랜덤카드 2장 화면에 보이기
		for (int i = 0; i < 4; i = i + 2)									
		{
			if (i == 2) cout << "\t\t??????\t\t";
			if (tableCard[i] == 0)
			{
				if (tableCard[i + 1] == 1)	cout << " ♥ " << "A";
				else if (tableCard[i + 1] == 11)	cout << " ♥ " << "J";
				else if (tableCard[i + 1] == 12)	cout << " ♥ " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " ♥ " << "K";
				else cout << " ♥ " << tableCard[i + 1];
			}
			else if (tableCard[i] == 1)
			{
				if (tableCard[i + 1] == 1)	cout << " ♣ " << "A";
				else if (tableCard[i + 1] == 11)	cout << " ♣ " << "J";
				else if (tableCard[i + 1] == 12)	cout << " ♣ " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " ♣ " << "K";
				else cout << " ♣ " << tableCard[i + 1];
			}
			else if (tableCard[i] == 2)
			{
				if (tableCard[i + 1] == 1)	cout << " ♠ " << "A";
				else if (tableCard[i + 1] == 11)	cout << " ♠ " << "J";
				else if (tableCard[i + 1] == 12)	cout << " ♠ " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " ♠ " << "K";
				else cout << " ♠ " << tableCard[i + 1];
			}
			else if (tableCard[i] == 3)
			{
				if (tableCard[i + 1] == 1)	cout << " ◆ " << "A";
				else if (tableCard[i + 1] == 11)	cout << " ◆ " << "J";
				else if (tableCard[i + 1] == 12)	cout << " ◆ " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " ◆ " << "K";
				else cout << " ◆ " << tableCard[i + 1];
			}
		}

		//소지금액 출력
		cout << endl << endl << endl;
		if (gameCnt == 16) 		cout << "\t\t      마지막 배팅" << endl << endl;
		else cout << "\t\t      " << gameCnt + 1 << "번째 배팅" << endl << endl;
		cout << "소지금액 : " << money << endl << endl;



		//배팅금액 제한
		cout << "배팅금액 : ";
		cin >> batting;
		while (true)
		{
			if (!cin.good() || batting < 100 || batting > money)		//문자입력 or 100 이하 or money초과
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "다시배팅 ( 100 ~ "<< money << " ) : ";
				cin >> batting;
				continue;
			}
			else break;
		}
		cout << endl;

		//결과값 비교
		if ( (tableCard[5] < tableCard[3] && tableCard[5] > tableCard[1]) 
			|| (tableCard[5] < tableCard[1] && tableCard[5] > tableCard[3]) )
		{
			cout << "\t\t나이샤!";
			money += batting;
		}
		else
		{
			cout << "\t\t아까비!";
			money -= batting;
		}

		//정답 출력
		cout << "   정답 카드 : ";
		if (tableCard[4] == 0)
		{
			if (tableCard[5] == 1)	cout << " ♥ " << "A";
			else if (tableCard[5] == 11)	cout << " ♥ " << "J";
			else if (tableCard[5] == 12)	cout << " ♥ " << "Q";
			else if (tableCard[5] == 13)	cout << " ♥ " << "K";
			else cout << " ♥ " << tableCard[5];
		}
		else if (tableCard[4] == 1)
		{
			if (tableCard[5] == 1)	cout << " ♣ " << "A";
			else if (tableCard[5] == 11)	cout << " ♣ " << "J";
	
			else if (tableCard[5] == 12)	cout << " ♣ " << "Q";
			else if (tableCard[5] == 13)	cout << " ♣ " << "K";
			else cout << " ♣ " << tableCard[5];
		}
		else if (tableCard[4] == 2)
		{
			if (tableCard[5] == 1)	cout << " ♠ " << "A";
			else if (tableCard[5] == 11)	cout << " ♠ " << "J";
			else if (tableCard[5] == 12)	cout << " ♠ " << "Q";
			else if (tableCard[5] == 13)	cout << " ♠ " << "K";
			else cout << " ♠ " << tableCard[5];
		}
		else if (tableCard[4] == 3)
		{
			if (tableCard[5] == 1)	cout << " ◆ " << "A";
			else if (tableCard[5] == 11)	cout << " ◆ " << "J";
			else if (tableCard[5] == 12)	cout << " ◆ " << "Q";
			else if (tableCard[5] == 13)	cout << " ◆ " << "K";
			else cout << " ◆ " << tableCard[5];
		}

		Sleep(500);

		//게임 탈출조건
		if (gameCnt == 16)					//횟수 다 사용했을때 카운팅에 쓰인 배열중 0인자리 인덱스 번호 찾아서 출력
		{
			system("cls");
			cout << "\t\t   < 카운팅 도우미 > " << endl << endl;				//카운팅 배열 and 중복뽑기 방지배열
			cout << "\t    ♥ : ";
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (opencard[i][j] == 1) cout << "A ";
					else if (opencard[i][j] == 11) cout << "J ";
					else if (opencard[i][j] == 12) cout << "Q ";
					else if (opencard[i][j] == 13) cout << "K ";
					else if (opencard[i][j] == 0) cout << "  ";
					else cout << opencard[i][j] << " ";
				}
				if (i == 0)	cout << endl << "\t    ♣ : ";
				else if (i == 1)	cout << endl << "\t    ♠ : ";
				else if (i == 2)	cout << endl << "\t    ◆ : ";
			}

			cout << endl << endl << "소지금액 : " << money << endl << endl;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (opencard[i][j] == 0)
					{
						cout << endl << endl << "\t\t 나머지 카드 : ";
						if (i == 0)
						{
							if (card[i][j] == 1)	cout << " ♥ " << "A";
							else if (card[i][j] == 11)	cout << " ♥ " << "J";
							else if (card[i][j] == 12)	cout << " ♥ " << "Q";
							else if (card[i][j] == 13)	cout << " ♥ " << "K";
							else cout << " ♥ " << card[i][j];
						}
						else if (i == 1)
						{
							if (card[i][j] == 1)	cout << " ♣ " << "A";
							else if (card[i][j] == 11)	cout << " ♣ " << "J";
							else if (card[i][j] == 12)	cout << " ♣ " << "Q";
							else if (card[i][j] == 13)	cout << " ♣ " << "K";
							else cout << " ♣ " << card[i][j];
						}
						else if (i == 2)
						{
							if (card[i][j] == 1)	cout << " ♠ " << "A";
							else if (card[i][j] == 11)	cout << " ♠ " << "J";
							else if (card[i][j] == 12)	cout << " ♠ " << "Q";
							else if (card[i][j] == 13)	cout << " ♠ " << "K";
							else cout << " ♠ " << card[i][j];
						}
						else if (i == 3)
						{
							if (card[i][j] == 1)	cout << " ◆ " << "A";
							else if (card[i][j] == 11)	cout << " ◆ " << "J";
							else if (card[i][j] == 12)	cout << " ◆ " << "Q";
							else if (card[i][j] == 13)	cout << " ◆ " << "K";
							else cout << " ◆ " << card[i][j];
						}
					}
				}
			}
			if (money > 10000) cout << endl << endl << "\t   당신은 놀랍게도" << money - 10000 << "원을 따셨습니다." << endl;
			else cout << endl << endl << "\t   당신은 아쉽게도 " << 10000 - money << "원을 잃었습니다." << endl;
			cout << endl << endl;
			break;
		}
		else if (money < 100)			//금액 100원이하일때
		{
			system("cls");
			cout << "\t\t   < 카운팅 도우미 > " << endl << endl;				//카운팅 배열 and 중복뽑기 방지배열
			cout << "\t    ♥ : ";
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (opencard[i][j] == 1) cout << "A ";
					else if (opencard[i][j] == 11) cout << "J ";
					else if (opencard[i][j] == 12) cout << "Q ";
					else if (opencard[i][j] == 13) cout << "K ";
					else if (opencard[i][j] == 0) cout << "  ";
					else cout << opencard[i][j] << " ";
				}
				if (i == 0)	cout << endl << "\t    ♣ : ";
				else if (i == 1)	cout << endl << "\t    ♠ : ";
				else if (i == 2)	cout << endl << "\t    ◆ : ";
			}

			cout << endl << endl << endl;
			if (gameCnt == 16) 		cout << "\t\t      마지막 배팅" << endl << endl;
			else cout << "\t\t      " << gameCnt + 1 << "번째 배팅" << endl << endl;
			cout << "소지금액 : " << money << endl << endl;

			cout << endl << endl << "\t " << money << "원?????? 내가 빙다리 핫바지로 보이냐?" << endl << endl;
			cout << "\t\t<< 파 ~~~~~~~~~~~ 산 >>" << endl;
			break;
		}
		system("cls");
		gameCnt++;
	}
}

trump::~trump()
{
	cout << endl << endl << "\t << 게임은 게임일뿐 도박에 빠지지말자 >>" << endl << endl;
}