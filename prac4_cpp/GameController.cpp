#include <iostream>
#include "GameController.h"
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

GameController::GameController(GameField& gameField, Display& display, Reader& reader)
	: gF(gameField), d(display), r(reader) {}


void GameController::startGame() {
    gF.size = r.inputSize();
    gF.init();
    d.displayGame(gF);
    while(!isWon()) {
        if (move()) {
            d.displayGame(gF);
        }
	}
}

bool GameController::canBeMoved(char dir) {
    switch (dir) {
        case 'w':
            return gF.emptyRow - 1 >= 0;
        case 's':
			return gF.emptyRow + 1 < gF.size;
		case 'a':
			return gF.emptyColumn - 1 >= 0;
        case 'd':
			return gF.emptyColumn + 1 < gF.size;
        default:
			return true;
    }
}

bool GameController::move() {
    char command = r.inputCommand();
    int movable;
    if (canBeMoved(command)) {
        switch (command) {
        case 'w':
    //        movable = gF.field[gF.emptyRow - 1][gF.emptyColumn];
    //        gF.field[gF.emptyRow][gF.emptyColumn] = movable;        
    //        gF.field[gF.emptyRow - 1][gF.emptyColumn] = 0;
            std::swap(gF.field[gF.emptyRow][gF.emptyColumn], gF.field[gF.emptyRow - 1][gF.emptyColumn]);
            gF.emptyRow--;
			return true;
			break;
        case 's':
            std::swap(gF.field[gF.emptyRow][gF.emptyColumn], gF.field[gF.emptyRow + 1][gF.emptyColumn]);
			gF.emptyRow++;
            return true;
			break;
        case 'a':
			std::swap(gF.field[gF.emptyRow][gF.emptyColumn], gF.field[gF.emptyRow][gF.emptyColumn - 1]);
			gF.emptyColumn--;
            return true;
			break;
		case 'd':
			std::swap(gF.field[gF.emptyRow][gF.emptyColumn], gF.field[gF.emptyRow][gF.emptyColumn + 1]);
			gF.emptyColumn++;
            return true;
			break;
		default:
            std::cout << "Wrong command!" << std::endl;
            return false;
			break;
        }
    }
    else {
		std::cout << "End of the game field!" << std::endl;
		return false;
    }
}

bool GameController::isWon() {

    for (int i = 0; i < gF.size; i++) {
        for (int j = 0; j < gF.size-1; j++) {
            if (gF.field[i][j] > gF.field[i][j+1]) {
                return false;
			}
        }
	}

    for (int i = 0; i < gF.size - 1; i++) {
        if (gF.field[i][gF.size - 1] > gF.field[i + 1][0]) {
            return false;
        }
    }
	return true;
}