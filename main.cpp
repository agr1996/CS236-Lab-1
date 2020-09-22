// Lab 1 Scanner-Tokenizer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "IncludedHeaders.h"

using namespace std;

string InputFromFile(istream& in)
{
    ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

int main(int argc, char* argv[])
{
    ofstream out(argv[2]);
    {
        
        ifstream in(argv[1]);
        string input(InputFromFile(in));
        in.close();
           
        Lexer lexer;
        lexer.Tokenize(input);
        
        vector<Token*>& tokens = lexer.GetTokens();

        for (unsigned int i = 0; i < tokens.size(); ++i)
        {
            Token* token = tokens.at(i);
            out << "(" << Token::tokenTypeToString(token->Type) << ",\"" << token->Contents << "\"," << token->LineNumber << ")\n";
        }
        out << "Total Tokens = " << tokens.size();


    }





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
