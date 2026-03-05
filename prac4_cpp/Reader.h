//Reader.h
#pragma once
class Reader {
private:
	char command;
	void move(char command);
public:
	char inputCommand();
	int inputSize();
};