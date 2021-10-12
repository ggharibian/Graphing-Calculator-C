#ifndef MCOUNTER_H
#define MCOUNTER_H
#include "MCounter.cpp"

class MCounter
{
private:
    int _count;
    bool _error;
public:
    //Constructor
    MCounter();

    //Mutator Functions
    int add_1();
    int add_10();
    int add_100();
    int add_1000();

    //Accessor Function
    int count() const;

    //Error Functions
    int reset();    //Resets the count and error variables
    bool error();   //Prints the value of Error
    bool is_error() const; //Returns whether there is an error or not.
};

#endif // !MCOUNTER_H



