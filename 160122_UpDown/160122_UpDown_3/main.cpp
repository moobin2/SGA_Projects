#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	cout << "<과제3> UpDownGame만들기 (10번안에, random함수이용, 0~1000까지)\n" << endl;

	srand((unsigned int)time(NULL)); // 난수 생성

	int randNum = rand() % 1001;     // 1001로 나눔으로써 범위 0~1000으로 제한
	int inputNum, i;

	cout << "\t\t\t업다운게임 시작(" << randNum << ")" << endl << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "입력 : ";
		cin >> inputNum;
		if (randNum == inputNum) // inputNum이 randNum 과 같으면 정답. break로 for문 탈출
		{
			cout << "\t\t\t축하합니다. 정답입니다!" << endl;
			break;
		}
		else if (randNum < inputNum) // inputNum이 randNum 과 크면 "다운"과 남은 횟수 출력
		{
			cout << "\tNO! <다운>\t" << 9 - i << "번 남았습니다." << endl;
		}
		else if (randNum > inputNum) // inputNum이 randNum 과 크면 "업"과 남은 횟수 출력
		{
			cout << "\tNO! <업>\t" << 9 - i << "번 남았습니다." << endl;
		}
		if (i == 9 && randNum != inputNum) // for문 마지막 randNum과 inputNum이 다를 경우
		{
			cout << "\n\t\t\t아쉽게도...다음기회에" << endl << endl;
		}
	}

	cout << "정답 :randNum의 값은 " << randNum << "입니다." << endl;

	return 0;
}