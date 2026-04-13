//GameController.cpp
#include <iostream>
#include "GameController.h"
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

GameController::GameController(GameField& gameField, Display& display, Reader& reader)
	: gF(gameField), d(display), r(reader) {}


void GameController::startGame() {
    try {
        gF.size = r.inputSize();
    }
    catch (const char* msg) {
		d.displayError(msg);
        startGame();
        return;
	}
    catch (const int er) {
		d.displayError("You must enter an integer");
        startGame();
        return;
    }
    gF.init();
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
    int imv;
    try {
        imv = r.inputMenuVariant();
    }
    catch (const char* msg) {
		d.displayError(msg);
        menu();
        return;
    }
    catch (const int er) {
		d.displayError("You must enter an integer");
        menu();
        return;
    }
    switch (imv) {
    case 1:
        startGame();
        break;
    case 2:
        if (gF.isCreated) {
            continueGame();
        }
        else {
			d.displayMessage("Trying to continue. No game to continue! Start new game.");
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
		d.displayMessage("Wrong variant!");
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
	d.displayMessage("Player entered command: " + std::string(1, command));
    int movable;
    if (command == ' ') {
        pause();
        return false;
    }
    if (canBeMoved(command)) {
        int* idx;
        try {
            idx = r.commantToIdx(command);
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
            return false;
		}
        *this >> idx;
        gF.step++;
		return true;
    }
    else {
		d.displayMessage("End of the game field! You are trying to move out of bounds.");
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