#ifndef LEXER_H
#define LEXER_H

#include "Tokenizer.h"

using namespace std;

class Lexer
{
public:
	void Tokenize(string& input)
	{
		Tokenizer tokenizer(input);
		for (;;)
		{
			Token* current = tokenizer.getNextToken();
			Tokens.push_back(current);

			if (current->Type == TokenType::END)
			{
				break;
			}
		}
	}
	vector<Token*>& GetTokens()
	{
		return Tokens;
	}


private:
	vector<Token*> Tokens;



};

#endif