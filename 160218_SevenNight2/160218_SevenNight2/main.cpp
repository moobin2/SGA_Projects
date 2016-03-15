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

		cout << endl << "\t\t<< 상대방의 턴을 기다리고 있습니다 >> " << endl;
		Sleep(1000);
		mainGame.MakeAttack(computer);
		Sleep(2000);
		if (mainGame.HPcheck() == TRUE) break;
		else continue;
	}

	return 0;
}