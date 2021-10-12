#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "Constants.h"
using namespace std;

class Token
{
public:
	virtual int typeOf() = 0;
	virtual void print(ostream& outs) = 0;
	virtual int precedence() = 0;

};

#endif // !TOKEN_H

