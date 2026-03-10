//GameField.cpp
#include "GameField.h"
#include <iostream>
#define EMPTY_VALUE 999

void GameField::init() {
	step = 0;
	state = ACTIVE;

	field.resize(size);
	for (int i = 0; i < size; i++) {
		field[i].resize(size);
	}
	int val = size*size - 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = val;
			val--;
		}
	}

	if (size % 2 == 0) {
		field[size-1][size-2] = 2;
		field[size-1][size-3] = 1;
	}

	emptyRow = size-1;
	emptyColumn = size-1;
	field[emptyRow][emptyColumn] = EMPTY_VALUE;
}