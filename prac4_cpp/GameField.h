//GameField.h
#pragma once
#include <vector>

enum State {NONACTIVE, ACTIVE, WIN, BROKEN};

struct GameField {
	int size;
	std::vector<std::vector<int>> field;
	int emptyRow;
	int emptyColumn;
	int step;
	State state;
	void init();
	void canBeMoved();
	void move();
};