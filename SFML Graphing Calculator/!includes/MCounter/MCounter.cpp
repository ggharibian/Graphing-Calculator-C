#include "MCounter.h"
using namespace std;

MCounter::MCounter()
{
	_count = 0;
	_error = false;
}

int MCounter::add_1()
{
	_count++;
	_error = is_error();
	return _count;
}

int MCounter::add_10()
{
	_count += 10;
	_error = is_error();
	return _count;
}

int MCounter::add_100()
{
	_count += 100;
	_error = is_error();
	return _count;
}

int MCounter::add_1000()
{
	_count += 1000;
	_error = is_error();
	return _count;
}

int MCounter::reset()
{
	_count = 0;
	_error = is_error();
	return _count;
}

int MCounter::count() const
{
	return _count;
}

bool MCounter::is_error() const
{
	return _count >= 10000;
}

bool MCounter::error()
{
	return _error;
}