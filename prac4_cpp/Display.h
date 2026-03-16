//Display.h
#pragma once
#include "GameField.h"
#include <iostream>

class Display {
public:
	void displayMenu();
	void displayRules();
	void displayGame(GameField gf);
};

std::ostream& operator<<(std::ostream& out, const GameField& gf);