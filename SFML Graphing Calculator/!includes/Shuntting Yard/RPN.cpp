#include "RPN.h"

RPN::RPN(Queue<Token*> postFix) : _postfix(postFix) {}

RPN::~RPN()
{
}

double RPN::operator()(double x)
{
	Queue<Token*> postfix = _postfix;

	Queue<Token*>::Iterator i;

	Stack<double> buffer;

	while (!postfix.Empty()) {

		if (postfix.Front()->typeOf() == OPERAND) {
			buffer.Push(static_cast<Operand*>(postfix.Pop())->value());

		}

		else if (postfix.Front()->typeOf() == VARIABLE) {
			buffer.Push(x);
			postfix.Pop();

		}

		else if (postfix.Front()->typeOf() == UNARYMINUS) {
			buffer.Push(buffer.Pop() * -1);
			postfix.Pop();
		}

		else if (postfix.Front()->typeOf() == OPERATOR) {

			double num2 = buffer.Pop();
			double num1 = buffer.Pop();


			switch (static_cast<Operator*>(postfix.Pop())->value()[0]) {
			case '+':
				buffer.Push(num1 + num2);
				break;
			case '-':
				buffer.Push(num1 - num2);
				break;
			case '*':
				buffer.Push(num1 * num2);
				break;
			case '/':
				buffer.Push(num1 / num2);
				break;
			case '^':
				buffer.Push(pow(num1, num2));
				break;

			}
		}
		else if (postfix.Front()->typeOf() == FUNCTION) {
			myVector<double> args;

			for (int i = 0; i < static_cast<Function*>(postfix.Front())->getNumArgs(); i++) {
				args.push_back(buffer.Pop());
			}

			buffer.Push(static_cast<Function*>(postfix.Pop())->callFunction(args));
		}
	}

	double ans = buffer.Pop();

	assert(buffer.Empty());

	return ans;
}
