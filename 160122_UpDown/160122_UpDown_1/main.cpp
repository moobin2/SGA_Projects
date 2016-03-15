#include <iostream>

using namespace std;

int main(void)
{
	cout << "<과제2> 0~10000까지의 2^n 출력" << endl;

	int a = 1, b, c;

	while (a <= 10000)           //a가 10000보다 작거나 같을때 계속 반복
	{
		cout << a << endl;       //2^0=1 이므로 처음 a=1일때 처음 출력후 2배씩 반복
		a = a * 2;
	}

	cout << "------------" << endl;

	for (b = 1; b <= 10000; b++) //b = 1부터 10000보다 작거나 같을때까지 출력.
	{
		cout << b << endl;       //2^0=1 이므로 처음 b=1일때 처음 출력후 2배씩 반복
		b = (b * 2) - 1;         //증감문이 b++ 이므로 2배후 -1해줌
	}

	cout << "------------" << endl;

	for (c = 1; c <= 10000; c = c * 2)  //c = 1부터 10000보다 작을때까지. 2배씩 반복
	{
		cout << c << endl;
	}
	return 0;
}