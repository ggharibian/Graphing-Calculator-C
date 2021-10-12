#include "Poly.h"

//------------------------------------------
//Consrtuctor:
//------------------------------------------

Poly::Poly(SortedList<Term> poly): _error(false)
{
	_polynomial = poly;
	_polynomial.InsertItem(Term());
	fixOrder();
		//We must call fix order in case an List with 0s is inputted.
}

//------------------------------------------
//Big Three Functions
//------------------------------------------

Poly::Poly(const Poly& other)
{
	_polynomial = other._polynomial;
	_error = other._error;
	fixOrder();
}

Poly& Poly::operator=(const Poly& rhs)
{
	if (this == &rhs)
		return *this;

	_polynomial = rhs._polynomial;
	_error = rhs._error;
	fixOrder();

	return *this;
}

Poly::~Poly()
{
	_polynomial.~SortedList();
}

//------------------------------------------
//Comparison Operators:
//------------------------------------------

bool operator==(const Poly& lhs, const Poly& rhs)
{
	return lhs._polynomial == rhs._polynomial;
}

bool operator!=(const Poly& lhs, const Poly& rhs)
{
	return !(lhs == rhs);
}

//------------------------------------------
//Sumation Operators:
//------------------------------------------

Poly Poly::operator+=(const Term& t)
{
	_polynomial.InsertItem(t);

	return *this;
}

Poly Poly::operator+=(const Poly& rhs)
{
	if (_error || rhs.error()) {
		_error = true;
		return *this;
	}
		//Will return an undefined object if either statement has an error
		//flag triggered.

	for (SortedList<Term>::Iterator walker = rhs._polynomial.Begin(); walker != rhs._polynomial.End(); walker++) {
		*this += walker->_obj;
	}

	fixOrder();

	return *this;
}

Poly operator+(const Poly& lhs, const Term& t)
{
	Poly temp = lhs;

	temp += t;

	return temp;
}

Poly operator+(const Poly& lhs, const Poly& rhs)
{

	Poly temp = lhs;

	if (lhs.error() || rhs.error()) {
		temp._error = true;
		return temp;
	}
		//Will return an undefined object if either statement has an error
		//flag triggered.

	temp += rhs;

	return temp;
}

//------------------------------------------
//Difference Operators:
//------------------------------------------

Poly operator-(const Poly& p)
{
	Poly temp;

	if (p.error()) {
		temp._error = true;
		return temp;
	}

	for (SortedList<Term>::Iterator i = p._polynomial.Begin(); i != p._polynomial.End(); i++) {
		temp += -i->_obj;
	}

	temp.fixOrder();
		//There is a possiblity that subtracting two polynomials will result in a
		//"0" polynomial, so we must call this function.

	return temp;
}

Poly operator-(const Poly& lhs, const Poly& rhs)
{
	return Poly(lhs) + -rhs;
}

Poly Poly::operator-=(const Term& t)
{
	*this += -t;
	return *this;
}

Poly Poly::operator-=(const Poly& rhs)
{
	*this += -rhs;
	return *this;
}

Poly Poly::operator*=(const Term& t)
{
	*this = *this * t;
	return *this;
}

//------------------------------------------
//Product Operators:
//------------------------------------------

Poly operator*(const Poly& lhs, const Term& t)
{
	Poly temp = lhs;

	for (SortedList<Term>::Iterator i = temp._polynomial.Begin(); i != temp._polynomial.End(); i++) {
		i->_obj *= t;
	}

	temp.fixOrder();
		//There is a possiblity that multiplying two polynomials will result in a
		//"0" polynomial, so we must call this function.

	return temp;
}

Poly operator*(const Poly& lhs, const Poly& rhs)
{
	Poly ans;

	if (lhs.error() || rhs.error()) {
		ans._error = true;
		return ans;
	}
		//Error check, will return undefined polynomial if triggered.

	for (SortedList<Term>::Iterator i = rhs._polynomial.Begin(); i != rhs._polynomial.End(); i++) {
		ans += lhs * i->_obj;
	}

	ans.fixOrder();

	return ans;
}

Poly& Poly::operator*=(const Poly& rhs)
{
	*this = *this * rhs;

	return *this;
}

Poly Poly::operator/=(const Term& t)
{
	for (SortedList<Term>::Iterator i = _polynomial.Begin(); i->_obj >= t && i < _polynomial.End(); i++)
		i->_obj /= t;

	return *this;
}

Poly Poly::operator/=(const Poly& rhs)
{
	*this = *this / rhs;
	return *this;
}

//------------------------------------------
//Quotient And Modulus Operators:
//------------------------------------------

Poly operator/(const Poly& lhs, const Poly& rhs)
{
	Poly ans;

	if (rhs._polynomial.Begin()->_obj.getExponent() == 0 && rhs._polynomial.Begin()->_obj.getCoefficient() == 0) {
		ans = rhs;
		ans._error = true;
		return ans;
		//If rhs is 0, then the result of this function will be
		//a Poly / 0 which is undefined. An error Polynomial will 
		//return.
	}

	Poly tempDivisor = lhs;
	Poly tempDividend;
	Term nextTermInAns;

	int index = tempDivisor._polynomial.Begin()->_obj.getExponent() - rhs._polynomial.Begin()->_obj.getExponent();

	while (index >= 0 && (tempDivisor != Poly() || tempDivisor._polynomial.Begin()->_obj.getCoefficient() != 0)) {
				//The loop will stop when the next term in the "ans"
				//polynomial results in a remainder, or when we begin to
				//divide by 0.

		nextTermInAns = tempDivisor._polynomial.Begin()->_obj / rhs._polynomial.Begin()->_obj;
				//This will aquire the next term that will be imputted into answer.

		ans += nextTermInAns;
				//Answer is updated with the next term.

		tempDividend = rhs * nextTermInAns;
				//We aquire the current remainder from the next term in ans;
				//This will be subtracted from the current quotient.

		tempDivisor -= tempDividend;
				//We subtract the current divisor by the product of the
				//nextTermInAnswer and the dividend.

		tempDivisor.fixOrder();
				//Fix order, in case we get a zero sum result.

		index = tempDivisor._polynomial.Begin()->_obj.getExponent() - rhs._polynomial.Begin()->_obj.getExponent();
				//Get the next highest order in answer for comparison in the while loop.
	}

	return ans;
}

Poly operator%(const Poly& lhs, const Poly& rhs)
{
	Poly ans = lhs - lhs / rhs * rhs;

	ans.fixOrder();

	return ans;
}

//------------------------------------------
//Error Functions:
//------------------------------------------

bool Poly::error() const
{
	return _error;
}

string Poly::errorDescription() const
{
	if (_error)
		return "The polynomial is undefined.";
	else
		return "There are no errors.";
}

void Poly::clear()
{
	_error = false;
}

//------------------------------------------
//IOStream Operators:
//------------------------------------------

ostream& operator <<(ostream& outs, const Poly& p)
{
	outs << "[";
	if (p.error()) {
		outs << "undef";
	}		//If the Poly p has ever been divided by 0 then the value will
			//be printed as undefined.
	else {
		outs << p._polynomial.Begin()->_obj;

		if (p._polynomial.Begin().Next()) {

			for (SortedList<Term>::Iterator i = p._polynomial.Begin().Next(); i != p._polynomial.End(); i++) {

				if (i->_obj.getCoefficient() > 0)
					outs << " + " << i->_obj;

				else if (i->_obj.getCoefficient() < 0)
					outs << " - " << i->_obj * Term(-1, 0);

				//This if/else statement helps to increase the readability
				//of the output by seperating the +/- signs from the Term
				//to easier signify addition and subtraction.
			}
		}
	}
	outs << "]";

	return outs;
}

istream& operator>>(istream& ins, Poly& p)
{
	p = Poly();
	//We have to reset the previous value of p to 0 in order utilize
	//the += operator.

	Term temp;
	//The current term to be inputted in the loop.

	char c;
	//The user's last-inputted character

	bool positive = true;
	//Signifies whether the term is a positive or negative number.

	do {
		//Will run until the user inputs the x^0 value
		//Ex.
		//3x^3 + 1x^1 + 0x^0
		//				^^^^
		do {
			cin.get(c);
			if (c == '-')
				positive = !positive;

		} while (!isdigit(c));

		//This loop will take care of all white space preceding an
		//inputted Term and will trace the sign of the Term.
		//Ex. 
		//		-3x^6 - -5x^2 + -3x^0
		//		^     ^ ^       ^
		//If statement will catch and trace all negative values preceding
		//the Term and evaluate the overall value of the polynomial. This
		//example will become:
		//		-3x^6 + 5x^2 - 3x^0


		cin.putback(c);
		ins >> temp;

		if (!positive)
			temp = -temp;
		//Changes the current Term to negative based on the previous 
		//loop.

		positive = true;

		p += temp;

	} while (temp.getExponent() != 0);

	return ins;
}

//------------------------------------------
//Private Helper Function:
//------------------------------------------

void Poly::fixOrder()
{
	SortedList<Term>::Iterator walker = _polynomial.Begin();

	while (walker.Next() != _polynomial.End()) {

		if (walker->_obj.getCoefficient() == 0) {
			_polynomial.Delete(walker++);
		}
		else
			walker++;
	}
}