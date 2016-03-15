#pragma once
#include <stdlib.h>
#include <iostream>
#include "board.h"
#include "location.h"

using namespace std;

class MainGame {
private:

public:
	//MainGame();
	void Init();
	void Play();
	void Clear() {
		system("cls");
	}

	void Menu();
};