#ifndef TERM_H
#define TERM_H
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Term
{
public:
	//Constructors
	Term();
	Term(int exponent);
	Term(double coeff, int exponent);

	//Accessors
	double getCoefficient() const;
	int getExponent() const;

	//Sumation Operators
	Term operator +=(const Term& right);
	friend Term operator +(const Term& left, const Term& right);

	//Difference Operators
	Term operator -=(const Term& right);
	friend Term operator -(const Term& t);
	friend Term operator -(const Term& left, const Term& right);

	//Product Operators
	Term operator *=(const Term& right);
	friend Term operator *(const Term& left, const Term& right);

	//Quotient Operators
	Term operator /=(const Term& right);
	friend Term operator /(const Term& left, const Term& right);

	//IOStream Operators
	friend ostream& operator <<(ostream& outs, const Term& t);
	friend istream& operator >>(istream& ins, Term& t);

	//Comparison Operators
	friend bool operator ==(const Term& lhs, const Term& rhs);
	friend bool operator !=(const Term& lhs, const Term& rhs);
	friend bool operator >(const Term& lhs, const Term& rhs);
	friend bool operator <(const Term& lhs, const Term& rhs);
	friend bool operator >=(const Term& lhs, const Term& rhs);
	friend bool operator <=(const Term& lhs, const Term& rhs);

private:
	double _coefficient; //The coefficient of a Term
	int _exponent;	//The exponent of the Term
};

#endif // !TERM_H

