#ifndef OPERATOR_H
#define OPERATOR_H

#include "Token.h"
#include <string>
using namespace std;

class Operator : public Token
{
public:

	Operator(string oper);

	int typeOf();

	string value();

	void print(ostream& outs);

	int precedence();
private:
	string _operator;
};

#endif // !OPERATOR_H

