//Display.h
#pragma once
#include "GameField.h"
#include <iostream>
#include <fstream>
#include <string>

class Display {
public:
	void displayOnStart();
	void displayMenu();
	void displayRules();
	void displayWin();
	void displayPause();
	void displayEnd();
	void displayGame(GameField gf);
	void displayOnEnd();
	void displayMessage(std::string message);
	void displayError(std::string err);
private:
	std::ofstream logFile;
};

std::ostream& operator<<(std::ostream& out, const GameField& gf);