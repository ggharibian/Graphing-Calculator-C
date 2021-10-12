#include "Tokenizer.h"

Tokenizer::Tokenizer(string tokens)
{
	for (int i = 0; i < tokens.length(); i++) {

		if (tokens[i] != ' ' && tokens[i] != ',') {

			if (tokens[i] == '-') {
				int e = i - 1;

				while (e > 0 && tokens[e] == ' ')
					e--;
				if (e < 0)
					_tokens.Push(new UnaryMinus());
				else if (tokens[e] != '(' && !isdigit(tokens[e]) 
					&& toupper(tokens[e]) != 'X') {
					_tokens.Push(new UnaryMinus());
				}
				else {
					_tokens.Push(new Operator(tokens.substr(i, 1)));
				}	//If statement checks to see if minus sign is unary or
					//not, then imputs them accordingly 
			}

			//FUNCTION CHECKS

			else
			if (tokens.substr(i, 3) == "sin") {
				i += 2;
				_tokens.Push(new Function("sin", 1));
			}
			else if (tokens.substr(i, 3) == "cos") {
				i += 2;
				_tokens.Push(new Function("cos", 1));
			}
			else if (tokens.substr(i, 3) == "tan") {
				i += 2;
				_tokens.Push(new Function("tan", 1));
			}
			else if (tokens.substr(i, 4) == "sinh") {
				i += 3;
				_tokens.Push(new Function("sinh", 1));
			}
			else if (tokens.substr(i, 4) == "cosh") {
				i += 3;
				_tokens.Push(new Function("cosh", 1));
			}
			else if (tokens.substr(i, 4) == "tanh") {
				i += 3;
				_tokens.Push(new Function("tanh", 1));
			}
			else if (tokens.substr(i, 3) == "log") {
				i += 2;
				_tokens.Push(new Function("log", 2));
			}
			else if (tokens.substr(i, 2) == "ln") {
				i += 1;
				_tokens.Push(new Function("ln", 1));
			}
			else if (tokens.substr(i, 6) == "arcsin") {
				i += 5;
				_tokens.Push(new Function("arcsin", 1));
			}
			else if (tokens.substr(i, 6) == "arccos") {
				i += 5;
				_tokens.Push(new Function("arccos", 1));
			}
			else if (tokens.substr(i, 6) == "arctan") {
				i += 5;
				_tokens.Push(new Function("arctan", 1));
			}

			else
			if (tokens[i] == '(') 

				_tokens.Push(new LeftParenthesis());

			else if (tokens[i] == ')')

				_tokens.Push(new RightParenthesis());

			else if (toupper(tokens[i]) == 'X')

				_tokens.Push(new Variable());

			else if (isdigit(tokens[i])) {

				int e = i;

				while (e < tokens.length() && isdigit(tokens[e]) 
					|| tokens[e] == '.') {
					e++;
				}

				_tokens.Push(new Operand(tokens.substr(i, e - i)));

				i = --e;

			}
			
			else {
				_tokens.Push(new Operator(tokens.substr(i, 1)));

			}
		}

	}
}

Queue<Token*> Tokenizer::getTokens()
{
	return _tokens;
}
