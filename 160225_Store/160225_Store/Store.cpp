#include "Store.h"



Store::Store()
{
	itemList[0] = new Item("��Ÿ�� ����", "��ȭ", 0, 0, 50000, 100000, "��ݾ��� ��Ÿ�� ����. �ȸ� �������� �������..?!");
	itemList[1] = new Item("  ���Ǻ�   ", "����", 380, 0, 200000, 50000, "�տ����� �ն��� �����ִ� ���Ǻ�");
	itemList[2] = new Item(" ������� ", "����", 0, 248, 100000, 1000, "ī���� ��Դٰ� ���� ��");
	itemList[3] = new Item("����� ����", "����", 0, 200, 250000, 70000, "���縶�� ä�밡 �����ִ� ������ ����");
	itemList[4] = new Item("��� Ű����", "����", 999, 999, 300000, 500000, "������ �ڵ��ɷ��� �����ϴ� ��������");
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
	cout << "             ���     ��    ��     ���     ����  " << endl;
	cout << "           ��    ��   ��    ��   ��    ��   ��    ��" << endl;
	cout << "             ��       ��    ��   ��    ��   ��    ��" << endl;
	cout << "               ��     �����   ��    ��   ����  " << endl;
	cout << "           ��    ��   ��    ��   ��    ��   ��      " << endl;
	cout << "             ���     ��    ��     ���     ��      " << endl;
	cout << "����������������������������������������������������������������" << endl;
	cout << "    < �̸� >      < Ÿ�� >    < ���� >    < ��� >    < ���� >" << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i+1 << ". " << itemList[i]->getName() << "\t    " << itemList[i]->getType() << "\t" << itemList[i]->getDam() << "\t    " << itemList[i]->getDef() << "\t\t" << itemList[i]->getBuyPrice() << endl;
	}
	cout << "����������������������������������������������������������������" << endl;
}
