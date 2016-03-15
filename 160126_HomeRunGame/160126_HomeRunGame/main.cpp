#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	int randNum1, randNum2, randNum3;
	int answer[3];
	int input[3];
	int strike, ball, out;

	srand((unsigned int)time(NULL));		//시간에 따른 랜덤난수 생성

	while (true)							//true값으로 무한루프
	{
		randNum1 = rand() % 10;				//랜덤값(0~9)까지 생성후 randNum이 0이 아니면 루프 탈출
		if (randNum1 != 0) break;
	}
	while (true)
	{
		randNum2 = rand() % 10;
		if (randNum2 != randNum1) break;	//randNum2가 randNum1과 다르면 루프탈출
	}
	while (true)
	{
		randNum3 = rand() % 10;
		if (randNum3 != randNum1 && randNum3 != randNum2) break;	//randNum3가 randNum1,randNum2와 다르면 루프탈출
	}

	answer[0] = randNum1;
	answer[1] = randNum2;
	answer[2] = randNum3;		//계산하기 쉽게 생성된 랜덤값을 배열에 저장

	cout << "\t\t\tHomeRunGame Start!!" << "(" << randNum1 << randNum2 << randNum3 << ")" << endl;
	cout << endl;

	for (int i = 0; i < 10; i++)	//기회는 10번
	{
		strike = 0;					//strike, ball, out 초기화
		ball = 0;
		out = 0;
		for (int j = 0; j < 3; j++)	//숫자 입력부
		{
			cout << "숫자를 입력해보시지요 : ";
			cin >> input[j];
		}
		for (int j = 0; j < 3; j++)
		{
			if (answer[j] == input[j]) strike++;	//각 배열의 같은위치게 같은값이 있으면 strike값 증가
			for (int k = 0; k < 3; k++)
			{
				if (answer[j] == input[k] && j != k) ball++;	//같은 위치를 제외하고 같은값이 있으면 ball값 증가
			}
			out = 3 - strike - ball;	//아웃은 3에서 strike와 ball값을 빼줌
		}
		cout << endl << "\t\tStrike : " << strike << "\tBall:" << ball << "\tOut : " << out << endl;
		if (strike == 3)	//strike값이 3이라면 정답이므로 루프 탈출
		{
			cout << endl << "\t\t정답입니다. 저처럼 똑똑하시군요?!" << endl << endl;
			break;
		}
		else if (input[0] < 0 || input[1] < 0 || input[2] < 0) //만약에 하나라도 음수를 입력시 i를 초기화
		{
			i = -1;
			cout << "\t\t\t도전 횟수를 초기화 하였습니다." << endl << endl;
		}
		else cout << "\t\t\t<" << 9 - i << "> 번 남았습니다." << endl << endl;	//아니라면 계속 반복
	}
	cout << "정답은 " << randNum1 << randNum2 << randNum3 << "이었습니다. " << endl;

	return 0;
}