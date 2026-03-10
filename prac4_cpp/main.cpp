//main.cpp
#include "GameController.h"
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

int main()
{
	GameField gameField;
	Display display;
	Reader reader;
	GameController gameController(gameField, display, reader);

	gameController.startGame();
}
