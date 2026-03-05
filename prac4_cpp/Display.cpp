//Display.cpp
#include "Display.h"
#include <iostream>
#include <string>
#include <iomanip>

#define BORDER 25
#define MAX_NUMBER_LENGHT 2
#define SYMBOLS_NEAR_NUMBER 2
#define EMPTY '*'

void Display::displayGame(GameField gf) {

    int rowSize = gf.size * (MAX_NUMBER_LENGHT + SYMBOLS_NEAR_NUMBER);

    std::cout << std::string(BORDER, ' ');
	std::cout << std::string((rowSize-8)/2, ' ') << "| GAME |" << std::endl;

    for (int i = 0; i < gf.size; i++) {
        std::cout << std::string(BORDER, ' ');
        std::cout << std::string(rowSize, '-') << std::endl;
        std::cout << std::string(BORDER, ' ');
        for (int j = 0; j < gf.size; j++) {
            if (gf.field[i][j] != 0) {
                std::cout << "|" << std::setw(MAX_NUMBER_LENGHT) << gf.field[i][j] << "|";
            }
            else {
                std::cout << "|" << std::setw(MAX_NUMBER_LENGHT) << EMPTY << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::string(BORDER, ' ');
    std::cout << std::string(rowSize, '-') << std::endl;
}