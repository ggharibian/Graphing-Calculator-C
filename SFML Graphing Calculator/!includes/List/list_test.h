#ifndef LIST_TEST_H
#define LIST_TEST_H

#include <random>
#include <ctime>
#include <iostream>
#include "List.h"

List<int> getAscendingList();

List<int> getDecendingList();

List<int> getRandomList();

void testInsertHead();

void testInsertAfter();

void testInsertBefore();

void testNext();

void testPrev();

void testDelete();

void testOutput();

void testSearch();

void testAssignmentOperator();

void testDeallocate();

void testBracketOperator();

void testInsertSorted();

void testBegin();

void testEnd();

void testEmpty();

void testIterator();

#endif // !LIST_TEST_H
