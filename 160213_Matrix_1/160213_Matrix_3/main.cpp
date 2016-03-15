#include <iostream>

using namespace std;

int main(void)
{
	int matrix[20][20] = { 0, };
	int cnt = 1;
	int repeat;

	cout << "È½¼ö ÀÔ·Â : ";
	cin >> repeat;

	for (int i = 0; i < repeat; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = repeat - 1; j >= 0; j--)
			{
				matrix[i][j] = cnt;
				cnt++;
			}
		}
		else
		{
			for (int j = 0; j < repeat; j++)
			{
				matrix[i][j] = cnt;
				cnt++;
			}
		}
	}

	cout << endl;

	for (int i = 0; i < repeat; i++)
	{
		for (int j = 0; j < repeat; j++)
		{
			if (matrix[i][j] != 0) cout << matrix[i][j] << "\t";
			else cout << " \t";
		}
		cout << endl << endl;
	}

	return 0;
}