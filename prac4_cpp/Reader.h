//Reader.h
#pragma once
class Reader {
private:
	char command;
	int menuVariant;
public:
	int inputMenuVariant();
	char inputCommand();
	int inputSize();
	int* commantToIdx(char command);
};