//Reader.cpp
#include<iostream>
#include "Reader.h"

#define MAX_FIELD_SIZE 9
#define MIN_FIELD_SIZE 4


int Reader::inputSize() {
	int n;
	std::cout << "Enter the size of the field (Enter N and the size will be NxN)" << std::endl;
	std::cout << "N: ";
	
	std::cin >> n;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		throw 1;
	}
	if (n < MIN_FIELD_SIZE || n > MAX_FIELD_SIZE) {
		throw "Size must be between 4 and 9";
	}
	return n;
}

char Reader::inputCommand() {
	char command;
	std::cout << "Enter the command (w - up, s - down, a - left, d - right, SPACE - pause)" << std::endl;
	std::cout << "Command: ";
	while (std::cin.get(command)) {
		if (command == '\n') {
			continue;
		}
		else {
			break;
		}
	}
	return command;
}

int* Reader::commantToIdx(char command) {
	int* idx = new int[2];
	switch (command) {
		case 'w':
			idx[0] = -1;
			idx[1] = 0;
			break;
		case 's':
			idx[0] = 1;
			idx[1] = 0;
			break;
		case 'a':
			idx[0] = 0;
			idx[1] = -1;
			break;
		case 'd':
			idx[0] = 0;
			idx[1] = 1;
			break;
		default:
			throw "Invalid command";
	}
	return idx;
}

int Reader::inputMenuVariant() {
	int menuVariant;
	std::cout << "Enter variant: ";
	std::cin >> menuVariant;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		throw 1;
	}
	if (menuVariant < 1 || menuVariant > 4) {
		throw "Variant must be between 1 and 4";
	}
	return menuVariant;
}
