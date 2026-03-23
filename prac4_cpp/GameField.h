//GameField.h
#pragma once
#include <vector>

enum State {NONACTIVE, ACTIVE, WIN, BROKEN};

struct GameField {
	int size;
	bool isCreated;
	std::vector<std::vector<int>> field;
	int emptyRow;
	int emptyColumn;
	int step;
	State state;
	void init();
	void destroy();
	void canBeMoved();
	void move();
};