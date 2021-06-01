//
// Created by cFAG on 31/05/2021.
//

#include "Parser.h"

#include <utility>

using namespace std;


Integer::Integer(int value) : _value(value)
{}

int Integer::eval() const
{
    return _value;
}

void Integer::prettyPrint(std::ostream &os) const
{
    os << "Integer(" << _value << ")" << endl;
}

void BinaryOperation::prettyPrint(ostream &os) const
{
    _exp1->prettyPrint(os);
    os << " " << getOperatorName() << " ";
    _exp2->prettyPrint(os);
}

BinaryOperation::BinaryOperation(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
{
    _exp1 = std::move(left);
    _exp2 = std::move(right);
}

std::string Addition::getOperatorName() const
{
    return "+";
}

int Addition::eval() const
{
    return _exp1->eval() + _exp2->eval();
}

Addition::Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) : BinaryOperation(std::move(left), std::move(right))
{

}

std::string Subtraction::getOperatorName() const
{
    return "-";
}

int Subtraction::eval() const
{
    return _exp1->eval() - _exp2->eval();
}

Subtraction::Subtraction(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) : BinaryOperation(std::move(left),
                                                                                                                std::move(right))
{

}

void Parser::parse(std::vector<Token> token)
{
    for (auto current = token.begin(); current != token.end(); current++) {
        switch (current->getType()) {
            case Token::INTEGER:
                if (!_parsed)
                    _parsed.reset(new Integer(stoi(current->getValue())));
                if (!_parsed->_exp1)
                    _parsed->_exp1 = make_shared<Integer>(stoi(current->getValue()));
                else
                    _parsed->_exp2 = make_shared<Integer>(stoi(current->getValue()));
                break;

            case Token::PLUS:
                _parsed->_exp1 = make_shared<Addition>(_parsed->_exp1, _parsed->_exp2);
                break;

            case Token::MINUS:
                _parsed->_exp1 = make_shared<Subtraction>(_parsed->_exp1, _parsed->_exp2);
                break;

            default:
                break;
        }
    }
}

void Parser::prettyPrint(ostream &os)
{
    _parsed->prettyPrint(os);
}
