#include "Hero.h"
#include "Handler.h"

int main(void)
{
	Handler mainGame;

	mainGame.MakePlayer();

	while (true)
	{
		system("cls");
		mainGame.showPlayerInfo();
		mainGame.MakeAttack(player);
		Sleep(1000);
		if (mainGame.HPcheck() == TRUE) break;

		cout << endl << "\t\t<< ������ ���� ��ٸ��� �ֽ��ϴ� >> " << endl;
		Sleep(1000);
		mainGame.MakeAttack(computer);
		Sleep(2000);
		if (mainGame.HPcheck() == TRUE) break;
		else continue;
	}

	return 0;
}