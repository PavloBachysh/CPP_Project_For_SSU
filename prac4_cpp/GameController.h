//GameController.h
#pragma once
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

class GameController {
private:
	void continueGame();
	void pause();
	bool isWon();
	bool canBeMoved(char dir);
	bool move();
	void checkStatus();

	GameField& gF;
	Display& d;
	Reader& r;


public:
	GameController(GameField& gameField, Display& display, Reader& reader);
	void startGame();
	void endGame();
	void menu();
	GameController& operator>> (const int idx[2]);
};