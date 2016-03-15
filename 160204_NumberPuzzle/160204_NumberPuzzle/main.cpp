#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

void Shuffle(int arr[]);
int ZeroPosition(int arr[]);
void PointMove(int arr[], int input, int pos);
bool Check(int arr[]);

int main(void)
{
	srand((unsigned int)time(NULL));

	int Puzzle[25];
	int answer[24];
	int inputNum, position;
	int count = 0;

	// 퍼즐 배열 초기화 부분. 인덱스 마지막만 빼서 0으로 따로 초기화함.
	for (int i = 0; i < 24; i++)			
	{
		Puzzle[i] = i + 1;
		answer[i] = i + 1;
	}
	Puzzle[24] = 0;

	Shuffle(Puzzle);

	while (true)
	{
		cout << "\t<< 숫자 퍼즐 >> " << endl << endl;
		cout << "  4:← 6:→ 8:↑ 2:↓ " << "<" << count << "> 번 이동" << endl;

		//배열 출력
		for (int i = 0; i < 25; i++)		
		{
			if (i % 5 == 0) cout << endl << endl;
			if (Puzzle[i] == 0) cout << "●" << "\t";
			else cout << Puzzle[i] << "\t";
		}		

		// 1~24 정답 마췄을때 반복문 탈출.
		if (Check(Puzzle) == TRUE)		
		{
			cout << endl << endl << "올 ~~ 퍼즐 마추셨심 추카추카" << endl;
			break;
		}

		//0의 인덱스 번호찾기
		position = ZeroPosition(Puzzle);	

		cout << endl << endl << "숫자 입력 : ";
		cin >> inputNum;

		//입력숫자 확인
		while (true)
		{
			if (!cin.good() || (inputNum != 2 && inputNum != 4 && inputNum != 6 && inputNum != 8)\
				|| (inputNum == 4 && position % 5 == 0) || (inputNum == 6 && position % 5 == 4)\
				|| (inputNum == 8 && position < 5) || (inputNum == 2 && position > 19))					// 문자입력했을때 || 2,4,6,8이 아닌 다른수 입력했을때
			{																							// 막혀있는부분 갈려고할때
				cin.clear();																			
				cin.ignore(INT_MAX, '\n');
				cout << "다시 입력 : ";
				cin >> inputNum;
				continue;
			}
			else break;
		}

		system("cls");

		PointMove(Puzzle, inputNum, position);
		
		count++;
	}
	return 0;
}

void Shuffle(int arr[])		// 배열 섞기
{
	int dest, sour, temp;

	for (int i = 0; i < 50; i++)
	{
		dest = rand() % 24; // 범위는 0~23까지 나옴.
		sour = rand() % 24;

		temp = arr[dest];
		arr[dest] = arr[sour]; 
		arr[sour] = temp;
	}
}

int ZeroPosition(int arr[])		// 0의 위치 찾기
{
	int zero;

	for (int i = 0; i < 25; i++)
	{
		if (arr[i] == 0) zero = i;
	}
	return zero;
}

void PointMove(int arr[], int input, int pos)		// 움직이는 방향대로 배열순서 변경
{
	int temp;

	if (input == 4)									// 왼쪽 : 인덱스 -1 번째와 위치 교환
	{
		temp = arr[pos];
		arr[pos] = arr[pos - 1];
		arr[pos - 1] = temp;
	}
	else if (input == 6)							// 오른쪽 : 인덱스 +1 번째와 위치 교환
	{
		temp = arr[pos];
		arr[pos] = arr[pos + 1];
		arr[pos + 1] = temp;
	}
	else if (input == 8)							// 위쪽 : 인덱스 -5 번째와 위치 교환
	{
		temp = arr[pos];
		arr[pos] = arr[pos - 5];
		arr[pos - 5] = temp;
	}
	else if (input == 2)							// 아래쪽 : 인덱스 +5 번째와 위치 교환
	{
		temp = arr[pos];
		arr[pos] = arr[pos + 5];
		arr[pos + 5] = temp;
	}
}

bool Check(int arr[])					// 정답배열과 일치하는지 확인.
{
	int cnt = 0;
	for (int i = 0; i < 24; i++)					//0~24배열 모두다 일치하면 true리턴 / 아니면 false 리턴
	{
		if (arr[i] == i+1) cnt++;
	}
	if (cnt == 24) return TRUE;
	else return FALSE;
}