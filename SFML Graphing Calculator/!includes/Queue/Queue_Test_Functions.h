#ifndef QUEUE_TEST_FUNCTIONS_H
#define QUEUE_TEST_FUNCTIONS_H

#include <random>
#include <ctime>
#include <iostream>
#include "Queue.h"

Queue<int> getAscendingQueue();

Queue<int> getDecendingQueue();

Queue<int> getRandomQueue();

void testQueueCopyConstructor();

void testQueueAssignmentOperator();

void testQueueDeallocate();

void testQueuePush();

void testQueuePop();

void testQueueFront();

void testQueueEmpty();

void testQueueOutput();

void testQueueIterator();

#endif // !QUEUE_TEST_FUNCTIONS_H
