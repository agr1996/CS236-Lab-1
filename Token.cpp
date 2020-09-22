#include "Token.h"

using namespace std;

string tokenTypeStrings[] = {
	string("COMMA"),
	string("PERIOD"), 
	string("Q_MARK"),
	string("LEFT_PAREN"),
	string("RIGHT_PAREN"),
	string("COLON"),
	string("COLON_DASH"),
	string("MULTIPLY"),
	string("ADD"),
	string("SCHEMES"),
	string("FACTS"),
	string("RULES"),
	string("QUERIES"),
	string("ID"),
	string("STRING"),
	string("COMMENT"),
	string("UNDEFINED"),
	string("EOF"),
};

string Token::tokenTypeToString(TokenType value)
{
	return tokenTypeStrings[(int)value];
}
