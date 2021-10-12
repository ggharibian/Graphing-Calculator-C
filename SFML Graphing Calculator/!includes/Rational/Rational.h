#ifndef Rational_H
#define Rational_H

#include <string>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int n, int d);
	Rational(int w);

	void simplify();

	void set(int n, int d);
	void setNumerator(int n);
	void setDenominator(int d);

	int getNumerator() const;
	int getDenominator() const;

	bool error() const;
	string errorDescription() const;
	void clear();
	bool checkError();

	friend Rational operator +(const Rational& first, const Rational& second);
	friend Rational operator -(const Rational& first, const Rational& second);
	friend Rational operator *(const Rational& first, const Rational& second);
	friend Rational operator /(const Rational& first, const Rational& second);

	friend ostream& operator <<(ostream& outs, const Rational& r);
	friend istream& operator >>(istream& ins, Rational& r);

private:
	int _numerator;
	int _denominator;
	bool _error;
};

#endif // !Rational_H

