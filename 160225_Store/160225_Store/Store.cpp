#include "Store.h"



Store::Store()
{
	itemList[0] = new Item("산타의 선물", "잡화", 0, 0, 50000, 100000, "뜬금없는 산타의 선물. 팔면 좋은일이 생길수도..?!");
	itemList[1] = new Item("  여의봉   ", "무기", 380, 0, 200000, 50000, "손오공의 손때가 묻어있는 여의봉");
	itemList[2] = new Item(" 사령의포 ", "갑옷", 0, 248, 100000, 1000, "카일이 밥먹다가 놓고간 옷");
	itemList[3] = new Item("루디의 방패", "방패", 0, 200, 250000, 70000, "루디사마의 채취가 묻어있는 꼬릿한 방패");
	itemList[4] = new Item("장쌤 키보드", "전설", 999, 999, 300000, 500000, "소유시 코딩능력이 증가하는 전설의템");
}


Store::~Store()
{
	for (int i = 0; i < 5; i++)
	{
		delete itemList[i];
	}
}

int Store::itemPrice(int itemNum)
{
	return itemList[itemNum - 1]->getBuyPrice();
}

char * Store::itemName(int itemNum)
{
	return itemList[itemNum - 1]->getName();
}

void Store::showItemList(void)
{
	cout << endl;
	cout << "             ■■     ■    ■     ■■     ■■■  " << endl;
	cout << "           ■    ■   ■    ■   ■    ■   ■    ■" << endl;
	cout << "             ■       ■    ■   ■    ■   ■    ■" << endl;
	cout << "               ■     ■■■■   ■    ■   ■■■  " << endl;
	cout << "           ■    ■   ■    ■   ■    ■   ■      " << endl;
	cout << "             ■■     ■    ■     ■■     ■      " << endl;
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
	cout << "    < 이름 >      < 타입 >    < 공격 >    < 방어 >    < 가격 >" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i+1 << ". " << itemList[i]->getName() << "\t    " << itemList[i]->getType() << "\t" << itemList[i]->getDam() << "\t    " << itemList[i]->getDef() << "\t\t" << itemList[i]->getBuyPrice() << endl;
	}
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}
