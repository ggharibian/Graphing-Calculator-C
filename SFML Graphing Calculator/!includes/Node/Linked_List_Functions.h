#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <cassert>
#include "../Node/Node.h"

template<typename T>
ostream& print(Node<T>* head, ostream& outs = cout);
							//Prints the linked list.
					//Precondition: head has been created.
					//Postcondition: The list has been printed.

//HELPER FUNCTION
template<typename T>
ostream& printRecursive(Node<T>* head, ostream& outs = cout);
							//Prints the linked list Recursively
					//Precondition: head has been created.
					//Postcondition: The list has been printed.

template<typename T>
ostream& printBackwards(Node<T>* head, ostream& outs = cout);
							//Prints the linked list backwards
					//Precondition: head has been created.
					//Postcondition: The list has been printed backwards.

//HELPER FUNCTION
template<typename T>
void printBackwardsRecursive(Node<T>* head, ostream& outs = cout);
							//Prints the linked list backwards recursively
					//Precondition: head has been created.
					//Postcondition: The list has been printed backwords

template <typename T>
Node<T>* searchList(Node<T>* head, T key);
							//Searches the link list for the key and returns
							//the pointer location to the first occurence of
							//the key.
					//Precondition: head has been created.
					//Postcondition: The first occurence of the key is
					//returned.

template<typename T>
Node<T>* insertHead(Node<T>*& head_ptr, const T& item);
							//Inserts a value at the head of the linked list
					//Precondition: head has been created.
					//Postcondition: head of the list has been reassigned.

template <typename T>
Node<T>* insertAfter(Node<T>*& head,        //insert after ptr
    Node<T>* afterThis,
    T insertThis);
							//inserts a node after the node "afterThis" in the
							//linked list.
					//Precondition: head has been created.
					//Postcondition: The node has been inserted into the list.

template <typename T>
Node<T>* insertBefore(Node<T>*& head,       //insert before ptr
    Node<T>* beforeThis,
    T insertThis);
							//inserts a node before the "beforeThis" Node
					//Precondition: head has been created.
					//Postcondition: The node has been inserted into the list.

template <typename T>
Node<T>* nextNode(Node<T>* head,        //ptr to previous Node
    Node<T>* afterThis);
							//Accesses the next Node to "afterThis"
					//Precondition: head has been created.
					//Postcondition: The next Node of "afterThis" has
					//been returned

template <typename T>
Node<T>* previousNode(Node<T>* head,        //ptr to previous Node
    Node<T>* prevToThis);
							//Accesses the previous Node to "prevToThis"
					//Precondition: head has been created.
					//Postcondition: The previous Node of "prevToThis" has
					//been returned

template <typename T>
T deleteNode(Node<T>*& head,                 //delete, return item
    Node<T>* deleteThis);
							//deletes the node designated by "deleteThis".
							//and returns it's contents.
					//Precondition: head has been created.
					//Postcondition: The node "deleteThis" has been removed 
					//from the list and the value has been returned.

template <typename T>
Node<T>* copyList(Node<T>* head);           //duplicate the list...
							//Copies the linked list designated by "head".
					//Precondition: head has been created.
					//Postcondition: The duplicate linked list has been 
					//returned.

template <typename T>
void clearList(Node<T>*& head);                     //delete all the Nodes
							//Deletes all the nodes from the list designated
							//by head.
					//Precondition: head has been created.
					//Postcondition: All nodes in head have been deleted.

template <typename T>
T& at(Node<T>* head, int pos);              //_item at this position
							//Gets the item at the position "pos" in a list
					//Precondition: head has been created.
					//				0 <= pos < len(head)
					//Postcondition: The item at "pos" has been returned.

template <typename T>
Node<T>* insertSorted(Node<T>*& head,       //insert
    T item,
    bool ascending = true);
							//Inserts the item into a sorted list.
					//Precondition: head has been created.
					//Postcondition: The item has been inserted into the list.

template <typename T>
Node<T>* insertSortedAndAdd(Node<T>*& head, //insert or add if a dup
    T item,
    bool ascending = true);

template <typename T>
Node<T>* whereThisGoes(Node<T>* head,         //Node after which this
    T item,                //    item goes
    bool ascending = true);          //order: 0 ascending
							//returns the node after which the item must be
							//placed.
					//Precondition: head has been created.
					//Postcondition: The node after which item must be 
					//inserted is returned.

template <typename T>
Node<T>* lastNode(Node<T>* head);            //Last Node in the list
							//Returns the last node in the list.
					//Precondition: head has been created.
					//Postcondition: The last node has been returned.


//===========================

template<typename T>
ostream& print(Node<T>* head, ostream& outs)
{
	outs << "H->";
	return printRecursive(head, outs);
			//Prints all the nodes in head followed by a "|||"
}

template<typename T>
ostream& printRecursive(Node<T>* head, ostream& outs)
{
	if (head == nullptr) {
				//Base case: The end of the list

		outs << "|||";
		return outs;
	}

	outs << *head;

	return printRecursive(head->_next, outs);
			//Will iterate over the entire list.
}

template<typename T>
ostream& printBackwards(Node<T>* head, ostream& outs)
{
	cout << "T->";

	printBackwardsRecursive(head, outs);
			//Prints all the Nodes in head
	outs << "|||";
	return outs;
}

template<typename T>
void printBackwardsRecursive(Node<T>* head, ostream& outs)
{
	if (head != nullptr) {
				//No Base case, just recursive condition

		printBackwardsRecursive(head->_next, outs);
		outs << *head;
	}
	
}

template<typename T>
Node<T>* searchList(Node<T>* head, T key)
{
	if (head == nullptr) {
			//Base Case 1

		return nullptr;
				//If the key doesn't exist in the list.
	}

	if (head->_obj == key){
			//Base case 2

		return head;
				//Returns the location of the item.
	}

	return searchList(head->_next, key);
			//Recursive Statement
}

template<typename T>
Node<T>* insertHead(Node<T>*& head_ptr, const T& item)
{
	//1: create a new Node:
	Node<T>* temp = new Node<T>(item);
	//2. point (the next field of) this new Node to where head is pointing to
	temp->_next = head_ptr;

	//3. point head to this new Node:
	head_ptr = temp;

	return head_ptr;
}

template<typename T>
Node<T>* insertAfter(Node<T>*& head, Node<T>* afterThis, T insertThis)
{
	Node<T>* next = nextNode(head, afterThis);
			//Finds the next node in the list. Asserts if not there.

	afterThis->_next = new Node<T>(insertThis, next);
			//The node is added to the list.

	return afterThis->_next;
}

template<typename T>
Node<T>* insertBefore(Node<T>*& head, Node<T>* beforeThis, T insertThis)
{
	Node<T>* prev = previousNode(head, beforeThis);
			//Finds the previous node in the list. Asserts if not there.

	if (prev == nullptr)
				//Checks if beforeThis is the head of the list.
		return insertHead(head, insertThis);

	prev->_next = new Node<T>(insertThis, prev->_next);
			//The node is added into the list.

	return prev->_next;
}

template<typename T>
Node<T>* nextNode(Node<T>* head, Node<T>* afterThis)
{
	assert(head != nullptr);
			//Asserts if list is empty or afterThis is not in the list.

	if (head == afterThis)
		return head->_next;
			//Base Case: Found afterThis

	return nextNode(head->_next, afterThis);
			//Recursive call.
}

template<typename T>
Node<T>* previousNode(Node<T>* head, Node<T>* prevToThis)
{
	assert(head != nullptr);
			//Asserts if list is empty or afterThis is not in the list.

	if (head == prevToThis)
		return nullptr;
			//Returns nullptr if prevToThis is the head.

	if (head->_next == prevToThis)
		return head;
			//Base Case


	return previousNode(head->_next, prevToThis);
			//Recursive Statement
}

template<typename T>
T deleteNode(Node<T>*& head, Node<T>* deleteThis)
{
	Node<T>* prev = previousNode(head, deleteThis);
			//Accesses previous value. Asserts if deleteThis is not in the 
			//list.

	T value;
			//Value of the delete item.

	assert(deleteThis != nullptr);
			//asserts if deleteThis is nullptr.

	if (deleteThis == head) 
		head = head->_next;
			//Reassigns the head to the next value.
	else 
		prev->_next = deleteThis->_next;
		
	value = deleteThis->_obj;

	delete deleteThis;
			//The node is removed from the array.

	return value;
}

template<typename T>
Node<T>* copyList(Node<T>* head)
{
	if (head == nullptr)
		return nullptr;
			//Base Case

	return new Node<T>(head->_obj, copyList(head->_next));
			//Recursive Statement
}

template<typename T>
void clearList(Node<T>*& head)
{
	if (head != nullptr) {
			//No Base Case, just conditional statement
			//Will run until the list has no values.

		deleteNode(head, head);

		clearList(head);
			//Recursive Statemenet
	}
}

template<typename T>
T& at(Node<T>* head, int pos)
{
	if (pos == 0)
		return head->_obj;
			//Base Case: Item has been found

	return at(head->_next, --pos);
			//Recursive Statement

}

template<typename T>
Node<T>* insertSorted(Node<T>*& head, T item, bool ascending){
	Node<T>* loc = whereThisGoes(head, item, ascending);
			//Finds the location where the value must be inserted after.

	if (loc == nullptr)
		return insertHead(head, item);
			//If the value must be inserted at the head.
	else
		return insertAfter(head, loc, item);
}


//NOTE: The next function is not required (yet).
template<typename T>
Node<T>* insertSortedAndAdd(Node<T>*& head, T item, bool ascending)
{

	Node<T>* loc = whereThisGoes(head, item, ascending);


	if (head == nullptr) {
		return insertHead(head, item);
	}
	else
	if (loc == nullptr) {
		if (head->_obj == item) {
			head->_obj += item;
			return head;
		}
		else
			return insertHead(head, item);
	}
	else
	if (loc->_next != nullptr && loc->_next->_obj == item) {
		loc->_next->_obj += item;
		return loc->_next;
	}
	else
	return insertAfter(head, loc, item);
}

template<typename T>
Node<T>* whereThisGoes(Node<T>* head, T item, bool ascending)
{
	if (head == nullptr || ascending && head->_obj >= item
		|| !ascending && head->_obj <= item)
		return nullptr;

	if (head->_next == nullptr || ascending && head->_next->_obj >= item 
		|| !ascending && head->_next->_obj <= item)
			//Checks to see if weve reached the value we're looking for to
			//place before
		return head;
			//Base case 2: Found location

		return whereThisGoes(head->_next, item, ascending);
				//Recursive Statement
}

template<typename T>
Node<T>* lastNode(Node<T>* head)
{
	if (head == nullptr || head->_next == nullptr)
		return head;
			//Base Case

	return lastNode(head->_next);
			//Recursive Statement
}

#endif // !LINKED_LIST_FUNCTIONS_H