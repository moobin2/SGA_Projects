#include <iostream>

using namespace std;

class B
{
public:
	virtual void printNum(int a)
	{
		cout << "B inside int " << a << endl;
	}
	virtual void printNum(double a) // B 오버로딩 함수
	{
		cout << "B inside double " << a << endl;
	}
};

class D : public B
{
public:
	void printNum(int a) // B 에서 오버라이딩한 함수 
	{
		cout << "D inside int " << a << endl;
	}
};

int main(void)
{
	D d;				// 자식 객체 생성
	B b;
	B* pb = &d;

	b.printNum(9);  // B inside int 9
	b.printNum(9.5);  // B inside double 9.5

	d.printNum(9);  // D inside int 9
	d.printNum(9.5);  // D inside int 9

	pb->printNum(9);  // D inside int 9
	pb->printNum(9.5); // B inside double 9.5

	return 0;
}