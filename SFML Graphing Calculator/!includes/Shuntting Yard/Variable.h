#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include "Token.h"
using namespace std;

class Variable : public Token
{
	int typeOf();
	void print(ostream& outs);
	int precedence();
};

#endif // !VARIABLE_H

