#include "IncludedHeaders.h"
#include <ctype.h>

using namespace std;
bool Tokenizer::Match(const char* match)
{
	int i = 0;
	while (match[i] != '\0')
	{
		if ((CurrentPosition + i ) > Input.size() || match[i] != Input.at(CurrentPosition + i))
		{
			return false;
		}		
		++i;
	}
	CurrentPosition += i;
	return true;
}

Token* Tokenizer::getNextToken()
{
	while (CurrentPosition < Input.size())
	{
		char c = Input.at(CurrentPosition);
		if (c == ' ' || c == '\t' || c == '\r')
		{
			++CurrentPosition;
		}
		else if (c == '\n')
		{
			++CurrentPosition;
			++CurrentLine;
		}
		else if (c == ',')
		{
			++CurrentPosition;
			return new Token(TokenType::COMMA, ",", CurrentLine);
		}
		else if (c == '.')
		{
			++CurrentPosition;
			return new Token(TokenType::PERIOD, ".", CurrentLine);
		}
		else if (c == '?')
		{
			++CurrentPosition;
			return new Token(TokenType::Q_MARK, "?", CurrentLine);
		}
		else if (c == '(')
		{
			++CurrentPosition;
			return new Token(TokenType::LEFT_PAREN, "(", CurrentLine);
		}
		else if (c == ')')
		{
			++CurrentPosition;
			return new Token(TokenType::RIGHT_PAREN, ")", CurrentLine);
		}
		else if (c == ':')
		{
			++CurrentPosition;
			if (CurrentPosition != Input.size())
			{
				if (Input.at(CurrentPosition) == '-')
				{
					++CurrentPosition;
					return new Token(TokenType::COLON_DASH, ":-", CurrentLine);
				}
			}
			return new Token(TokenType::COLON, ":", CurrentLine);
		}
		else if (c == '*')
		{
			++CurrentPosition;
			return new Token(TokenType::MULTIPLY, "*", CurrentLine);
		}
		else if (c == '+')
		{
			++CurrentPosition;
			return new Token(TokenType::ADD, "+", CurrentLine);
		}
		/*else if (Match("Schemes"))         //Didn't want me to catch it everytime
		{
			return new Token(TokenType::SCHEMES, "Schemes", CurrentLine);
		}
		else if (Match("Facts"))
		{
			return new Token(TokenType::FACTS, "Facts", CurrentLine);    
		}
		else if (Match("Rules"))
		{
			return new Token(TokenType::RULES, "Rules", CurrentLine);
		}
		else if (Match("Queries"))
		{
			return new Token(TokenType::QUERIES, "Queries", CurrentLine);
		}*/
		else if (isalpha(c))
		{
			unsigned int i = 0;
			while (CurrentPosition + i < Input.size() && isalnum(Input.at(CurrentPosition + i)))
			{
				++i;
			}			
			CurrentPosition += i;
			string value = Input.substr(CurrentPosition - i, i);
			if (value == "Schemes")
			{
				return new Token(TokenType::SCHEMES, value, CurrentLine);
			}
			if (value == "Facts")
			{
				return new Token(TokenType::FACTS, value, CurrentLine);
			}
			if (value == "Rules")
			{
				return new Token(TokenType::RULES, value, CurrentLine);
			}
			if (value == "Queries")
			{
				return new Token(TokenType::QUERIES, value, CurrentLine);
			}
			return new Token(TokenType::ID, value, CurrentLine);			
		}
		else if (c == '\'')
		{
			int startingLine = CurrentLine;
			unsigned int i = 1;
			for (;;)
			{
				if (CurrentPosition + i >= Input.size())
				{
					// Reached end without a quote
					string value = Input.substr(CurrentPosition, i);
					CurrentPosition += i;
					return new Token(TokenType::UNDEFINED, value, startingLine);
				}
				if (Input.at(CurrentPosition + i) == '\'')
				{
					if (CurrentPosition + i + 1 < Input.size() - 1 && Input.at(CurrentPosition + i + 1) == '\'')
					{
						i += 2;
					}
					else
					{
						++i;
						string value = Input.substr(CurrentPosition, i);
						CurrentPosition += i;
						return new Token(TokenType::STRING, value, startingLine);
					}
				}
				else if (Input.at(CurrentPosition + i) == '\n')
				{
					++CurrentLine;
					++i;
				}
				else
				{
					++i;
				}
			}
		}
		else if (c == '#')
		{
			if (CurrentPosition + 1 < Input.size() && Input.at(CurrentPosition + 1) == '|')
			{
				// Block Comment
				unsigned int startingline = CurrentLine;
				unsigned int i = 1;
				while (CurrentPosition + i + 1 < Input.size() && (Input.at(CurrentPosition + i) != '|' || Input.at(CurrentPosition + i + 1) != '#'))
				{
					if (Input.at(CurrentPosition + i) == '\n')
					{
						++CurrentLine;
					}
					++i;
				}
				if (CurrentPosition + i + 1 <= Input.size())
				{
					i += 2;
					CurrentPosition += i;
					return new Token(TokenType::COMMENT, Input.substr(CurrentPosition - i, i), startingline);
				}
				else
				{
					i = Input.size() - CurrentPosition;
					CurrentPosition += i;
					return new Token(TokenType::UNDEFINED, Input.substr(CurrentPosition - i, i), startingline);
				}
			}
			else
			{
				// Line Comment
				unsigned int i = 1;
				while (Input.at(CurrentPosition + i) != '\n')
				{
					++i;
				}
				CurrentPosition += i;
				return new Token(TokenType::COMMENT, Input.substr(CurrentPosition - i, i), CurrentLine);
			}
		}
		else 
		{
			++CurrentPosition;
			return new Token(TokenType::UNDEFINED, string(1,c), CurrentLine);
		}
	}
	return new Token(TokenType::END, "", CurrentLine);
}


