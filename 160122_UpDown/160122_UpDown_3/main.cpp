#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	cout << "<����3> UpDownGame����� (10���ȿ�, random�Լ��̿�, 0~1000����)\n" << endl;

	srand((unsigned int)time(NULL)); // ���� ����

	int randNum = rand() % 1001;     // 1001�� �������ν� ���� 0~1000���� ����
	int inputNum, i;

	cout << "\t\t\t���ٿ���� ����(" << randNum << ")" << endl << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "�Է� : ";
		cin >> inputNum;
		if (randNum == inputNum) // inputNum�� randNum �� ������ ����. break�� for�� Ż��
		{
			cout << "\t\t\t�����մϴ�. �����Դϴ�!" << endl;
			break;
		}
		else if (randNum < inputNum) // inputNum�� randNum �� ũ�� "�ٿ�"�� ���� Ƚ�� ���
		{
			cout << "\tNO! <�ٿ�>\t" << 9 - i << "�� ���ҽ��ϴ�." << endl;
		}
		else if (randNum > inputNum) // inputNum�� randNum �� ũ�� "��"�� ���� Ƚ�� ���
		{
			cout << "\tNO! <��>\t" << 9 - i << "�� ���ҽ��ϴ�." << endl;
		}
		if (i == 9 && randNum != inputNum) // for�� ������ randNum�� inputNum�� �ٸ� ���
		{
			cout << "\n\t\t\t�ƽ��Ե�...������ȸ��" << endl << endl;
		}
	}

	cout << "���� :randNum�� ���� " << randNum << "�Դϴ�." << endl;

	return 0;
}