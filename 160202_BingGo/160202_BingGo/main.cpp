#include <iostream>
#include <time.h>

using namespace std;

int bingGoCheck(int arr[]);
void suffle(int arr[]);

int main(void)
{
	srand((unsigned int)time(NULL));

	int BingGo[25];
	int inputArr[25];

	for (int i = 0; i < 25; i++)					//빙고배열 1~25까지 저장
	{
		BingGo[i] = i + 1;
	}

	suffle(BingGo);									//빙고배열 셔플

	for (int i = 0;i < 25;i++)
	{	
		for (int j = 0; j < 25; j++)				//출력 : 5.10.15.20일때 줄바꿈. 
		{
			if (j % 5 == 0) cout << endl << endl << endl;
			if (BingGo[j] == 35) cout << "●\t";	//값이 35면 char형으로 출력
			else cout << BingGo[j] << "\t";							//아니면 int형으로 출력
		}

		if (bingGoCheck(BingGo) >= 5) break;	//화면 클리어때문에 그 상황판 출력까지 하고 브레이크

		cout << endl << endl << endl << i + 1 << "번째 숫자를 입력하세요 : ";
		cin >> inputArr[i];

		system("cls");

		cout<< "입력한 숫자들 : ";				//화면을 지우기때문에 무엇을 입력했는지 화면 출력
		for (int j = 0; j < i + 1; j++)
		{
			cout << inputArr[j] << " ";
		}

		cout << endl;

		for (int j = 0; j < 25; j++)			//입력한 값이 같으면 35로 바꿔 저장
		{
			if (BingGo[j] == inputArr[i])
			{
				BingGo[j] = 35;
			}
		}

		cout << endl << endl << "\t\t\t\t빙고 카운트 : " << bingGoCheck(BingGo) << endl;
	}
	
	return 0;
}

void suffle(int arr[])				//배열 셔플함수
{
	for (int i = 0; i < 50; i++)
	{
		int dest = rand() % 25;
		int sour = rand() % 25;

		int temp = arr[dest];
		arr[dest] = arr[sour];
		arr[sour] = temp;
	}
}

int bingGoCheck(int arr[])			//빙고체크함수
{
	int cnt = 0;
	int cnt2 = 0;
	int bingcnt = 0;

	for (int i = 0; i < 25; i = i + 6)		//왼쪽상단에서 오른쪽 하단 대각선(0,6,12,18,24)
	{
		if (arr[i] == 35)
		{
			cnt++;
			if (cnt == 5) bingcnt++;
		}
	}
	cnt = 0;

	for (int i = 4; i <= 20; i = i + 4)		//오른쪽상단에서 왼쪽하단 대각선(4,8,12,16,20)
	{
		if (arr[i] == 35)
		{
			cnt++;
			if (cnt == 5) bingcnt++;
		}
	}
	cnt = 0;

	for (int i = 0; i < 25; i = i + 5)		// 가로 빙고 체크 (0.1.2.3.4) 체크후 (5.6.7.8.9) 체크
	{										// 처음은 0부터 시작 다음은 5부터 시작이므로 증가값 +5씩
		for (int j = i; j < i + 5; j++)		// 시작은 i = j같을때부터, 값이 같으면 cnt1증가시키고 5가되면 빙고카운트증가
		{
			if (arr[j] == 35) cnt++;
		}
		if (cnt == 5) bingcnt++;
		cnt = 0;							
	}

	for (int i = 0; i < 5; i++)				// 세로 빙고 체크 (0,5,10,15,20) 체크후 (1,6,11,16,21) 체크
	{										// 처음은 0부터 시작 그리고 1씩 증가. 4까지 체크
		for (int j = i; j < 25; j = j + 5)	// 가로와 마찬가지로 5씩 증가해서 
		{
			if (arr[j] == 35) cnt++;
		}
		if (cnt == 5) bingcnt++;
		cnt = 0;
	}

	return bingcnt;
}