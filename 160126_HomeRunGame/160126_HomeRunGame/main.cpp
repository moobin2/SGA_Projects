#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	int randNum1, randNum2, randNum3;
	int answer[3];
	int input[3];
	int strike, ball, out;

	srand((unsigned int)time(NULL));		//�ð��� ���� �������� ����

	while (true)							//true������ ���ѷ���
	{
		randNum1 = rand() % 10;				//������(0~9)���� ������ randNum�� 0�� �ƴϸ� ���� Ż��
		if (randNum1 != 0) break;
	}
	while (true)
	{
		randNum2 = rand() % 10;
		if (randNum2 != randNum1) break;	//randNum2�� randNum1�� �ٸ��� ����Ż��
	}
	while (true)
	{
		randNum3 = rand() % 10;
		if (randNum3 != randNum1 && randNum3 != randNum2) break;	//randNum3�� randNum1,randNum2�� �ٸ��� ����Ż��
	}

	answer[0] = randNum1;
	answer[1] = randNum2;
	answer[2] = randNum3;		//����ϱ� ���� ������ �������� �迭�� ����

	cout << "\t\t\tHomeRunGame Start!!" << "(" << randNum1 << randNum2 << randNum3 << ")" << endl;
	cout << endl;

	for (int i = 0; i < 10; i++)	//��ȸ�� 10��
	{
		strike = 0;					//strike, ball, out �ʱ�ȭ
		ball = 0;
		out = 0;
		for (int j = 0; j < 3; j++)	//���� �Էº�
		{
			cout << "���ڸ� �Է��غ������� : ";
			cin >> input[j];
		}
		for (int j = 0; j < 3; j++)
		{
			if (answer[j] == input[j]) strike++;	//�� �迭�� ������ġ�� �������� ������ strike�� ����
			for (int k = 0; k < 3; k++)
			{
				if (answer[j] == input[k] && j != k) ball++;	//���� ��ġ�� �����ϰ� �������� ������ ball�� ����
			}
			out = 3 - strike - ball;	//�ƿ��� 3���� strike�� ball���� ����
		}
		cout << endl << "\t\tStrike : " << strike << "\tBall:" << ball << "\tOut : " << out << endl;
		if (strike == 3)	//strike���� 3�̶�� �����̹Ƿ� ���� Ż��
		{
			cout << endl << "\t\t�����Դϴ�. ��ó�� �ȶ��Ͻñ���?!" << endl << endl;
			break;
		}
		else if (input[0] < 0 || input[1] < 0 || input[2] < 0) //���࿡ �ϳ��� ������ �Է½� i�� �ʱ�ȭ
		{
			i = -1;
			cout << "\t\t\t���� Ƚ���� �ʱ�ȭ �Ͽ����ϴ�." << endl << endl;
		}
		else cout << "\t\t\t<" << 9 - i << "> �� ���ҽ��ϴ�." << endl << endl;	//�ƴ϶�� ��� �ݺ�
	}
	cout << "������ " << randNum1 << randNum2 << randNum3 << "�̾����ϴ�. " << endl;

	return 0;
}