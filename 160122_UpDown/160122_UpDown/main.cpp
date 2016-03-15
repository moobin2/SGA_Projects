#include <iostream>

using namespace std;

int main(void)
{
	cout << "<과제1> 0~99까지의 짝수 출력" << endl;

	int a;
	int cnt = 0;

	for (a = 0; a < 100; a++)    // 범위가 0~99까지 , 1씩 증가하면서 반복
	{
		if (a % 2 == 0)          // 2로 나눈 나머지가 0이면 출력, 아니면 패스
		{
			cout << a << "\t";
			cnt++;
		}
		if (cnt % 5 == 0) cout << endl;
	}

	return 0;
}