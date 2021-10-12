#ifndef OPERAND_H
#define OPERAND_H

#include "Token.h"
#include <string>
using namespace std;

class Operand : public Token
{
public:

	Operand(string value);

	Operand(double value);

	Operand& operator =(string value);

	Operand& operator =(double value);

	int typeOf();

	int precedence();

	double value();

	void print(ostream& outs);

private:
	double _value = 0;
};

#endif // !OPERAND_H


