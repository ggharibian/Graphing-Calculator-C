#include "Rational.h"
#include <iostream>

Rational::Rational(): _numerator(0), _denominator(1){
	checkError();
}

Rational::Rational(int n, int d): _numerator(n), _denominator(d) {
	checkError();
}

Rational::Rational(int w): _numerator(w), _denominator(1){
	checkError();
}

void Rational::simplify(){
	int num = 10;
	while (num >= 2) {
		while (_numerator % num == 0 && _denominator % num == 0) {
			_numerator /= num;
			_denominator /= num;
		}
		num--;
	}

	if (_denominator != 0 &&_numerator % _denominator == 0) {
		_numerator /= _denominator;
		_denominator = 1;
	}
	if (_numerator != 0 && _denominator % _numerator == 0) {
		_denominator /= _numerator;
		_numerator = 1;
	}
}

void Rational::set(int n, int d){
	_numerator = n;
	_denominator = d;
	checkError();
}

void Rational::setNumerator(int n) {
	_numerator = n;
	checkError();
}
void Rational::setDenominator(int d) {
	_denominator = d;
	checkError();
}

int Rational::getNumerator() const
{
	return _numerator;
}

int Rational::getDenominator() const
{
	return _denominator;
}

bool Rational::error() const{
	return _error;
}

string Rational::errorDescription() const
{
	if (_error == true) {
		return "The Rational number is undefined.";
	}
	else {
		return "No error.";
	}
}

void Rational::clear(){
	_numerator = 0;
	_denominator = 1;
	_error = false;
}

bool Rational::checkError()
{
	if (_denominator == 0)
		_error = true;
	else
		_error = false;

	return _error;
}

Rational operator+(const Rational& first, const Rational& second)
{
	if (first.error() || second.error()) {
		return Rational(1, 0);
	}

	int newNumerator = first._numerator * second._denominator + 
		second._numerator * first._denominator;
	int newDenominator = first._denominator * second._denominator;

	Rational newR = Rational(newNumerator, newDenominator);
	newR.simplify();

	return newR;

}

Rational operator-(const Rational& first, const Rational& second)
{
	if (first.error() || second.error()) {
		return Rational(1, 0);
	}

	int newNumerator = first._numerator * second._denominator -
		second._numerator * second._denominator;
	int newDenominator = first._denominator * second._denominator;

	return Rational(newNumerator, newDenominator);
}

Rational operator*(const Rational& first, const Rational& second)
{
	if (first.error() || second.error()) {
		return Rational(1, 0);
	}

	int newNumerator = first._numerator * second._numerator;
	int newDenominator = first._denominator * second._denominator;

	return Rational(newNumerator, newDenominator);
}

Rational operator/(const Rational& first, const Rational& second)
{
	if (first.error() || second.error()) {
		return Rational(1, 0);
	}

	int newNumerator = first._numerator * second._denominator;
	int newDenominator = first._denominator * second._numerator;

	return Rational(newNumerator, newDenominator);
}

ostream& operator<<(ostream& outs, const Rational& r)
{
	outs << r.getNumerator() << '/' << r.getDenominator();

	return outs;
}

istream& operator>>(istream& ins, Rational& r)
{
	int n, d;
	char c;

	ins >> n >> c >> d;

	r = Rational(n, d);

	return ins;
}

