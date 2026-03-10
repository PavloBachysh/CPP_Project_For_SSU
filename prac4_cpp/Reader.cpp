//Reader.cpp
#include<iostream>
#include "Reader.h"

int Reader::inputSize() {
	int n;
	std::cout << "Enter the size of the field (Enter N and the size will be NxN)" << std::endl;
	std::cout << "N: ";
	std::cin >> n;
	return n;
}

char Reader::inputCommand() {
	char command;
	std::cout << "Enter the command (w - up, s - down, a - left, d - right)" << std::endl;
	std::cout << "Command: ";
	std::cin >> command;
	return command;
}