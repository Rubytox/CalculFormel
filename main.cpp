#include <iostream>
#include <string>

#include "Tokenizer.h"
#include "Parser.h"

using namespace std;

int main()
{
    string prompt = "> ";

    cout << prompt;
    string input;
    while (getline(cin, input)) {
        if (input == "exit")
            break;

        Tokenizer tokenizer;
        tokenizer.lex(input);
        tokenizer.print_lex();
        Parser parser;
        parser.parse(tokenizer.getToken());
        parser.prettyPrint(cout);

        cout << prompt;
    }

    return 0;
}
