#ifndef STACK_TEST_FUNCTIONS_H
#define STACK_TEST_FUNCTIONS_H

#include <random>
#include <ctime>
#include <iostream>
#include "Stack.h"

Stack<int> getAscendingStack();

Stack<int> getDecendingStack();

Stack<int> getRandomStack();

void testStackCopyConstructor();

void testStackAssignmentOperator();

void testStackDeallocate();

void testStackPush();

void testStackPop();

void testStackTop();

void testStackEmpty();

void testStackOutput();

void testStackIterator();

#endif // !STACK_TEST_FUNCTIONS_H
