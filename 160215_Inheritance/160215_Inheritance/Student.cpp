#include "Student.h"



void Student::eating()
{
	cout << endl << "Student :: 인스턴스음식으로 끼니를 때운다" << endl;
}

void Student::study()
{
	cout << endl << "Student :: 재미는 없지만 공부를 해본다" << endl;
}

void Student::play()
{
	cout << endl << "Student :: 친구들과 밤새 논다." << endl;
}

Student::Student()
{
	cout << endl << "Student :: 학생이 되었다." << endl;
}


Student::~Student()
{
	cout << endl << "Student :: 학창시절을 회상한다" << endl;
}
