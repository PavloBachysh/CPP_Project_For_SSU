//main.cpp
#include "GameController.h"
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

int main()
{
	GameField gameField;
	gameField.step = 0;
	gameField.state = NONACTIVE;
	gameField.isCreated = false;


	Display display;
	Reader reader;
	GameController gameController(gameField, display, reader);

	gameController.menu();
}
