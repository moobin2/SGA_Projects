#include <iostream>

using namespace std;

int main(void)
{
	cout << "<����1> 0~99������ ¦�� ���" << endl;

	int a;
	int cnt = 0;

	for (a = 0; a < 100; a++)    // ������ 0~99���� , 1�� �����ϸ鼭 �ݺ�
	{
		if (a % 2 == 0)          // 2�� ���� �������� 0�̸� ���, �ƴϸ� �н�
		{
			cout << a << "\t";
			cnt++;
		}
		if (cnt % 5 == 0) cout << endl;
	}

	return 0;
}