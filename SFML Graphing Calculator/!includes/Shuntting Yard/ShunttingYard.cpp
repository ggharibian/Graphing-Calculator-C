#include "ShunttingYard.h"

ShunttingYard::ShunttingYard(Queue<Token*> q)
{
	Stack<Token*> buffer;

	while (!q.Empty()) {

		if (q.Front()->typeOf() == VARIABLE || q.Front()->typeOf() == OPERAND)

			_postfix.Push(q.Pop());

		else if (buffer.Empty())

			buffer.Push(q.Pop());

		else if (q.Front()->precedence() == SixthPrecedence) {
			buffer.Push(q.Pop());
			_postfix.Push(q.Pop());
			_postfix.Push(buffer.Pop());
		}
		else if (q.Front()->precedence() == FourthPrecedence) {
			q.Pop();

			while (buffer.Top()->precedence() != FirstPrecedence) {
				_postfix.Push(buffer.Pop());
			}

			buffer.Pop();

		}

		else if (q.Front()->precedence() == FirstPrecedence 
			|| buffer.Top()->precedence() < q.Front()->precedence()) {

			buffer.Push(q.Pop());
		}

		else if (buffer.Top()->precedence() >= q.Front()->precedence()) {

			while (!buffer.Empty() && buffer.Top()->precedence() >= q.Front()->precedence())

				_postfix.Push(buffer.Pop());

			buffer.Push(q.Pop());
		}
	}

	while (!buffer.Empty())
		_postfix.Push(buffer.Pop());
}

Queue<Token*> ShunttingYard::getPostFix()
{
	return _postfix;
}


