#include "Operator.h"

Operator::Operator(string oper) : _operator(oper) {}

int Operator::typeOf()
{
	return OPERATOR;
}

string Operator::value()
{
	return _operator;
}

void Operator::print(ostream& outs)
{
	outs << _operator;
}

int Operator::precedence()
{
	if (_operator == "^") {
		return FifthPrecedence;
	}
	else if (_operator == "+" || _operator == "-")
		return SecondPrecendence;
	else
		return ThirdPrecendence;
}
