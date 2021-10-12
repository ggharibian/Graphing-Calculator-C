#include "Term.h"

//------------------------------------------
//Consrtuctors:
//------------------------------------------

Term::Term()
{
	_coefficient = 0;
	_exponent = 0;
}

Term::Term(int exponent): _exponent(exponent)
{
	assert(exponent >= 0);
			//Checks for negative exponent values.
	_coefficient = 1;
}

Term::Term(double coeff, int exponent): _coefficient(coeff), _exponent(exponent)
{
	assert(exponent >= 0);
			//Checks for negative exponent values.
}

//------------------------------------------
//Accessor Functions:
//------------------------------------------

double Term::getCoefficient() const
{
	return _coefficient;
}

int Term::getExponent() const
{
	return _exponent;
}

//------------------------------------------
//Sumation Operator:
//------------------------------------------

Term operator+(const Term& left, const Term& right)
{
	assert(left._exponent == right._exponent);
			//You are only able to add two Terms that have the same exponent.
			//The program will crash if otherwise.

	return Term(left._coefficient + right._coefficient, left._exponent);
			//Ex. 3x^4 + 4x^4 = 7x^4
}

Term Term::operator+=(const Term& right)
{
	*this = *this + right;

	return *this;
}

//------------------------------------------
//Difference Operators:
//------------------------------------------

Term operator-(const Term& t)
{
	return Term(-1 * t._coefficient, t._exponent);
}

Term operator-(const Term& left, const Term& right)
{
	return left + -right;
			//Ex. 3x^4 + -4x^4 = 3x^4 - 4x^4 = -1x^4
}

Term Term::operator-=(const Term& right)
{
	return *this += -right;
}

//------------------------------------------
//Product Operator:
//------------------------------------------

Term operator*(const Term& left, const Term& right)
{
	return Term(left._coefficient * right._coefficient, left._exponent 
		+ right._exponent);
			//Ex. 3x^2 * 4x^2 = 12x^4
}

Term Term::operator*=(const Term& right)
{
	*this = *this * right;

	return *this;
}

//------------------------------------------
//Quotient Operator:
//------------------------------------------

Term operator/(const Term& left, const Term& right)
{
	return Term(left._coefficient / right._coefficient, left._exponent
		- right._exponent);
			//Ex. 4x^2 / 2x^1 = 2x^1
}

Term Term::operator/=(const Term& right)
{
	*this = *this / right;

	return *this;
}

//------------------------------------------
//IOStream  Operators:
//------------------------------------------

ostream& operator<<(ostream& outs, const Term& t)
{
	if (t._coefficient != 1 || t.getExponent() == 0)
		outs << fixed << showpoint << setprecision(1) << t._coefficient;

	if (t.getExponent() != 0)
		outs << "x^" << t._exponent;

	return outs;
}

istream& operator>>(istream& ins, Term& t)
{
	char c1, c2;
	ins >> t._coefficient >> c1 >> c2 >> t._exponent;
	assert(t._exponent >= 0);

	return ins;
}

//------------------------------------------
//Comparison Operators:
//------------------------------------------

bool operator==(const Term& lhs, const Term& rhs)
{
	return lhs._exponent == rhs._exponent;
}

bool operator!=(const Term& lhs, const Term& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const Term& lhs, const Term& rhs)
{
	return lhs._exponent > rhs._exponent;
}

bool operator<(const Term& lhs, const Term& rhs)
{
	return lhs._exponent < rhs._exponent;
}

bool operator>=(const Term& lhs, const Term& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator<=(const Term& lhs, const Term& rhs)
{
	return lhs > rhs || lhs == rhs;
}


