#ifndef RIGHTPARENTHEISIS
#define RIGHTPARENTHEISIS

#include <iostream>
#include "Token.h"
using namespace std;

class RightParenthesis : public Token
{
public:
	int typeOf();
	void print(ostream& outs);
	int precedence();
};

#endif // !RIGHTPARENTHEISIS

