#include "Human.h"

void Human::eating(void)
{
	cout << endl << "Human :: 어머니의 따스한 밥을 먹고 자란다" << endl;
}

Human::Human()
{
	cout << "Human :: 어느날 사람이 태어났다." << endl;
}


Human::~Human()
{
	cout << endl << "Human :: 하! 좋은 인생이였다. 인생 마감" << endl << endl;
}
