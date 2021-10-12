#include "Variable.h"

int Variable::typeOf()
{
	return VARIABLE;
}

void Variable::print(ostream& outs)
{
	outs << "X";
}

int Variable::precedence()
{
	return FifthPrecedence;
}
