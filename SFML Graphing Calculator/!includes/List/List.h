#ifndef LIST_H
#define LIST_H

#include "../Node/Linked_List_Functions.h"

template<typename T>
class List {
public:

	//Note: The Iterator class is used as a traversal method for the user of 
	//the List object. Functionality is the same to that of a pointer.

	class Iterator {
	public:
		friend class List;

		Iterator(Node<T>* ptr = nullptr): _ptr(ptr){}

		Iterator Next() {	//Gets the next location in the list
			return Iterator(_ptr->_next);
		}

		T& operator *() {	//Gets the object at the location of this 
							//Iterator.
			assert(_ptr);
			return _ptr->_obj;
		}

		const T operator *() const{
			assert(_ptr);
			return _ptr->_obj;
		}

		T* operator ->() {	//Accesses the elements of the Object at
							//this Iterator.
			assert(_ptr);
			return _ptr->_obj;
		}

		const T* operator ->() const{
			assert(_ptr);
			return _ptr->_obj;
		}

		friend Iterator operator ++(Iterator& it, int unused) {
			//prefix

			Iterator old;
					//Holds the old value of the iterator so that I can be
					//returned at the end.

			old = it;
			it = it.Next();
			return old;
		}

		Iterator& operator ++() {
			//postfix

			_ptr = _ptr->_next;
			return *this;
		}

		friend bool operator ==(const Iterator& left, const Iterator& right) {
			return left._ptr == right._ptr;
		}

		friend bool operator !=(const Iterator& left, const Iterator& right) {
			return left._ptr != right._ptr;
		}

	private:
		Node<T>* _ptr; //Traces a Node location in a List object.
	};

	//Constructor
	List();

	//Big Three Functions
	~List();
	List(const List<T>& copyThis);
	List<T>& operator =(const List<T>& rhs);

	//Insertion Functions
	List<T>::Iterator InsertHead(T item);

	List<T>::Iterator InsertAfter(T item, List<T>::Iterator location);

	List<T>::Iterator InsertBefore(T item, List<T>::Iterator location);

	List<T>::Iterator InsertSorted(T item);

	//Delete Function
	T Delete(List<T>::Iterator location);

	//Print Function
	void Print() const;

	//Search Function
	List<T>::Iterator Search(const T key);

	//Traversal Functions
	List<T>::Iterator Next(List<T>::Iterator location) const;
	List<T>::Iterator Prev(List<T>::Iterator location) const;

	//Bracket Access Operator
	T& operator [](int index);

	//Accessor Functions
	List<T>::Iterator Begin() const;
	List<T>::Iterator End() const;
	List<T>::Iterator lastValue() const;
	bool Empty();

	//Output Operator
	template<typename U>
	friend ostream& operator <<(ostream& outs, const List<U>& l);

	//Equality Operator
	template<typename U>
	friend bool operator ==(const List<U>& lhs, const List<U>& rhs);

private:

	//The head of the linked list.
	Node<T>* _head;


};

	//Note: Check the "Linked_List_Functions.h" file for documentation for 
	//further info helper functions.

//------------------------------------------
//Constructor:
//------------------------------------------

template<typename T>
List<T>::List(): _head(nullptr)
{
	//Intentionally Blank.
}

//------------------------------------------
//Big Three Functions
//------------------------------------------

template<typename T>
List<T>::~List()
{	//Deallocates the list using the clearList() function.

	clearList(_head);
}

template<typename T>
List<T>::List(const List<T>& copyThis)
{	//Copies the list using thr copyList() function.

	_head = copyList(copyThis._head);
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{

	if (this->_head == rhs._head)
		return *this;
			//Checking for self reference.

	clearList(_head);
			//Deletes old list

	_head = copyList(rhs._head);
			//Creates a new copy of the list.

	return *this;

}

//------------------------------------------
//Insertion Functions:
//------------------------------------------

template<typename T>
typename List<T>::Iterator List<T>::InsertHead(T item)
{
	return Iterator(insertHead(_head, item));
			//Inserts the item at the start of the list.
}

template<typename T>
typename List<T>::Iterator List<T>::InsertAfter(T item, List<T>::Iterator location)
{
	return Iterator(insertAfter(_head, location._ptr, item));
			//Inserts the item after location in the list.
}

template<typename T>
typename List<T>::Iterator List<T>::InsertBefore(T item, List<T>::Iterator location)
{
	return Iterator(insertBefore(_head, location._ptr, item));
			//Inserts the item before location in the list.
}

template<typename T>
typename List<T>::Iterator List<T>::InsertSorted(T item)
{
	return Iterator(insertSorted(_head, item, true));
			//Inserts an item into a sorted list.
			//List must be sorted to work.
}

//------------------------------------------
//Delete Function:
//------------------------------------------

template<typename T>
T List<T>::Delete(List<T>::Iterator location)
{
	return deleteNode(_head, location._ptr);
			//Deletes the node at location from the list.
}

//------------------------------------------
//Print Function:
//------------------------------------------

template<typename T>
void List<T>::Print() const
{
	print(_head);
			//Prints the list to the console.
}

//------------------------------------------
//Search Function:
//------------------------------------------

template<typename T>
typename List<T>::Iterator List<T>::Search(const T key)
{
	return Iterator(searchList(_head, key));
			//Returns the location of key in list.
}

//------------------------------------------
//Traversal Functions:
//------------------------------------------

template<typename T>
typename List<T>::Iterator List<T>::Next(List<T>::Iterator location) const{
	return Iterator(nextNode(_head, location._ptr));
			//Gets the next node. Asserts if location is not in the list.
}

template<typename T>
typename List<T>::Iterator List<T>::Prev(List<T>::Iterator location) const
{
	return Iterator(previousNode(_head, location._ptr));
			//Gets the previous node. Asserts if location is not in the list.
}

//------------------------------------------
//Bracket Access Operator:
//------------------------------------------

template<typename T>
T& List<T>::operator[](int index)
{
	return at(_head, index);
			//Gets value at index. Asserts if out of bounds.
}

//------------------------------------------
//Accessor Functions:
//------------------------------------------

template<typename T>
typename List<T>::Iterator List<T>::Begin() const
{
	return Iterator(_head);
}

template<typename T>
typename List<T>::Iterator List<T>::End() const
{
	return Iterator(nullptr);
}

template<typename T>
typename List<T>::Iterator List<T>::lastValue() const
{
	return Iterator(lastNode(_head));
}

template<typename T>
bool List<T>::Empty()
{
	return _head == nullptr;
}

//------------------------------------------
//Output Operator:
//------------------------------------------

template<typename U>
ostream& operator<<(ostream& outs, const List<U>& l)
{
	print(l._head, outs);
			//Prints the list to the console.
	return outs;
}

//------------------------------------------
//Comparison Operator:
//------------------------------------------

template<typename U>
bool operator==(const List<U>& lhs, const List<U>& rhs)
{
	return lhs._head == rhs._head;
}

#endif // !LIST_H