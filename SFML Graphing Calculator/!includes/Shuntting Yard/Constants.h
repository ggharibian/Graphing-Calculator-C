#ifndef CONSTANTS_H
#define CONSTANTS_H

enum {
	LPARENTHESIS,
	RPARENTEHSIS,
	OPERATOR,
	OPERAND,
	FUNCTION,
	VARIABLE,
	UNARYMINUS,
	FirstPrecedence = 1, // ( )
	SecondPrecendence = 2,// 
	ThirdPrecendence = 3,
	FourthPrecedence = 4,
	FifthPrecedence = 5,
	SixthPrecedence = 6
};

#endif // !CONSTANTS_H
