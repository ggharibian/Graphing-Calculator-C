#ifndef SHUNTTINGYARD_H
#define SHUNTTINGYARD_H

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

class ShunttingYard
{
public:
	ShunttingYard(Queue<Token*> q);

	Queue<Token*> getPostFix();
private:
	Queue<Token*> _postfix;
};

#endif // !SHUNTTINGYARD

