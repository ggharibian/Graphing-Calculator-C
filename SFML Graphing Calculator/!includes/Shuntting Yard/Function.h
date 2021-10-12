#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include "../../../!includes/myVector/myVector.h"
#include "Token.h"
using namespace std;

class Function : public Token
{
public:
	Function(string function, int args);

	int getNumArgs();

	int typeOf();

	void print(ostream& outs);

	int precedence();

	double callFunction(myVector<double>);

private:
	string _function;
	int numArgs;
};

#endif // !FUNCTION_H


