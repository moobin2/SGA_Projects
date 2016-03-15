#include "HighLowSeven.h"

HighLowSeven::HighLowSeven()
{
	srand((unsigned int)time(NULL));
	money = 10000;
	int num;
	int dest, sour, betting;
	int cnt = 0;
	char type;

	for (int i = 0; i < 52; i++)
	{
		num = i / 13;
		switch (num)
		{
		case 0:
			trump[i].shape = "��";
			break;
		case 1:
			trump[i].shape = "��";
			break;
		case 2:
			trump[i].shape = "��";
			break;
		case 3:
			trump[i].shape = "��";
			break;
		}
		num = i % 13 + 1;
		trump[i].number = num;
	}

	for (int i = 0; i < 200; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		Card temp = trump[dest];
		trump[dest] = trump[sour];
		trump[sour] = temp;
	}

	while (true)
	{
		system("cls");	

		cout << endl << "\t\t\t    << HighLowSeven >>" << endl << endl;
		cout << "\t��������������������������������������������������������" << endl;
		cout << "\t��           �������� : High , Low , Seven            ��" << endl;
		cout << "\t�����ù�� : High -> 8 , Low -> 2 , Seven -> 5 �� �Է¦�" << endl;
		cout << "\t�����ñݾ� : ������ 100�� �̻����, Seven������ 13��!!��" << endl;
		cout << "\t��������������������������������������������������������" << endl << endl;
		if (cnt == 46) cout << "\t\t\t ������ �õ�" << endl << endl;
		else cout << "\t\t\t\t" << cnt + 1 << "��° �õ�" << endl << endl;

		cout << "\t\t";
		for (int i = cnt; i < cnt + 5; i++)
		{
			CardPrint(i);
			if (i == cnt + 4) cout << "XXXX" << endl << endl;
		}

		cout << "�����ݾ� : " << money << endl << endl;
		cout << "High(8), Low(2), Seven(5)" << endl << endl;
		type = _getch();

		while (true)
		{
			if (type != 56 && type != 53 && type != 50)
			{
				cout << "�ٽ��Է��ϼ��� High(8), Low(2), Seven(5) " << endl;
				type = _getch();
				continue;
			}
			break;
		}

		cout << "���ñݾ� : ";
		cin >> betting;
		while (true)
		{
			if (!cin.good() || betting < 100 || betting > money)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "�ٽù��� ( 100 ~ " << money << " ) : ";
				cin >> betting;
				continue;
			}
			break;
		}

		switch (type)
		{
		case 56:
			if (trump[cnt + 5].number > 7)
			{
				cout << endl << "\t\t\t      ���� ���?" << endl;
				money += betting;
				Sleep(1500);
			}
			else
			{
				cout << endl << "\t\t\t      ���� ������" << endl;
				money -= betting;
				Sleep(1500);
			}
			break;
		case 50:
			if (trump[cnt + 5].number < 7)
			{
				cout << endl << "\t\t\t      ���� ���?" << endl;
				money += betting;
				Sleep(1500);
			}
			else
			{
				cout << endl << "\t\t\t      ���� ������" << endl;
				money -= betting;
				Sleep(1500);
			}
			break;
		case 53:
			if (trump[cnt + 5].number == 7)
			{
				cout << endl << "\t\t\t      ����!! ����!!!" << endl;
				money = money + betting * 13;
				Sleep(1500);
			}
			else
			{
				cout << endl << "\t\t\t      ���� ������" << endl;
				money -= betting;
				Sleep(1500);
			}
			break;
		}

		if (cnt == 46)					//Ƚ�� �� ��������� ī���ÿ� ���� �迭�� 0���ڸ� �ε��� ��ȣ ã�Ƽ� ���
		{
			cout << endl << endl << "�����ݾ� : " << money << endl << endl;

			if (money > 10000) cout << endl << endl << "\t\t   ����� ����Ե�" << money - 10000 << "���� ���̽��ϴ�." << endl;
			else cout << endl << endl << "\t\t   ����� �ƽ��Ե� " << 10000 - money << "���� �Ҿ����ϴ�." << endl;
			cout << endl << endl;
			break;
		}
		else if (money < 100)			//�ݾ� 100�������϶�
		{
			cout << endl << endl << "�����ݾ� : " << money << endl << endl;
			cout << endl << "\t\t " << money << "��?????? ���� ���ٸ� �ֹ����� ���̳�?" << endl << endl;
			cout << "\t\t\t<< �� ~~~~~~~~~~~ �� >>" << endl;
			break;
		}
		cnt++;
	}
}


HighLowSeven::~HighLowSeven()
{
}

void HighLowSeven::CardPrint(int num)
{
	switch (trump[num].number)
	{
	case 1:
		cout << trump[num].shape << "A\t";
		break;
	case 11:
		cout << trump[num].shape << "J\t";
		break;
	case 12:
		cout << trump[num].shape << "Q\t";
		break;
	case 13:
		cout << trump[num].shape << "K\t";
		break;
	default:
		cout << trump[num].shape << trump[num].number << "\t";
		break;
	}
}