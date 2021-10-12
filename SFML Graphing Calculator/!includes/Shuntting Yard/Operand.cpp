#include "Operand.h"

Operand::Operand(const string value) : _value(stod(value)) {}

Operand::Operand(const double value) : _value(value) {}

Operand& Operand::operator=(const string value)
{
	*this = Operand(value);

	return *this;
}

Operand& Operand::operator=(const double value)
{
	*this = Operand(value);

	return *this;
}

int Operand::typeOf()
{
	return OPERAND;
}

int Operand::precedence()
{
	return FifthPrecedence;
}

double Operand::value()
{
	return _value;
}

void Operand::print(ostream& outs)
{
	outs << _value;
}
