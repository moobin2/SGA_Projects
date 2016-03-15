#include "trump.h"

trump::trump()
{
	srand((unsigned int)time(NULL));

	int card[4][13], tableCard[6];
	int opencard[4][13] = { 0, };
	int number, shape;
	int gameCnt = 0;
	int money = 10000;
	int batting;
	int printCnt = 0;

	//�迭 �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
			card[i][j] = j + 1;
	}

	//���� �ݺ��� ����
	while (true)
	{
		cout << "\t\t   < ī���� ����� > " << endl << endl;				//ī���� �迭 and �ߺ��̱� �����迭
		cout << "\t    �� : ";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (opencard[i][j] == 1) cout << "A ";
				else if (opencard[i][j] == 11) cout << "J ";
				else if (opencard[i][j] == 12) cout << "Q ";
				else if (opencard[i][j] == 13) cout << "K ";
				else if (opencard[i][j] == 0) cout << "  ";
				else cout << opencard[i][j] << " ";
			}
			if(i == 0)	cout << endl << "\t    �� : ";
			else if (i == 1)	cout << endl << "\t    �� : ";
			else if (i == 2)	cout << endl << "\t    �� : ";
		}
		cout << endl << endl << "\t\t   <<< ���ð��� >>>" << endl << endl << endl;

		//52���� ������ �̱�
		while (true)
		{
			shape = rand() % 4;		//0~3
			number = rand() % 13;	//0~12
			if (printCnt == 6)												//3���� ��� ���� �����ϸ� Ż��
			{
				printCnt = 0;												//��� �̾ƾߵǹǷ� �ʱ�ȭ
				break;
			}
			if (opencard[shape][number] == card[shape][number]) continue;	//�ߺ��ڸ��� ��Ƽ��
			else
			{
				opencard[shape][number] = card[shape][number];				//�ߺ��ڸ� �ƴϸ� ��迭�� ������ġ�� ���� : ī���ù迭 and �����Ѽ� ���̴°� ���̱�����
				tableCard[printCnt] = shape;								//�򸮴� ī������ 0, 2, 4�ε����� ����
				tableCard[printCnt + 1] = number + 1;						//�򸮴� ī����ڴ� 1, 3, 5�ε����� ����
				printCnt += 2;												//���, ���� 2�����̹Ƿ� 2�� ����
			}
		}

		cout << "\t ó��\t         �߰�\t          ��" << endl << endl << "\t";

		//����ī�� 2�� ȭ�鿡 ���̱�
		for (int i = 0; i < 4; i = i + 2)									
		{
			if (i == 2) cout << "\t\t??????\t\t";
			if (tableCard[i] == 0)
			{
				if (tableCard[i + 1] == 1)	cout << " �� " << "A";
				else if (tableCard[i + 1] == 11)	cout << " �� " << "J";
				else if (tableCard[i + 1] == 12)	cout << " �� " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " �� " << "K";
				else cout << " �� " << tableCard[i + 1];
			}
			else if (tableCard[i] == 1)
			{
				if (tableCard[i + 1] == 1)	cout << " �� " << "A";
				else if (tableCard[i + 1] == 11)	cout << " �� " << "J";
				else if (tableCard[i + 1] == 12)	cout << " �� " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " �� " << "K";
				else cout << " �� " << tableCard[i + 1];
			}
			else if (tableCard[i] == 2)
			{
				if (tableCard[i + 1] == 1)	cout << " �� " << "A";
				else if (tableCard[i + 1] == 11)	cout << " �� " << "J";
				else if (tableCard[i + 1] == 12)	cout << " �� " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " �� " << "K";
				else cout << " �� " << tableCard[i + 1];
			}
			else if (tableCard[i] == 3)
			{
				if (tableCard[i + 1] == 1)	cout << " �� " << "A";
				else if (tableCard[i + 1] == 11)	cout << " �� " << "J";
				else if (tableCard[i + 1] == 12)	cout << " �� " << "Q";
				else if (tableCard[i + 1] == 13)	cout << " �� " << "K";
				else cout << " �� " << tableCard[i + 1];
			}
		}

		//�����ݾ� ���
		cout << endl << endl << endl;
		if (gameCnt == 16) 		cout << "\t\t      ������ ����" << endl << endl;
		else cout << "\t\t      " << gameCnt + 1 << "��° ����" << endl << endl;
		cout << "�����ݾ� : " << money << endl << endl;



		//���ñݾ� ����
		cout << "���ñݾ� : ";
		cin >> batting;
		while (true)
		{
			if (!cin.good() || batting < 100 || batting > money)		//�����Է� or 100 ���� or money�ʰ�
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "�ٽù��� ( 100 ~ "<< money << " ) : ";
				cin >> batting;
				continue;
			}
			else break;
		}
		cout << endl;

		//����� ��
		if ( (tableCard[5] < tableCard[3] && tableCard[5] > tableCard[1]) 
			|| (tableCard[5] < tableCard[1] && tableCard[5] > tableCard[3]) )
		{
			cout << "\t\t���̻�!";
			money += batting;
		}
		else
		{
			cout << "\t\t�Ʊ��!";
			money -= batting;
		}

		//���� ���
		cout << "   ���� ī�� : ";
		if (tableCard[4] == 0)
		{
			if (tableCard[5] == 1)	cout << " �� " << "A";
			else if (tableCard[5] == 11)	cout << " �� " << "J";
			else if (tableCard[5] == 12)	cout << " �� " << "Q";
			else if (tableCard[5] == 13)	cout << " �� " << "K";
			else cout << " �� " << tableCard[5];
		}
		else if (tableCard[4] == 1)
		{
			if (tableCard[5] == 1)	cout << " �� " << "A";
			else if (tableCard[5] == 11)	cout << " �� " << "J";
	
			else if (tableCard[5] == 12)	cout << " �� " << "Q";
			else if (tableCard[5] == 13)	cout << " �� " << "K";
			else cout << " �� " << tableCard[5];
		}
		else if (tableCard[4] == 2)
		{
			if (tableCard[5] == 1)	cout << " �� " << "A";
			else if (tableCard[5] == 11)	cout << " �� " << "J";
			else if (tableCard[5] == 12)	cout << " �� " << "Q";
			else if (tableCard[5] == 13)	cout << " �� " << "K";
			else cout << " �� " << tableCard[5];
		}
		else if (tableCard[4] == 3)
		{
			if (tableCard[5] == 1)	cout << " �� " << "A";
			else if (tableCard[5] == 11)	cout << " �� " << "J";
			else if (tableCard[5] == 12)	cout << " �� " << "Q";
			else if (tableCard[5] == 13)	cout << " �� " << "K";
			else cout << " �� " << tableCard[5];
		}

		Sleep(500);

		//���� Ż������
		if (gameCnt == 16)					//Ƚ�� �� ��������� ī���ÿ� ���� �迭�� 0���ڸ� �ε��� ��ȣ ã�Ƽ� ���
		{
			system("cls");
			cout << "\t\t   < ī���� ����� > " << endl << endl;				//ī���� �迭 and �ߺ��̱� �����迭
			cout << "\t    �� : ";
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (opencard[i][j] == 1) cout << "A ";
					else if (opencard[i][j] == 11) cout << "J ";
					else if (opencard[i][j] == 12) cout << "Q ";
					else if (opencard[i][j] == 13) cout << "K ";
					else if (opencard[i][j] == 0) cout << "  ";
					else cout << opencard[i][j] << " ";
				}
				if (i == 0)	cout << endl << "\t    �� : ";
				else if (i == 1)	cout << endl << "\t    �� : ";
				else if (i == 2)	cout << endl << "\t    �� : ";
			}

			cout << endl << endl << "�����ݾ� : " << money << endl << endl;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (opencard[i][j] == 0)
					{
						cout << endl << endl << "\t\t ������ ī�� : ";
						if (i == 0)
						{
							if (card[i][j] == 1)	cout << " �� " << "A";
							else if (card[i][j] == 11)	cout << " �� " << "J";
							else if (card[i][j] == 12)	cout << " �� " << "Q";
							else if (card[i][j] == 13)	cout << " �� " << "K";
							else cout << " �� " << card[i][j];
						}
						else if (i == 1)
						{
							if (card[i][j] == 1)	cout << " �� " << "A";
							else if (card[i][j] == 11)	cout << " �� " << "J";
							else if (card[i][j] == 12)	cout << " �� " << "Q";
							else if (card[i][j] == 13)	cout << " �� " << "K";
							else cout << " �� " << card[i][j];
						}
						else if (i == 2)
						{
							if (card[i][j] == 1)	cout << " �� " << "A";
							else if (card[i][j] == 11)	cout << " �� " << "J";
							else if (card[i][j] == 12)	cout << " �� " << "Q";
							else if (card[i][j] == 13)	cout << " �� " << "K";
							else cout << " �� " << card[i][j];
						}
						else if (i == 3)
						{
							if (card[i][j] == 1)	cout << " �� " << "A";
							else if (card[i][j] == 11)	cout << " �� " << "J";
							else if (card[i][j] == 12)	cout << " �� " << "Q";
							else if (card[i][j] == 13)	cout << " �� " << "K";
							else cout << " �� " << card[i][j];
						}
					}
				}
			}
			if (money > 10000) cout << endl << endl << "\t   ����� ����Ե�" << money - 10000 << "���� ���̽��ϴ�." << endl;
			else cout << endl << endl << "\t   ����� �ƽ��Ե� " << 10000 - money << "���� �Ҿ����ϴ�." << endl;
			cout << endl << endl;
			break;
		}
		else if (money < 100)			//�ݾ� 100�������϶�
		{
			system("cls");
			cout << "\t\t   < ī���� ����� > " << endl << endl;				//ī���� �迭 and �ߺ��̱� �����迭
			cout << "\t    �� : ";
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (opencard[i][j] == 1) cout << "A ";
					else if (opencard[i][j] == 11) cout << "J ";
					else if (opencard[i][j] == 12) cout << "Q ";
					else if (opencard[i][j] == 13) cout << "K ";
					else if (opencard[i][j] == 0) cout << "  ";
					else cout << opencard[i][j] << " ";
				}
				if (i == 0)	cout << endl << "\t    �� : ";
				else if (i == 1)	cout << endl << "\t    �� : ";
				else if (i == 2)	cout << endl << "\t    �� : ";
			}

			cout << endl << endl << endl;
			if (gameCnt == 16) 		cout << "\t\t      ������ ����" << endl << endl;
			else cout << "\t\t      " << gameCnt + 1 << "��° ����" << endl << endl;
			cout << "�����ݾ� : " << money << endl << endl;

			cout << endl << endl << "\t " << money << "��?????? ���� ���ٸ� �ֹ����� ���̳�?" << endl << endl;
			cout << "\t\t<< �� ~~~~~~~~~~~ �� >>" << endl;
			break;
		}
		system("cls");
		gameCnt++;
	}
}

trump::~trump()
{
	cout << endl << endl << "\t << ������ �����ϻ� ���ڿ� ���������� >>" << endl << endl;
}