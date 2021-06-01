//
// Created by cFAG on 31/05/2021.
//

#include "Tokenizer.h"

using namespace std;

Token::Token(Token::Type type, const std::string &value) : _type(type), _value(value)
{

}

std::string Token::getValue() const
{
    return _value;
}

Token::Type Token::getType() const
{
    return _type;
}

void Tokenizer::lex(std::string &input)
{
    for (auto current = input.begin(); current != input.end(); current++) {
        switch (*current) {
            case ' ':
            case '\n':
            case '\t':
            case '\r':
                break;

            case '+':
                _token.emplace_back(Token::PLUS, "+");
                break;

            case '-':
                _token.emplace_back(Token::MINUS, "-");
                break;

            case '(':
                _token.emplace_back(Token::L_PAREN, "(");
                break;

            case ')':
                _token.emplace_back(Token::R_PAREN, ")");
                break;

            default:  // Token::INTEGER
                auto first_not_digit = find_if(current, input.end(), [](auto c) {
                    return !isdigit(c);
                });

                if (current == first_not_digit) {
                    cerr << "[ERROR] Unknown token " << *current << endl;
                    exit(-1);
                }

                string integer = string(current, first_not_digit);

                _token.emplace_back(Token::INTEGER, integer);
                current = --first_not_digit;
        }
    }
}

void Tokenizer::print_lex()
{
    for (auto& token : _token) {
        cout << token << endl;
    }
}

std::vector<Token> Tokenizer::getToken() const {
    return _token;
}
