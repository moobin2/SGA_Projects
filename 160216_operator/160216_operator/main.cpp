#include "Operator.h"

int main(void)
{
	Operator boy("����", 19, "����");
	Operator man;

	boy.showInfo();

	boy + 3;

	boy.showInfo();

	boy - 1;

	boy.showInfo();

	man = boy;

	man.showInfo();

	return 0;
}