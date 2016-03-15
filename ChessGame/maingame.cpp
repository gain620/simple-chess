#include "maingame.h"
#include <windows.h>

void TestDraw()
{
	system("cls");
	cout << "----------------------" << endl;
	cout << "|                    |" << endl;
	cout << "|    This mode is    |" << endl;
	cout << "|       not yet      |" << endl;
	cout << "|    implemented!    |" << endl;
	cout << "|                    |" << endl;
	cout << "----------------------" << endl;
	Sleep(1000);
}

void MainGame::Init()
{
	
}

void MainGame::Play()
{
	Board coregame;
	int selectNum; // selected menu num

	while (1)
	{
		Clear();
		Menu();

		cin >> selectNum;

		switch (selectNum)
		{
		case 1:
			cout << "Player versus Player Mode" << endl;
			coregame.BeginGame();
			break;

		case 2:
			cout << "Replay Mode" << endl;
			//coregame.ReplayMode();
			TestDraw();
			break;

		case 3:
			cout << "Player versus Computer Mode" << endl;
			TestDraw();
			break;

		case 4:
			cout << "Computer versus Computer Mode" << endl;
			TestDraw();
			break;
		case 5:
			cout << "Exiting the game---" << endl;
			//Sleep(300);
			exit(0);
			break;
		default:
			cout << "Please input a number which is 1~5" << endl;
			break;
		}
	}
}

void MainGame::Menu()
{
	cout << "----------------------" << endl;
	cout << "|                    |" << endl;
	cout << "|     Chess Game     |" << endl;
	cout << "|                    |" << endl;
	cout << "|                    |" << endl;
	cout << "|    1. PvP          |" << endl;
	cout << "|    2. ReplayMode   |" << endl;
	cout << "|    3. PvE          |" << endl;
	cout << "|    4. Simulation   |" << endl;
	cout << "|    5. Exit         |" << endl;
	cout << "----------------------" << endl;
	cout << "Input an option to play :";
}