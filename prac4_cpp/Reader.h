//Reader.h
#pragma once
class Reader {
private:
	char command;
public:
	char inputCommand();
	int inputSize();
	int* commantToIdx(char command);
};