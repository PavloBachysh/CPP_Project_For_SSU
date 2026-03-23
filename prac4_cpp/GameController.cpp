//GameController.cpp
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
    continueGame();
	checkStatus();
}

void GameController::endGame() {
    gF.destroy();
}

void GameController::pause() {
    gF.state = NONACTIVE;
    d.displayPause();
    menu();
}

void GameController::menu() {
    d.displayMenu();
    switch (r.inputMenuVariant()) {
    case 1:
        startGame();
        break;
    case 2:
        if (gF.isCreated) {
            continueGame();
        }
        else {
            std::cout << "Game is not created yet!" << std::endl;
			menu();
        }
        break;
    case 3:
        d.displayRules();
        menu();
        break;
    case 4:
        endGame();
		break;
    default:
		std::cout << "Wrong variant!" << std::endl;
        menu();
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

void GameController::continueGame() {
    gF.state = ACTIVE;
    d.displayGame(gF);
    while (gF.state == ACTIVE) {
        if (move()) {
            d.displayGame(gF);
        }
    }
}

bool GameController::move() {
    char command = r.inputCommand();
    int movable;
    if (command == ' ') {
        pause();
        return false;
    }
    if (canBeMoved(command)) {
		int* idx = r.commantToIdx(command);
        *this >> idx;
        gF.step++;
		return true;
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

	gF.state = WIN;
	return true;
}

void GameController::checkStatus() {
    switch (gF.state) {
    case WIN:
		d.displayWin();
		endGame();
        break;
    case NONACTIVE:
		d.displayPause();
        break;
    case BROKEN:
		d.displayEnd();
		endGame();
        break;
    }

}

GameController& GameController::operator>> (const int idx[2]) {
    std::swap(gF.field[gF.emptyRow][gF.emptyColumn], gF.field[gF.emptyRow+idx[0]][gF.emptyColumn + idx[1]]);
    gF.emptyRow += idx[0];
	gF.emptyColumn += idx[1];
	return *this;
}