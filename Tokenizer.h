#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Token.h"

using namespace std;

class Tokenizer
{
public:
	Tokenizer(string& input)
	{
		Input = input;
		CurrentPosition = 0;
		CurrentLine = 1;
	}

	Token* getNextToken();

private:
	string Input;
	unsigned int CurrentPosition;
	int CurrentLine;
	bool Match(const char* match);
};

#endif 
