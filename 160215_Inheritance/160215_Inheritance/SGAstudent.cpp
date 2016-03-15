#include "SGAstudent.h"



void SGAstudent::eating()
{
	cout << endl << "SGAstudent :: 내 주식은 맥머핀" << endl;
}

void SGAstudent::play()
{
	cout << endl << "SGAstudent :: 놀고싶지.......만 못논다" << endl;
}

void SGAstudent::study()
{
	cout << endl << "SGAstudent :: 따라가기도 벅차므로 매일매일 스터디" << endl;
}

void SGAstudent::laptop()
{
	cout << endl << "SGAstudent :: 노트북은 필수품" << endl;
}

void SGAstudent::sleeping()
{
	cout << endl << "SGAstudent :: 초반 잘수 있을때 많이 자두자" << endl;
}

SGAstudent::SGAstudent()
{
	cout << endl << "SGAstudent :: SGA학생이 되었다." << endl;
}

SGAstudent::~SGAstudent()
{
	cout << endl << "SGAstudent :: 수료후, Blizzard 취업했다." << endl;
}
