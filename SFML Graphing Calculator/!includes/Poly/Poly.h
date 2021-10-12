#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <string>
#include "../Term/Term.h"
#include "../List/SortedList.h"
using namespace std;

class Poly
{
public:
    Poly(SortedList<Term> poly = SortedList<Term>());

    //the BIG 3
    //Note: I understand that I don't need these functions; I wanted to write
    //them anyway just for practice.

    Poly(const Poly& other);
    Poly& operator =(const Poly& rhs);
    ~Poly();

    //Comparison Operators
    friend bool operator ==(const Poly& lhs, const Poly& rhs);//Checks if two
                                                              //Polys are
                                                              //equal.
    friend bool operator !=(const Poly& lhs, const Poly& rhs);//Checks if two
                                                              //Polys are
                                                              //unequal.

    //Sumation Operators
    Poly operator +=(const Term& t);
    Poly operator +=(const Poly& rhs);
    friend Poly operator +(const Poly& lhs, const Term& t);
    friend Poly operator +(const Poly& lhs, const Poly& rhs);

    //Difference Operators
    Poly operator -=(const Term& t);
    Poly operator -= (const Poly& rhs);
    friend Poly operator -(const Poly& p);
    friend Poly operator - (const Poly& lhs, const Poly& rhs);

    //Product Operators
    Poly operator *=(const Term& t);
    Poly& operator *=(const Poly& rhs);
    friend Poly operator *(const Poly& lhs, const Term& t);
    friend Poly operator *(const Poly& lhs, const Poly& rhs);

    //Quotient and Modulus Operators
    Poly operator /=(const Term& t);
    Poly operator /=(const Poly& rhs);
    friend Poly operator /(const Poly& lhs, const Poly& rhs);
    friend Poly operator %(const Poly& lhs, const Poly& rhs);

    //IOStream Operators
    friend ostream& operator <<(ostream& outs, const Poly& p);
    friend istream& operator >>(istream& ins, Poly& p);

    //Error functions
    bool error() const; //returns if the polynomial is undefined (1) or not 
                        //(0).
    string errorDescription() const; //returns a description of the error.
    void clear(); //clears all errors and resets the object.

    //NOTE: There is no function "checkError" because the only error
    //that occurs is dividing by 0, which must be checked within the / 
    //operator.

private:

    void fixOrder();
    bool _error;
    SortedList<Term> _polynomial;

};

#endif // !POLY_H

