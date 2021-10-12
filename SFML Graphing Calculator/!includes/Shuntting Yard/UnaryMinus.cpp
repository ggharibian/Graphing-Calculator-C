#include "UnaryMinus.h"

int UnaryMinus::typeOf()
{
	return UNARYMINUS;
}

void UnaryMinus::print(ostream& outs)
{
	outs << "[-]";
}

int UnaryMinus::precedence()
{
	return SixthPrecedence;
}
