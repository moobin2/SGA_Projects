#include "Handler.h"



void Handler::gotoStore(void)
{
	system("cls");
	int num;
	int choice;
	_seller.showItemList();
	cout << endl << "1. 아이템사기" << endl;
	cout << "2. 나가기" << endl;
	cout << "선택 : "; cin >> choice;
	if (choice == 1)
	{
		system("cls");
		_seller.showItemList();
		cout << endl << "현재금액 : " << _buyer.getmoney() << endl;
		cout << "구매할 물품 : "; cin >> num;
		if (_seller.itemPrice(num) <= _buyer.getmoney() && num >= 1 && num <= 5)
		{
			_buyer.buyItem(num);
			cout << endl << "\t\t'" <<_seller.itemName(num) << "'을(를) 구매하였습니다." << endl;
			Sleep(500);
			gotoStore();
		}
		else if (_seller.itemPrice(num) >= _buyer.getmoney() && num >= 1 && num <= 5)
		{
			cout << endl << "금액이 부족합니다. " << endl;
			cout << "2초후 메인화면으로 돌아갑니다." << endl;
			Sleep(2000);
		}
		else if(num == 9)
		{
			cout << "메인화면으로 이동합니다." << endl;
			Sleep(2000);
		}

	}
}

void Handler::gotoinven(void)
{
	system("cls");
	int choice;
	_buyer.showInven();
	cout << endl << "1. 정보보기" << endl;
	cout << "2. 아이템팔기" << endl;
	cout << "3. 나가기" << endl;
	cout << "선택 : "; cin >> choice;
	if (choice == 1)
	{
		system("cls");
		_buyer.showInven();
		cout << endl << "<< 정보보기 >>" << endl;
		cout << "아이템선택 : "; cin >> choice;
		_buyer.showitemInfo(choice);
		Sleep(2000);
		gotoinven();
	}
	else if (choice == 2)
	{
		system("cls");
		_buyer.showInven();
		cout << endl << "<< 아이템팔기 >>" << endl;
		cout << endl << "현재금액 : " << _buyer.getmoney() << endl;
		cout << "아이템선택 : "; cin >> choice;
		_buyer.sellItem(choice);
		Sleep(1000);
		gotoinven();
	}
	else {}
}

void Handler::printFirstScreen(void)
{
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t┏━━━━━━━━━━━━━━━━┓" << endl;
	cout << "\t\t┃                                ┃" << endl;
	cout << "\t\t┃                                ┃" << endl;
	cout << "\t\t┃          1. 상점 가기          ┃" << endl;
	cout << "\t\t┃                                ┃" << endl;
	cout << "\t\t┃          2. 인벤 가기          ┃" << endl;
	cout << "\t\t┃                                ┃" << endl;
	cout << "\t\t┃          3.  나가기            ┃" << endl;
	cout << "\t\t┃                                ┃" << endl;
	cout << "\t\t┃                                ┃" << endl;
	cout << "\t\t┗━━━━━━━━━━━━━━━━┛" << endl;
}

Handler::Handler()
{
}


Handler::~Handler()
{
}
