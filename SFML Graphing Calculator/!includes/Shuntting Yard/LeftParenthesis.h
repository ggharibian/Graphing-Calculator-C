#ifndef LEFTPARENTHESIS
#define LEFTPARENTHESIS

#include <iostream>
#include "Token.h"
using namespace std;

class LeftParenthesis : public Token
{
public:
	int typeOf();
	void print(ostream& outs);
	int precedence();
};

#endif // !LEFTPARENTHESIS