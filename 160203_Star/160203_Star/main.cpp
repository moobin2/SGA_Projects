#include <iostream>

using namespace std;

int main(void)
{
	char star[6] = "*****";
	char space[6] = "     ";
	char* ptrStar = star;
	char* ptrSpace = space;

	for (int i = 0; i < 5; i++)
	{
		cout << (ptrStar + i) << endl;
	}

	cout << endl;

	for (int i = 4; i >= 0; i--)
	{
		cout << (ptrStar + i) << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << (ptrSpace + 5 - i);
		cout << (ptrStar + i) << endl;
	}

	cout << endl;

	for (int i = 4; i >= 0; i--)
	{
		cout << (ptrSpace + 5 - i);
		cout << (ptrStar + i) << endl;
	}

	return 0;
}