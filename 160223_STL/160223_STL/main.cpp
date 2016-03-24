#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main(void)
{
	cout << "[����. vector, list, map ����غ���] ps. ������ 4�� �����غ�" << endl;
	cout << endl << "<< vector  >>" << endl;
	vector<int> vectorNum;
	vector<int> ::iterator vArr;

	cout << "1. �������Է� push_back(): ";
	for (int i = 0; i < 10; i++)
	{
		vectorNum.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
	
	vArr = vectorNum.begin();
		cout << *(vArr+i) << " ";
	}

	cout << endl << "2. �����ͻ��� erase(iterator): ";

	for (int i = 0; i < vectorNum.size(); i++)
	{
		if(vectorNum[i] == 4) vectorNum.erase(vArr + i);
	}
	
	for (int i = 0; i < vectorNum.size(); i++)
	{
		vArr = vectorNum.begin();
		cout << *(vArr + i) << " ";
	}

	cout << endl << "3. ��������ü���� clear(): ";
	vectorNum.clear();
	cout << "clear()ȣ�� -> ";
	if (vectorNum.empty() == true) cout << "TRUE" << endl;
	else if (vectorNum.empty() != true) cout << "FALSE" << endl;

	cout << endl << "<< list  >>" << endl;
	list<int> Lnum;
	list<int> ::iterator Lpos;

	cout << "1. �������Է� push_back(), push_front(): ";
	for (int i = 0; i < 5; i++)
	{
		Lnum.push_back(i);
		Lnum.push_front(i);
	}
    
	Lpos = Lnum.begin();
	for (int i = 0; i < 10; i++)
	{
	
		cout << *(Lpos++) << " ";
	}

	cout << endl << "2. �����ͻ��� remove(Val): ";

	Lnum.remove(4);

	for (Lpos = Lnum.begin(); Lpos != Lnum.end(); Lpos++)
	{
		cout << *(Lpos) << " ";
	}

	cout << endl << "3. ��������ü���� clear(): ";
	Lnum.clear();
	cout << "clear()ȣ�� -> ";
	if (Lnum.empty() == true) cout << "TRUE" << endl;
	else if (Lnum.empty() != true) cout << "FALSE" << endl;

	cout << endl << "<< map >>" << endl;
	map<int, int> mNum;
	map<int, int> ::iterator mPos;

	cout << "1. �������Է� insert(): ";
	for (int i = 0, j = 5; i < 5; i++, j--)
	{
		mNum.insert( pair<int,int> (j, i));
	}

	for (mPos = mNum.begin(); mPos != mNum.end(); mPos++)
	{
		cout << "<"<< mPos->first << " : " << mPos->second << "> ";
	}
	cout << endl << "2. �����ͻ��� erase(key=4): ";
	mNum.erase(4);
	
	for (mPos = mNum.begin(); mPos != mNum.end(); mPos++)
	{
		cout << "<" << mPos->first << " : " << mPos->second << "> ";
	}

	cout << endl << "3. ��������ü���� clear(): ";
	mNum.clear();
	cout << "clear()ȣ�� -> ";
	if (mNum.empty() == true) cout << "TRUE" << endl;
	else if (mNum.empty() != true) cout << "FALSE" << endl;

	return 0;
}