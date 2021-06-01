//
// Created by cFAG on 31/05/2021.
//

#ifndef CALCULFORMEL_TOKENIZER_H
#define CALCULFORMEL_TOKENIZER_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Token {
public:
    enum Type {
        INTEGER = 0,
        PLUS,
        MINUS,
        L_PAREN,
        R_PAREN,
        NB_TYPES
    };

    Token(Type type, const std::string& value);

    std::string getValue() const;
    Type getType() const;

    friend std::ostream& operator<<(std::ostream& os, const Token& token)
    {
        return os << '[' << token.getValue() << ']';
    }

private:
    Type _type;
    std::string _value;
};


class Tokenizer {
public:
    Tokenizer() = default;

    void lex(std::string& input);

    void print_lex();

    std::vector<Token> getToken() const;

private:
    std::vector<Token> _token;
};


#endif //CALCULFORMEL_TOKENIZER_H
