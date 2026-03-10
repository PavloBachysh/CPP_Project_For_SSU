#pragma once
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

class GameController {
private:
	bool isWon();
	bool canBeMoved(char dir);
	bool move();

	GameField& gF;
	Display& d;
	Reader& r;


public:
	GameController(GameField& gameField, Display& display, Reader& reader);
	void startGame();
	void endGame();
};