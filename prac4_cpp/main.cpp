//main.cpp
#include "GameField.h"
#include "Reader.h"
#include "Display.h"

int main()
{
    GameField gameField;
    Display display;
    Reader reader;

    gameField.size = reader.inputSize();
    gameField.init();
    display.displayGame(gameField);
}
