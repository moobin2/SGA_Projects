#include "Handler.h"



void Handler::gotoStore(void)
{
	system("cls");
	int num;
	int choice;
	_seller.showItemList();
	cout << endl << "1. �����ۻ��" << endl;
	cout << "2. ������" << endl;
	cout << "���� : "; cin >> choice;
	if (choice == 1)
	{
		system("cls");
		_seller.showItemList();
		cout << endl << "����ݾ� : " << _buyer.getmoney() << endl;
		cout << "������ ��ǰ : "; cin >> num;
		if (_seller.itemPrice(num) <= _buyer.getmoney() && num >= 1 && num <= 5)
		{
			_buyer.buyItem(num);
			cout << endl << "\t\t'" <<_seller.itemName(num) << "'��(��) �����Ͽ����ϴ�." << endl;
			Sleep(500);
			gotoStore();
		}
		else if (_seller.itemPrice(num) >= _buyer.getmoney() && num >= 1 && num <= 5)
		{
			cout << endl << "�ݾ��� �����մϴ�. " << endl;
			cout << "2���� ����ȭ������ ���ư��ϴ�." << endl;
			Sleep(2000);
		}
		else if(num == 9)
		{
			cout << "����ȭ������ �̵��մϴ�." << endl;
			Sleep(2000);
		}

	}
}

void Handler::gotoinven(void)
{
	system("cls");
	int choice;
	_buyer.showInven();
	cout << endl << "1. ��������" << endl;
	cout << "2. �������ȱ�" << endl;
	cout << "3. ������" << endl;
	cout << "���� : "; cin >> choice;
	if (choice == 1)
	{
		system("cls");
		_buyer.showInven();
		cout << endl << "<< �������� >>" << endl;
		cout << "�����ۼ��� : "; cin >> choice;
		_buyer.showitemInfo(choice);
		Sleep(2000);
		gotoinven();
	}
	else if (choice == 2)
	{
		system("cls");
		_buyer.showInven();
		cout << endl << "<< �������ȱ� >>" << endl;
		cout << endl << "����ݾ� : " << _buyer.getmoney() << endl;
		cout << "�����ۼ��� : "; cin >> choice;
		_buyer.sellItem(choice);
		Sleep(1000);
		gotoinven();
	}
	else {}
}

void Handler::printFirstScreen(void)
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t������������������������������������" << endl;
	cout << "\t\t��                                ��" << endl;
	cout << "\t\t��                                ��" << endl;
	cout << "\t\t��          1. ���� ����          ��" << endl;
	cout << "\t\t��                                ��" << endl;
	cout << "\t\t��          2. �κ� ����          ��" << endl;
	cout << "\t\t��                                ��" << endl;
	cout << "\t\t��          3.  ������            ��" << endl;
	cout << "\t\t��                                ��" << endl;
	cout << "\t\t��                                ��" << endl;
	cout << "\t\t������������������������������������" << endl;
}

Handler::Handler()
{
}


Handler::~Handler()
{
}
