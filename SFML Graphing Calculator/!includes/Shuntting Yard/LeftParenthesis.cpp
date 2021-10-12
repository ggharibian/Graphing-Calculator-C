#include "LeftParenthesis.h"

int LeftParenthesis::typeOf()
{
	return LPARENTHESIS;
}

void LeftParenthesis::print(ostream& outs)
{
	outs << "(";
}

int LeftParenthesis::precedence()
{
	return FirstPrecedence;
}
