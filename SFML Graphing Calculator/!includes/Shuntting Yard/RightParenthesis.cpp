#include "RightParenthesis.h"

int RightParenthesis::typeOf()
{
	return RPARENTEHSIS;
}

void RightParenthesis::print(ostream& outs)
{
	outs << ")";
}

int RightParenthesis::precedence()
{
	return FourthPrecedence;
}
