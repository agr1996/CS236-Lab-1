#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum class TokenType
{
	COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	COLON,
	COLON_DASH,
	MULTIPLY,
	ADD,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	ID,
	STRING,
	COMMENT,
	UNDEFINED,
	END
};

class Token
{
public:
	Token(TokenType type, string contents, int lineNumber)
	{
		Type = type;
		Contents = contents;
		LineNumber = lineNumber;
	}
	Token(TokenType type, char* contents, int lineNumber)
	{
		Type = type;
		Contents = string(contents);
		LineNumber = lineNumber;
	}
	TokenType Type;
	string Contents;
	int LineNumber;

	static string tokenTypeToString(TokenType value);

private:



};

#endif 