#include <iostream>
#include <time.h>

using namespace std;

int bingGoCheck(int arr[]);
void suffle(int arr[]);

int main(void)
{
	srand((unsigned int)time(NULL));

	int BingGo[25];
	int inputArr[25];

	for (int i = 0; i < 25; i++)					//����迭 1~25���� ����
	{
		BingGo[i] = i + 1;
	}

	suffle(BingGo);									//����迭 ����

	for (int i = 0;i < 25;i++)
	{	
		for (int j = 0; j < 25; j++)				//��� : 5.10.15.20�϶� �ٹٲ�. 
		{
			if (j % 5 == 0) cout << endl << endl << endl;
			if (BingGo[j] == 35) cout << "��\t";	//���� 35�� char������ ���
			else cout << BingGo[j] << "\t";							//�ƴϸ� int������ ���
		}

		if (bingGoCheck(BingGo) >= 5) break;	//ȭ�� Ŭ������� �� ��Ȳ�� ��±��� �ϰ� �극��ũ

		cout << endl << endl << endl << i + 1 << "��° ���ڸ� �Է��ϼ��� : ";
		cin >> inputArr[i];

		system("cls");

		cout<< "�Է��� ���ڵ� : ";				//ȭ���� ����⶧���� ������ �Է��ߴ��� ȭ�� ���
		for (int j = 0; j < i + 1; j++)
		{
			cout << inputArr[j] << " ";
		}

		cout << endl;

		for (int j = 0; j < 25; j++)			//�Է��� ���� ������ 35�� �ٲ� ����
		{
			if (BingGo[j] == inputArr[i])
			{
				BingGo[j] = 35;
			}
		}

		cout << endl << endl << "\t\t\t\t���� ī��Ʈ : " << bingGoCheck(BingGo) << endl;
	}
	
	return 0;
}

void suffle(int arr[])				//�迭 �����Լ�
{
	for (int i = 0; i < 50; i++)
	{
		int dest = rand() % 25;
		int sour = rand() % 25;

		int temp = arr[dest];
		arr[dest] = arr[sour];
		arr[sour] = temp;
	}
}

int bingGoCheck(int arr[])			//����üũ�Լ�
{
	int cnt = 0;
	int cnt2 = 0;
	int bingcnt = 0;

	for (int i = 0; i < 25; i = i + 6)		//���ʻ�ܿ��� ������ �ϴ� �밢��(0,6,12,18,24)
	{
		if (arr[i] == 35)
		{
			cnt++;
			if (cnt == 5) bingcnt++;
		}
	}
	cnt = 0;

	for (int i = 4; i <= 20; i = i + 4)		//�����ʻ�ܿ��� �����ϴ� �밢��(4,8,12,16,20)
	{
		if (arr[i] == 35)
		{
			cnt++;
			if (cnt == 5) bingcnt++;
		}
	}
	cnt = 0;

	for (int i = 0; i < 25; i = i + 5)		// ���� ���� üũ (0.1.2.3.4) üũ�� (5.6.7.8.9) üũ
	{										// ó���� 0���� ���� ������ 5���� �����̹Ƿ� ������ +5��
		for (int j = i; j < i + 5; j++)		// ������ i = j����������, ���� ������ cnt1������Ű�� 5���Ǹ� ����ī��Ʈ����
		{
			if (arr[j] == 35) cnt++;
		}
		if (cnt == 5) bingcnt++;
		cnt = 0;							
	}

	for (int i = 0; i < 5; i++)				// ���� ���� üũ (0,5,10,15,20) üũ�� (1,6,11,16,21) üũ
	{										// ó���� 0���� ���� �׸��� 1�� ����. 4���� üũ
		for (int j = i; j < 25; j = j + 5)	// ���ο� ���������� 5�� �����ؼ� 
		{
			if (arr[j] == 35) cnt++;
		}
		if (cnt == 5) bingcnt++;
		cnt = 0;
	}

	return bingcnt;
}