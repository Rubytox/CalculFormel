//
// Created by cFAG on 31/05/2021.
//

#ifndef CALCULFORMEL_PARSER_H
#define CALCULFORMEL_PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Tokenizer.h"

class Expression {
public:
    Expression() = default;

    virtual int eval() const = 0;
    virtual void prettyPrint(std::ostream& os) const = 0;

    std::shared_ptr<Expression> _exp1;
    std::shared_ptr<Expression> _exp2;
};

class Integer : public Expression {
public:
    explicit Integer(int value);

    int eval() const override;
    void prettyPrint(std::ostream& os) const override;

private:
    int _value;
};

class BinaryOperation : public Expression {
public:
    BinaryOperation(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

    void prettyPrint(std::ostream& os) const override;

    virtual std::string getOperatorName() const = 0;
};

class Addition : public BinaryOperation {
public:
    Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

    std::string getOperatorName() const override;
    int eval() const override;
};

class Subtraction : public BinaryOperation {
public:
    Subtraction(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

    std::string getOperatorName() const override;
    int eval() const override;
};

class Parser {
public:
    Parser() = default;

    void parse(std::vector<Token> token);
    void prettyPrint(std::ostream& os);

private:
    std::shared_ptr<Expression> _parsed;
};


#endif //CALCULFORMEL_PARSER_H
