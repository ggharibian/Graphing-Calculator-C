#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
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
using namespace std;

class Tokenizer
{
public:
	Tokenizer(string tokens);

	Queue<Token*> getTokens();

private:
	Queue<Token*> _tokens;
};

#endif // !TOKENIZER_H

