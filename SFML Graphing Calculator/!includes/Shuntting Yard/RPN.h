#ifndef RPN_H
#define RPN_H
#include <cmath>
#include <iostream>
#include "UnaryMinus.h"
#include "Function.h"
#include "Token.h"
#include "Operand.h"
#include "Variable.h"
#include "Operator.h"
#include "LeftParenthesis.h"
#include "RightParenthesis.h"
#include "Constants.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"
using namespace std;

class RPN
{
public:
	RPN(Queue<Token*> postFix);

	~RPN();

	double operator ()(double x);

private:
	Queue<Token*> _postfix;
};

#endif // !RPN

