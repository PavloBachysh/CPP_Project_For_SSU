//Display.h
#pragma once
#include "GameField.h"
#include <iostream>

class Display {
public:
	void displayMenu();
	void displayRules();
	void displayWin();
	void displayPause();
	void displayEnd();
	void displayGame(GameField gf);
};

std::ostream& operator<<(std::ostream& out, const GameField& gf);