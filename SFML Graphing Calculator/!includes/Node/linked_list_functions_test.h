#ifndef LINKED_LIST_FUNCTIONS_TEST_H
#define LINKED_LIST_FUNCTIONS_TEST_H
#include <iostream>
#include <cmath>
#include <ctime>
#include "Linked_List_Functions.h"

Node<int>* getAscendingList();
							//Returns an ascending linked list.
					//Precondition: None
					//Postcondition: An ascending linked list has been 
					//returned.

Node<int>* getDecendingList();
							//Returns an decending linked list.
					//Precondition: None
					//Postcondition: An decending linked list has been 
					//returned.

Node<int>* getRandomList();
							//Returns an randomized linked list.
					//Precondition: None
					//Postcondition: An randomized linked list has been 
					//returned.

void testSearchList();
							//Tests the searchList() function
					//Precondition: None
					//Postcondition: All test cases for the searchList() 
					//function have been returned.

void testInsertHead();
							//Tests the insertHead() function
					//Precondition: None
					//Postcondition: All test cases for the insertHead() 
					//function have been returned.

void testInsertAfter();
							//Tests the insertAfter() function
					//Precondition: None
					//Postcondition: All test cases for the insertAfter() 
					//function have been returned.

void testInsertBefore();
							//Tests the insertBefore() function
					//Precondition: None
					//Postcondition: All test cases for the insertBefore() 
					//function have been returned.

void testPreviousNode();
							//Tests the previousNode() function
					//Precondition: None
					//Postcondition: All test cases for the previousNode() 
					//function have been returned.

void testNextNode();
							//Tests the nextNode() function
					//Precondition: None
					//Postcondition: All test cases for the nextNode() 
					//function have been returned.

void testDeleteNode();
							//Tests the deleteNode() function
					//Precondition: None
					//Postcondition: All test cases for the deleteNode() 
					//function have been returned.

void testCopyList();
							//Tests the copyList() function
					//Precondition: None
					//Postcondition: All test cases for the copyList() 
					//function have been returned.

void testClearList();
							//Tests the clearList() function
					//Precondition: None
					//Postcondition: All test cases for the clearList() 
					//function have been returned.

void testAt();
							//Tests the at() function
					//Precondition: None
					//Postcondition: All test cases for the at() 
					//function have been returned.

void testInsertSorted();
							//Tests the insertSorted() function
					//Precondition: None
					//Postcondition: All test cases for the insertSorted() 
					//function have been returned.

void testWhereThisGoes();
							//Tests the whereThisGoes() function
					//Precondition: None
					//Postcondition: All test cases for the searchList() 
					//function have been returned.

void testLastNode();
							//Tests the lastNode() function
					//Precondition: None
					//Postcondition: All test cases for the lastNode() 
					//function have been returned.

#endif // !LINKED_LIST_FUNCTIONS_TEST_H
