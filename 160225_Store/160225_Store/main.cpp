#include "Handler.h"

int main(void)
{
	Handler mainGame;
	int choice;

	while (true)
	{
		system("cls");
		mainGame.printFirstScreen();
		cout << "\t\t\t     ¼±ÅÃ : "; cin >> choice;
		if (choice == 1) mainGame.gotoStore();
		else if (choice == 2) mainGame.gotoinven();
		else if (choice == 3) break;
	}

	return 0;
}