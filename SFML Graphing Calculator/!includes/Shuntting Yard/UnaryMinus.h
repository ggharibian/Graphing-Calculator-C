#ifndef UNARYMINUS_H
#define UNARYMINUS_H

#include "Token.h"
#include <string>
using namespace std;

class UnaryMinus : public Token
{
public:

	int typeOf();

	void print(ostream& outs);

	int precedence();
private:
	string _operator;
};

#endif // !UNARYMINUS_H
