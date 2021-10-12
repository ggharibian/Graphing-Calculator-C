#include "Function.h"

Function::Function(string function, int args) : _function(function), numArgs(args) {}

int Function::getNumArgs()
{
	return numArgs;
}

int Function::typeOf()
{
	return FUNCTION;
}

void Function::print(ostream& outs)
{
	outs << _function;
}

int Function::precedence()
{
	return FifthPrecedence;
}

double Function::callFunction(myVector<double> args)
{
	if (_function == "sin") {
		return sin(args.pop_back());
	}
	else if (_function == "cos"){
		return cos(args.pop_back());
	}
	else if (_function == "tan") {
		return tan(args.pop_back());
	}
	else if (_function == "arcsin") {
		return asin(args.pop_back());
	}
	else if (_function == "arccos") {
		return acos(args.pop_back());
	}
	else if (_function == "arctan") {
		return atan(args.pop_back());
	}
	else if (_function == "sinh") {
		return sinh(args.pop_back());
	}
	else if (_function == "cosh") {
		return cosh(args.pop_back());
	}
	else if (_function == "tanh") {
		return tanh(args.pop_back());
	}
	else if (_function == "log") {
		double arg1 = args.pop_back();
		double arg2 = args.pop_back();

		return log(arg2) / log(arg1);
	}
	else {
		return log(args.pop_back());
	}
}
