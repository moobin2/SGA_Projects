#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

void Shuffle(int arr[]);
int ZeroPosition(int arr[]);
void PointMove(int arr[], int input, int pos);
bool Check(int arr[]);

int main(void)
{
	srand((unsigned int)time(NULL));

	int Puzzle[25];
	int answer[24];
	int inputNum, position;
	int count = 0;

	// ���� �迭 �ʱ�ȭ �κ�. �ε��� �������� ���� 0���� ���� �ʱ�ȭ��.
	for (int i = 0; i < 24; i++)			
	{
		Puzzle[i] = i + 1;
		answer[i] = i + 1;
	}
	Puzzle[24] = 0;

	Shuffle(Puzzle);

	while (true)
	{
		cout << "\t<< ���� ���� >> " << endl << endl;
		cout << "  4:�� 6:�� 8:�� 2:�� " << "<" << count << "> �� �̵�" << endl;

		//�迭 ���
		for (int i = 0; i < 25; i++)		
		{
			if (i % 5 == 0) cout << endl << endl;
			if (Puzzle[i] == 0) cout << "��" << "\t";
			else cout << Puzzle[i] << "\t";
		}		

		// 1~24 ���� �������� �ݺ��� Ż��.
		if (Check(Puzzle) == TRUE)		
		{
			cout << endl << endl << "�� ~~ ���� ���߼̽� ��ī��ī" << endl;
			break;
		}

		//0�� �ε��� ��ȣã��
		position = ZeroPosition(Puzzle);	

		cout << endl << endl << "���� �Է� : ";
		cin >> inputNum;

		//�Է¼��� Ȯ��
		while (true)
		{
			if (!cin.good() || (inputNum != 2 && inputNum != 4 && inputNum != 6 && inputNum != 8)\
				|| (inputNum == 4 && position % 5 == 0) || (inputNum == 6 && position % 5 == 4)\
				|| (inputNum == 8 && position < 5) || (inputNum == 2 && position > 19))					// �����Է������� || 2,4,6,8�� �ƴ� �ٸ��� �Է�������
			{																							// �����ִºκ� �������Ҷ�
				cin.clear();																			
				cin.ignore(INT_MAX, '\n');
				cout << "�ٽ� �Է� : ";
				cin >> inputNum;
				continue;
			}
			else break;
		}

		system("cls");

		PointMove(Puzzle, inputNum, position);
		
		count++;
	}
	return 0;
}

void Shuffle(int arr[])		// �迭 ����
{
	int dest, sour, temp;

	for (int i = 0; i < 50; i++)
	{
		dest = rand() % 24; // ������ 0~23���� ����.
		sour = rand() % 24;

		temp = arr[dest];
		arr[dest] = arr[sour]; 
		arr[sour] = temp;
	}
}

int ZeroPosition(int arr[])		// 0�� ��ġ ã��
{
	int zero;

	for (int i = 0; i < 25; i++)
	{
		if (arr[i] == 0) zero = i;
	}
	return zero;
}

void PointMove(int arr[], int input, int pos)		// �����̴� ������ �迭���� ����
{
	int temp;

	if (input == 4)									// ���� : �ε��� -1 ��°�� ��ġ ��ȯ
	{
		temp = arr[pos];
		arr[pos] = arr[pos - 1];
		arr[pos - 1] = temp;
	}
	else if (input == 6)							// ������ : �ε��� +1 ��°�� ��ġ ��ȯ
	{
		temp = arr[pos];
		arr[pos] = arr[pos + 1];
		arr[pos + 1] = temp;
	}
	else if (input == 8)							// ���� : �ε��� -5 ��°�� ��ġ ��ȯ
	{
		temp = arr[pos];
		arr[pos] = arr[pos - 5];
		arr[pos - 5] = temp;
	}
	else if (input == 2)							// �Ʒ��� : �ε��� +5 ��°�� ��ġ ��ȯ
	{
		temp = arr[pos];
		arr[pos] = arr[pos + 5];
		arr[pos + 5] = temp;
	}
}

bool Check(int arr[])					// ����迭�� ��ġ�ϴ��� Ȯ��.
{
	int cnt = 0;
	for (int i = 0; i < 24; i++)					//0~24�迭 ��δ� ��ġ�ϸ� true���� / �ƴϸ� false ����
	{
		if (arr[i] == i+1) cnt++;
	}
	if (cnt == 24) return TRUE;
	else return FALSE;
}