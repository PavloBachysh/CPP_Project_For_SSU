//Display.cpp
#include "Display.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>

#define EMPTY_VALUE 999
#define BORDER 25
#define MAX_NUMBER_LENGHT 2
#define SYMBOLS_NEAR_NUMBER 2
#define EMPTY '*'
#define SPACING 10
#define MINI_SPACING 5

void Display::displayOnStart() {
    std::cout << std::string(BORDER, ' ');
    std::cout << "PYATNASHKI starts" << std::endl;
	std::time_t now = std::time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
	std::cout << "Start time: " << buffer << std::endl;

    logFile.open("logs.txt");
    logFile << std::string(BORDER, ' ');
    logFile << "PYATNASHKI starts" << std::endl;
	logFile << "Start time: " << buffer << std::endl;
}

void Display::displayGame(GameField gf) {

    int rowSize = gf.size * (MAX_NUMBER_LENGHT + SYMBOLS_NEAR_NUMBER);

    std::cout << std::string(BORDER, ' ');
	std::cout << std::string((rowSize-8)/2, ' ') << "| GAME |" << std::endl;
    std::cout << gf;

    logFile << std::string(BORDER, ' ');
    logFile << std::string((rowSize - 8) / 2, ' ') << "| GAME |" << std::endl;
    logFile << gf;
}

std::ostream& operator<<(std::ostream& out, const GameField& gf) {
    int rowSize = gf.size * (MAX_NUMBER_LENGHT + SYMBOLS_NEAR_NUMBER);

    for (int i = 0; i < gf.size; i++) {
        out << std::string(BORDER, ' ');
        out << std::string(rowSize, '-') << std::endl;
        out << std::string(BORDER, ' ');
        for (int j = 0; j < gf.size; j++) {
            if (gf.field[i][j] != EMPTY_VALUE) {
                out << "|" << std::setw(MAX_NUMBER_LENGHT) << gf.field[i][j] << "|";
            }
            else {
                out << "|" << std::setw(MAX_NUMBER_LENGHT) << EMPTY << "|";
            }
        }
        out << std::endl;
    }
    out << std::string(BORDER, ' ');
    out << std::string(rowSize, '-') << std::endl;
	return out;
}

void Display::displayWin() {
    std::cout << std::string(BORDER, ' ');
	std::cout << std::string(SPACING, ' ') << "| YOU WIN! |" << std::endl;

    logFile << std::string(BORDER, ' ');
	logFile << std::string(SPACING, ' ') << "| YOU WIN! |" << std::endl;
}

void Display::displayPause() {
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING, ' ') << "| PAUSED |" << std::endl;

    logFile << std::string(BORDER, ' ');
	logFile << std::string(SPACING, ' ') << "| PAUSED |" << std::endl;
}

void Display::displayEnd() {
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING, ' ') << "| GAME OVER |" << std::endl;

	logFile << std::string(BORDER, ' ');
	logFile << std::string(SPACING, ' ') << "| GAME OVER |" << std::endl;
}

void Display::displayMenu() {
    std::cout << std::endl;
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING-14/2, ' ') << "| PYATNASHKI |" << std::endl;
    std::cout << std::endl;
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING-17/2, ' ') << "1. Start New Game" << std::endl;
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING-16/2, ' ') << "2. Continue Game" << std::endl;
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING-8/2, ' ') << "3. Rules" << std::endl;
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(SPACING-12/2, ' ') << "4. Exit Game" << std::endl;
    std::cout << std::endl;

	logFile << "Player in menu" << std::endl;
}

void Display::displayRules() {
    std::cout << std::string(BORDER, ' ');
    std::cout <<  "| Rules |" << std::endl;
    std::cout <<  "The goal of the game is to put all numbers from 1 to the highest" << std::endl;
    std::cout <<  "You can move the number to the empty space (*)" << std::endl;
    std::cout <<  "Use wasd to move the number which is:" << std::endl;
    std::cout << std::string(MINI_SPACING, ' ');
    std::cout <<  "w - upper than empty" << std::endl;
	std::cout << std::string(MINI_SPACING, ' ');
	std::cout <<  "s - lower than empty" << std::endl;
	std::cout << std::string(MINI_SPACING, ' ');
	std::cout <<  "a - left than empty" << std::endl;
	std::cout << std::string(MINI_SPACING, ' ');
	std::cout <<  "d - right than empty" << std::endl;
    std::cout <<  "Enter SPACE if you want to pause game" << std::endl;

    logFile << "Player in rules" << std::endl;
}

void Display::displayOnEnd() {
    std::cout << std::string(BORDER, ' ');
    std::cout << "PYATNASHKI ends" << std::endl;
    std::time_t now = std::time(nullptr);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    std::cout << "End time: " << buffer << std::endl;

    logFile << std::string(BORDER, ' ');
    logFile << "PYATNASHKI ends" << std::endl;
	logFile << "End time: " << buffer << std::endl;
	logFile.close();
}

void Display::displayMessage(std::string message) {
    std::cout << message << std::endl;
    logFile << message << std::endl;
}

void Display::displayError(std::string err) {
    std::cerr << "ERROR: " << err << std::endl;
    logFile << "ERROR: " << err << std::endl;
}