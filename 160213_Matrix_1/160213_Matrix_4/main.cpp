#include <iostream>

using namespace std;

int main(void)
{
	int matrix[5][5] = { 0, };
	int cnt = 1;
	int direction = 0;
	int oddDirction = 0;
	int repeat;
	int printCnt;
	int w = 0, h = 0;

	cout << "х╫╪Ж ют╥б : ";
	cin >> repeat;
	printCnt = repeat;

	for (int i = 0; cnt < printCnt * printCnt + 1; i++)
	{
		if (direction == 0)
		{
			for (int j = 0; j < repeat; j++)
			{
				matrix[h][w] = cnt;
				w++;
				cnt++;
			}
			w--;
			h++;
			direction++;
			oddDirction++;
			if (oddDirction % 2 == 1) repeat--;
		}
		else if (direction == 1)
		{
			for (int j = 0; j < repeat; j++)
			{
				matrix[h][w] = cnt;
				h++;
				cnt++;
			}
			h--;
			w--;
			direction++;
			oddDirction++;
			if (oddDirction % 2 == 1) repeat--;
		}
		else if (direction == 2)
		{
			for (int j = 0; j < repeat; j++)
			{
				matrix[h][w] = cnt;
				w--;
				cnt++;
			}
			w++;
			h--;
			direction++;
			oddDirction++;
			if (oddDirction % 2 == 1) repeat--;
		}
		else if (direction == 3)
		{
			for (int j = 0; j < repeat; j++)
			{
				matrix[h][w] = cnt;
				h--;
				cnt++;
			}
			h++;
			w++;
			direction = 0;
			oddDirction++;
			if (oddDirction % 2 == 1) repeat--;
		}
	}

	cout << endl;

	for (int i = 0; i < printCnt; i++)
	{
		for (int j = 0; j < printCnt; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}

	return 0;
}